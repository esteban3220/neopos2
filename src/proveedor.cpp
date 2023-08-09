#pragma once

#include "Pos.hpp"
#include "producto.cpp"
#include "point.cpp"
#include "columns.hpp"
#include "venta.cpp"
#include "config.cpp"
#include <string>

Pos::Pos(const Glib::RefPtr<Gtk::Application>& app)
{
    cargar_glade();
    if (!db->open())
    {
        std::cout << "Error al abrir la base de datos" << std::endl;
        return;
    }
    set_title("POS");
    set_default_size(800, 600);
    set_titlebar(header_bar);
    header_bar.pack_start(menu_button);
    header_bar.set_title_widget(stack_switcher);
    init();
    init_producto();
    carga_señales();
    llena_subca();
    ety_barras->set_completion(completion_pos);
    completion_pos->set_model(m_refTreeModel_prod);
    completion_pos->set_text_column(m_Columns_prod.nombre);
    ety_articulo_popover.set_completion(completion_producto);
    completion_producto->set_model(m_refTreeModel_prod);
    completion_producto->set_text_column(m_Columns_prod.nombre);
    spin_ingreso->set_adjustment(Gtk::Adjustment::create(0.0, 0.0, 100000.0, 1.0, 10.0, 0.0));
    spin_cantidad_articulo_popover.set_adjustment(Gtk::Adjustment::create(0.0, 0.0, 100000.0, 1.0, 10.0, 0.0));
    refGesture->set_button(GDK_BUTTON_SECONDARY);
    init_venta();
    init_popover_articulo();
    init_reporte();
    init_detalle_venta();
    init_config_ticket();

    auto refActionGroup = Gio::SimpleActionGroup::create();
    auto gmenu = Gio::Menu::create();
    auto submenu = Gio::Menu::create();

    gmenu->append_submenu("Configuracion",submenu);
    submenu->append("_Imprimir","popupmain.config.imprimir");
    submenu->append("_Conf. Ticket","popupmain.config.ticket");
    
    gmenu->append("_Salir", "app.quit");

    impresion_act = refActionGroup->add_action_bool("config.imprimir",[=](){
        bool activo = false;
        if(  impresion_act->get_state(activo); activo) 
        impresion_act->change_state(false);
        else
         impresion_act->change_state(true);

        db->command("UPDATE conf SET v7 = "+ std::to_string(!activo) );
        });

    db->command ("SELECT * FROM conf");
    impresion_act->change_state((bool) std::stoi(db->get_result()[0][6]));
    result.clear ();

    refActionGroup->add_action("config.ticket",[=](){window_conf_ticket->show();});
    insert_action_group("popupmain", refActionGroup);
    m_MenuPopup_main.set_menu_model(gmenu);

    app->set_accel_for_action("app.quit", "<Ctrl>Q");
    app->set_accel_for_action("popupmain.config.imprimir", "<Ctrl>I");
    
    menu_button.set_popover(m_MenuPopup_main);
}

void Pos::cargar_glade()
{
    box_pos = builder->m_refBuilder->get_widget<Gtk::Box>("box_pos");
    stack_main_pos = builder->m_refBuilder->get_widget<Gtk::Stack>("stack_main_pos");
    auto stack_debug = builder->m_refBuilder->get_widget<Gtk::StackSwitcher>("stack_debug");
    tree_prov = builder->m_refBuilder->get_widget<Gtk::TreeView>("tree_prov");
    tree_prod = builder->m_refBuilder->get_widget<Gtk::TreeView>("tree_prod");
    tree_venta = builder->m_refBuilder->get_widget<Gtk::TreeView>("tree_venta");
    lbl_cont_prod = builder->m_refBuilder->get_widget<Gtk::Label>("lbl_cont_prod");
    lbl_con_prov = builder->m_refBuilder->get_widget<Gtk::Label>("lbl_con_prov");
    btn_add_prov = builder->m_refBuilder->get_widget<Gtk::Button>("btn_add_prov");
    btn_remove_prov = builder->m_refBuilder->get_widget<Gtk::Button>("btn_remove_prov");
    btn_add_produ = builder->m_refBuilder->get_widget<Gtk::Button>("btn_add_produ");
    btn_remove_produ = builder->m_refBuilder->get_widget<Gtk::Button>("btn_remove_produ");
    lbl_precio_total = builder->m_refBuilder->get_widget<Gtk::Label>("lbl_precio_total");
    ety_barras = builder->m_refBuilder->get_widget<Gtk::Entry>("ety_barras");
    spin_ingreso = builder->m_refBuilder->get_widget<Gtk::SpinButton>("spin_ingreso");
    lbl_cambio = builder->m_refBuilder->get_widget<Gtk::Label>("lbl_cambio");
    btn_pago_efectivo = builder->m_refBuilder->get_widget<Gtk::Button>("btn_pago_efectivo");
    btn_pago_tarjeta = builder->m_refBuilder->get_widget<Gtk::Button>("btn_pago_tarjeta");
    btn_add_piezas = builder->m_refBuilder->get_widget<Gtk::Button>("btn_add_piezas");
    tree_repor = builder->m_refBuilder->get_widget<Gtk::TreeView>("tree_repor");
    tree_detalle_venta = builder->m_refBuilder->get_widget<Gtk::TreeView>("tree_detalle_venta");

    lbl_precio_total->set_markup("$<span font_desc='50'>0.00</span>");
    stack_switcher.set_stack(*stack_main_pos);
    stack_switcher.set_child_visible(true);
    stack_main_pos->set_transition_type(Gtk::StackTransitionType::SLIDE_LEFT_RIGHT);

    stack_debug->hide();
    set_child(*box_pos);
}

void Pos::carga_señales()
{
    auto controller = Gtk::EventControllerKey::create();

    btn_add_prov->signal_clicked().connect(sigc::mem_fun(*this, &Pos::on_btn_add_clicked));
    btn_remove_prov->signal_clicked().connect(sigc::mem_fun(*this, &Pos::on_btn_remove_clicked));
    cell1->signal_edited().connect(sigc::mem_fun(*this, &Pos::on_cell1_edited));
    cell2->signal_edited().connect(sigc::mem_fun(*this, &Pos::on_cell2_edited));
    cell3->signal_edited().connect(sigc::mem_fun(*this, &Pos::on_cell3_edited));
    cell4->signal_edited().connect(sigc::mem_fun(*this, &Pos::on_cell4_edited));
    ety_barras->signal_activate().connect(sigc::mem_fun(*this, &Pos::add_articulo_venta));
    completion_pos->signal_match_selected().connect(sigc::mem_fun(*this, &Pos::add_match_arcticulo), false);
    completion_producto->signal_match_selected().connect(sigc::mem_fun(*this, &Pos::add_match_producto), false);
    spin_ingreso->signal_changed().connect(sigc::mem_fun(*this, &Pos::on_spin_ingreso_changed));
    controller->signal_key_pressed().connect(sigc::mem_fun(*this, &Pos::on_spin_ingreso_activate), false);
    btn_pago_efectivo->signal_clicked().connect(sigc::mem_fun(*this, &Pos::cierra_venta));
    btn_pago_tarjeta->signal_clicked().connect(sigc::mem_fun(*this, &Pos::on_btn_pago_tarjeta_clicked));
    btn_remove_produ->signal_clicked().connect(sigc::mem_fun(*this, &Pos::on_btn_remove_prod_clicked));
    btn_add_piezas->signal_clicked().connect([this]()
                                             { popover_ingreso_articulos.popup(); });
    ety_articulo_popover.signal_activate().connect(sigc::mem_fun(*this, &Pos::add_articulo_venta_popover));
    btn_add_articulo_popover.signal_clicked().connect(sigc::mem_fun(*this, &Pos::add_btn_articulo_venta_popover));
    tree_repor->signal_row_activated().connect(sigc::mem_fun(*this, &Pos::on_tree_detalle_venta_row_activated));
    refGesture->signal_pressed().connect(sigc::mem_fun(*this, &Pos::on_popup_button_pressed));

    add_controller(controller);
    add_controller(refGesture);

    auto gmenu = Gio::Menu::create();
    gmenu->append("_Cancela Venta.", "popup.remove");
    auto refActionGroup = Gio::SimpleActionGroup::create();

    refActionGroup->add_action("remove",sigc::mem_fun(*this, &Pos::on_menu_file_popup_generic));
    insert_action_group("popup", refActionGroup);

    m_MenuPopup.set_parent(*tree_repor);
    m_MenuPopup.set_menu_model(gmenu);
    m_MenuPopup.set_has_arrow(false);

    btn_add_produ->signal_clicked().connect([this]()
                                            {row_producto = *(m_refTreeModel_prod->append()); lbl_cont_prod->set_text("Productos: " + std::to_string(++cont_prod)); });
    cell_sku->signal_edited().connect([this](const Glib::ustring &path_string, const Glib::ustring &new_text)
                                      {dialog.reset(new Gtk::MessageDialog(*this, "Editar", false, Gtk::MessageType::QUESTION, Gtk::ButtonsType::OK_CANCEL, true));
                                        dialog->set_secondary_text("¿Desea editar el campo?");
                                        dialog->signal_response().connect(sigc::bind(sigc::mem_fun(*this, &Pos::on_produ_dialog_edit_response),  path_string, new_text, COLUMNS::ColumnProducto::SKU));
                                        dialog->set_default_response(Gtk::ResponseType::OK);
                                        dialog->show(); });

    cell_nombre->signal_edited().connect([this](const Glib::ustring &path_string, const Glib::ustring &new_text)
                                         {dialog.reset(new Gtk::MessageDialog(*this, "Editar", false, Gtk::MessageType::QUESTION, Gtk::ButtonsType::OK_CANCEL, true));
                                           dialog->set_secondary_text("¿Desea editar el campo?");
                                           dialog->signal_response().connect(sigc::bind(sigc::mem_fun(*this, &Pos::on_produ_dialog_edit_response),  path_string, new_text, COLUMNS::ColumnProducto::NOMBRE_PRODUCTO));
                                           dialog->set_default_response(Gtk::ResponseType::OK);
                                           dialog->show(); });

    cell_caducidad->signal_edited().connect([this](const Glib::ustring &path_string, const Glib::ustring &new_text)
                                            {dialog.reset(new Gtk::MessageDialog(*this, "Editar", false, Gtk::MessageType::QUESTION, Gtk::ButtonsType::OK_CANCEL, true));
                                                dialog->set_secondary_text("¿Desea editar el campo?\nEl formato de la fecha es: aaaa-mm-dd");
                                                dialog->signal_response().connect(sigc::bind(sigc::mem_fun(*this, &Pos::on_produ_dialog_edit_response),  path_string, new_text, COLUMNS::ColumnProducto::CADUCIDAD));
                                                dialog->set_default_response(Gtk::ResponseType::OK);
                                                dialog->show(); });

    cell_marca->signal_changed().connect([this](const Glib::ustring &path_string, const Gtk::TreeModel::iterator &val)
                                         {dialog.reset(new Gtk::MessageDialog(*this, "Editar", false, Gtk::MessageType::QUESTION, Gtk::ButtonsType::OK_CANCEL, true));
                                            dialog->set_secondary_text("¿Desea editar el campo?");
                                            dialog->signal_response().connect(sigc::bind(sigc::mem_fun(*this, &Pos::on_cell_marca_changed),  path_string, val));
                                            dialog->set_default_response(Gtk::ResponseType::OK);
                                            dialog->show(); });

    cell_nota->signal_edited().connect([this](const Glib::ustring &path_string, const Glib::ustring &new_text)
                                       {dialog.reset(new Gtk::MessageDialog(*this, "Editar", false, Gtk::MessageType::QUESTION, Gtk::ButtonsType::OK_CANCEL, true));
                                        dialog->set_secondary_text("¿Desea editar el campo?");
                                        dialog->signal_response().connect(sigc::bind(sigc::mem_fun(*this, &Pos::on_produ_dialog_edit_response),  path_string, new_text, COLUMNS::ColumnProducto::NOTA));
                                        dialog->set_default_response(Gtk::ResponseType::OK);
                                        dialog->show(); });

    cell_piezas->signal_edited().connect([this](const Glib::ustring &path_string, const Glib::ustring &new_text)
                                         {dialog.reset(new Gtk::MessageDialog(*this, "Editar", false, Gtk::MessageType::QUESTION, Gtk::ButtonsType::OK_CANCEL, true));
                                            dialog->set_secondary_text("¿Desea editar el campo?");
                                            dialog->signal_response().connect(sigc::bind(sigc::mem_fun(*this, &Pos::on_produ_dialog_edit_response),path_string, new_text, COLUMNS::ColumnProducto::PIEZAS));
                                            dialog->set_default_response(Gtk::ResponseType::OK);
                                            dialog->show(); });

    cell_precio_u->signal_edited().connect([this](const Glib::ustring &path_string, const Glib::ustring &new_text)
                                           {dialog.reset(new Gtk::MessageDialog(*this, "Editar", false, Gtk::MessageType::QUESTION, Gtk::ButtonsType::OK_CANCEL, true));
                                                dialog->set_secondary_text("¿Desea editar el campo?");
                                                dialog->signal_response().connect(sigc::bind(sigc::mem_fun(*this, &Pos::on_produ_dialog_edit_response),path_string, new_text, COLUMNS::ColumnProducto::PRECIO_U));
                                                dialog->set_default_response(Gtk::ResponseType::OK);
                                                dialog->show(); });

    cell_categoria->signal_changed().connect([this](const Glib::ustring &path_string, const Gtk::TreeModel::iterator &val)
                                             {dialog.reset(new Gtk::MessageDialog(*this, "Editar", false, Gtk::MessageType::QUESTION, Gtk::ButtonsType::OK_CANCEL, true));
                                                dialog->set_secondary_text("¿Desea editar el campo?");
                                                dialog->signal_response().connect(sigc::bind(sigc::mem_fun(*this, &Pos::on_cell_categoria_changed),  path_string, val));
                                                dialog->set_default_response(Gtk::ResponseType::OK);
                                                dialog->show(); });

    cell_subcategoria->signal_changed().connect([this](const Glib::ustring &path_string, const Gtk::TreeModel::iterator &val)
                                                {dialog.reset(new Gtk::MessageDialog(*this, "Editar", false, Gtk::MessageType::QUESTION, Gtk::ButtonsType::OK_CANCEL, true));
                                                    dialog->set_secondary_text("¿Desea editar el campo?");
                                                    dialog->signal_response().connect(sigc::bind(sigc::mem_fun(*this, &Pos::on_cell_subcategoria_changed),  path_string, val));
                                                    dialog->set_default_response(Gtk::ResponseType::OK);
                                                    dialog->show(); });
}

void Pos::init()
{
    m_refTreeModel = Gtk::ListStore::create(m_Columns);
    tree_prov->set_model(m_refTreeModel);

    int id = 0;

    tree_prov->append_column_numeric("ID", m_Columns.id, "%03d");

    id = tree_prov->append_column(*Gtk::manage(new Gtk::TreeViewColumn("Nombre")));
    col1 = tree_prov->get_column(id - 1);
    id = tree_prov->append_column(*Gtk::manage(new Gtk::TreeViewColumn("Numero")));
    col2 = tree_prov->get_column(id - 1);
    id = tree_prov->append_column(*Gtk::manage(new Gtk::TreeViewColumn("Empresa")));
    col3 = tree_prov->get_column(id - 1);
    id = tree_prov->append_column(*Gtk::manage(new Gtk::TreeViewColumn("Correo")));
    col4 = tree_prov->get_column(id - 1);

    col1->pack_end(*cell1);
    col2->pack_end(*cell2);
    col3->pack_end(*cell3);
    col4->pack_end(*cell4);

    col1->add_attribute(cell1->property_markup(), m_Columns.m_col_name);
    col2->add_attribute(cell2->property_markup(), m_Columns.numero);
    col3->add_attribute(cell3->property_markup(), m_Columns.empresa);
    col4->add_attribute(cell4->property_markup(), m_Columns.correo);

    cell1->property_editable() = true;
    cell2->property_editable() = true;
    cell3->property_editable() = true;
    cell4->property_editable() = true;

    db->command("SELECT * FROM proveedor");
    result = db->get_result();

    m_refTreeModelCombo = Gtk::ListStore::create(m_ColumnsCombo);
    auto iter_ = Gtk::TreeModel::iterator();

    for (int i = 0; i < result.size(); i++)
    {
        row = *(m_refTreeModel->append());
        row[m_Columns.id] = std::stol(result[i][0]);
        row[m_Columns.m_col_name] = result[i][1];
        row[m_Columns.numero] = result[i][2];
        row[m_Columns.empresa] = result[i][3];
        row[m_Columns.correo] = result[i][4];
        iter_ = m_refTreeModelCombo->append();
        (*iter_)[m_ColumnsCombo.m_col_name] = result[i][3];
    }
    result.clear();

    tree_prov->set_search_column(m_Columns.m_col_name);
    tree_prov->set_enable_search(true);
    tree_prov->set_visible(true);

    tree_prov->set_headers_visible(true);

    cont_prov = m_refTreeModel->children().size();

    lbl_con_prov->set_text("Proveedores: " + std::to_string(cont_prov));
}

void Pos::on_cell1_edited(const Glib::ustring &path_string, const Glib::ustring &new_text)
{
    dialog.reset(new Gtk::MessageDialog(*this, "Editar", false, Gtk::MessageType::QUESTION, Gtk::ButtonsType::OK_CANCEL, true));
    dialog->set_secondary_text("¿Desea editar el campo?");
    dialog->signal_response().connect(sigc::bind(sigc::mem_fun(*this, &Pos::on_prov_dialog_edit_response), path_string, new_text, COLUMNS::ColumnProveedor::NOMBRE));
    dialog->set_default_response(Gtk::ResponseType::OK);
    dialog->show();
}

void Pos::on_cell2_edited(const Glib::ustring &path_string, const Glib::ustring &new_text)
{
    dialog.reset(new Gtk::MessageDialog(*this, "Editar", false, Gtk::MessageType::QUESTION, Gtk::ButtonsType::OK_CANCEL, true));
    dialog->set_secondary_text("¿Desea editar el campo?");
    dialog->signal_response().connect(sigc::bind(sigc::mem_fun(*this, &Pos::on_prov_dialog_edit_response), path_string, new_text, COLUMNS::ColumnProveedor::TELEFONO));
    dialog->set_default_response(Gtk::ResponseType::OK);
    dialog->show();
}

void Pos::on_cell3_edited(const Glib::ustring &path_string, const Glib::ustring &new_text)
{
    dialog.reset(new Gtk::MessageDialog(*this, "Editar", false, Gtk::MessageType::QUESTION, Gtk::ButtonsType::OK_CANCEL, true));
    dialog->set_secondary_text("¿Desea editar el campo?");
    dialog->signal_response().connect(sigc::bind(sigc::mem_fun(*this, &Pos::on_prov_dialog_edit_response), path_string, new_text, COLUMNS::ColumnProveedor::EMPRESA));
    dialog->set_default_response(Gtk::ResponseType::OK);
    dialog->show();
}

void Pos::on_cell4_edited(const Glib::ustring &path_string, const Glib::ustring &new_text)
{
    dialog.reset(new Gtk::MessageDialog(*this, "Editar", false, Gtk::MessageType::QUESTION, Gtk::ButtonsType::OK_CANCEL, true));
    dialog->set_secondary_text("¿Desea editar el campo?");
    dialog->signal_response().connect(sigc::bind(sigc::mem_fun(*this, &Pos::on_prov_dialog_edit_response), path_string, new_text, COLUMNS::ColumnProveedor::EMAIL));
    dialog->set_default_response(Gtk::ResponseType::OK);
    dialog->show();
}

void Pos::on_btn_add_clicked()
{
    auto rowid = m_refTreeModel->get_iter(std::to_string(m_refTreeModel->children().size() - 1));
    auto id = (*rowid)[m_Columns.id] + 1;

    try
    {
        db->command("INSERT INTO proveedor (id,nombre, numero, empresa, correo) VALUES (" + std::to_string(id) + ", 'Editame', 0, 'Editame', 'Editame')");
        row = *(m_refTreeModel->append());
        row[m_Columns.id] = id;
        row[m_Columns.m_col_name] = "<i>Editame</i>";
        row[m_Columns.numero] = "<i>Editame</i>";
        row[m_Columns.empresa] = "<i>Editame</i>";
        row[m_Columns.correo] = "<i>Editame</i>";
        auto iter_ = m_refTreeModelCombo->append();
        (*iter_)[m_ColumnsCombo.m_col_name] = "Editame";

        lbl_con_prov->set_text("Proveedores: " + std::to_string(++cont_prov));
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        dialog.reset(new Gtk::MessageDialog(*this, "Error al agregar un Registro", false, Gtk::MessageType::ERROR, Gtk::ButtonsType::OK, true));
        dialog->set_secondary_text(e.what());
        dialog->set_hide_on_close(true);
        dialog->show();
    }
}

void Pos::on_btn_remove_clicked()
{
    dialog.reset(new Gtk::MessageDialog(*this, "Eliminar", true, Gtk::MessageType::QUESTION, Gtk::ButtonsType::CANCEL, true));
    dialog->set_secondary_text("¿Desea eliminar el registro?");
    dialog->property_text().set_value("Eliminar");
    dialog->add_button("Eliminar", Gtk::ResponseType::OK)->set_css_classes({"destructive-action"});
    dialog->signal_response().connect(sigc::mem_fun(*this, &Pos::on_prov_dialog_remove_response));
    dialog->set_default_response(Gtk::ResponseType::OK);
    dialog->show();
}

void Pos::on_prov_dialog_remove_response(int response_id)
{
    switch (response_id)
    {
    case Gtk::ResponseType::OK:
    {
        auto selection = tree_prov->get_selection()->get_selected();
        auto iter_ = m_refTreeModel->get_path(selection);
        if (*selection)
        {
            try
            {
                db->command("DELETE FROM proveedor WHERE id = " + std::to_string((*selection)[m_Columns.id]));
                m_refTreeModel->erase(selection);

                m_refTreeModelCombo->erase(m_refTreeModelCombo->get_iter(iter_.to_string()));

                lbl_con_prov->set_text("Proveedores: " + std::to_string(--cont_prov));
                dialog->close();
            }
            catch (std::exception &e)
            {
                std::cout << e.what() << std::endl;
                dialog.reset(new Gtk::MessageDialog(*this, "Error al eliminar un Registro", false, Gtk::MessageType::ERROR, Gtk::ButtonsType::OK, true));
                dialog->set_secondary_text(e.what());
                dialog->set_hide_on_close(true);
                dialog->show();
            }
        }
        else
        {
            dialog.reset(new Gtk::MessageDialog(*this, "Error al eliminar un Registro", false, Gtk::MessageType::ERROR, Gtk::ButtonsType::OK, true));
            dialog->set_secondary_text("No hay ningun registro seleccionado");
            dialog->set_hide_on_close(true);
            dialog->show();
        }
    }
    break;
    case Gtk::ResponseType::CANCEL:
    {
        dialog->close();
    }
    break;
    }
}

void Pos::on_prov_dialog_edit_response(int response_id, const Glib::ustring &path_string, const Glib::ustring &new_text, const int &column)
{
    switch (response_id)
    {
    case Gtk::ResponseType::OK:
    {
        std::cout << "Path: " << path_string << std::endl;
        auto iter = m_refTreeModel->get_iter(path_string);
        auto iter_ = m_refTreeModelCombo->get_iter(path_string);
        if (iter)
        {
            try
            {
                switch (column)
                {
                case COLUMNS::ColumnProveedor::NOMBRE:
                {
                    db->command("UPDATE proveedor SET nombre = '" + new_text + "' WHERE id = " + std::to_string((*iter)[m_Columns.id]));
                    (*iter)[m_Columns.m_col_name] = new_text;
                }
                break;
                case COLUMNS::ColumnProveedor::TELEFONO:
                {
                    db->command("UPDATE proveedor SET numero = '" + new_text + "' WHERE id = " + std::to_string((*iter)[m_Columns.id]));
                    (*iter)[m_Columns.numero] = new_text.c_str();
                }
                break;
                case COLUMNS::ColumnProveedor::EMPRESA:
                {
                    db->command("UPDATE proveedor SET empresa = '" + new_text + "' WHERE id = " + std::to_string((*iter)[m_Columns.id]));
                    (*iter)[m_Columns.empresa] = new_text;
                    (*iter_)[m_ColumnsCombo.m_col_name] = new_text;
                }
                break;
                case COLUMNS::ColumnProveedor::EMAIL:
                {
                    db->command("UPDATE proveedor SET correo = '" + new_text + "' WHERE id = " + std::to_string((*iter)[m_Columns.id]));
                    (*iter)[m_Columns.correo] = new_text;
                }
                break;
                }
            }
            catch (std::exception &e)
            {
                std::cout << e.what() << std::endl;
                dialog.reset(new Gtk::MessageDialog(*this, "Error al editar un Registro", false, Gtk::MessageType::ERROR, Gtk::ButtonsType::OK, true));
                dialog->set_secondary_text(e.what());
                dialog->set_hide_on_close(true);
                dialog->signal_response().connect([&](int response_id)
                                                  { dialog->close(); });
                dialog->show();
            }
        }
        dialog->hide();
    }
    break;
    case Gtk::ResponseType::CANCEL:
        dialog->hide();
        break;
    default:
        dialog->hide();
        break;
    }
}