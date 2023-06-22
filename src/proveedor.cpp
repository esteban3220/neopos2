#include "Pos.hpp"
#include "columns.hpp"


Pos::Pos()
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
    carga_señales();
}

void Pos::cargar_glade()
{
    box_pos = builder->m_refBuilder->get_widget<Gtk::Box>("box_pos");
    stack_main_pos = builder->m_refBuilder->get_widget<Gtk::Stack>("stack_main_pos");
    auto stack_debug = builder->m_refBuilder->get_widget<Gtk::StackSwitcher>("stack_debug");
    tree_prov = builder->m_refBuilder->get_widget<Gtk::TreeView>("tree_prov");
    lbl_cont_prod = builder->m_refBuilder->get_widget<Gtk::Label>("lbl_cont_prod");
    btn_add_prov = builder->m_refBuilder->get_widget<Gtk::Button>("btn_add_prov");
    btn_remove_prov = builder->m_refBuilder->get_widget<Gtk::Button>("btn_remove_prov");
    btn_edit_prov = builder->m_refBuilder->get_widget<Gtk::Button>("btn_edit_prov");
    lbl_precio_total = builder->m_refBuilder->get_widget<Gtk::Label>("lbl_precio_total");

    lbl_precio_total->set_markup("<span font_desc='50'>$0.00</span>");
    stack_switcher.set_stack(*stack_main_pos);
    stack_switcher.set_child_visible(true);
    stack_main_pos->set_transition_type(Gtk::StackTransitionType::SLIDE_LEFT_RIGHT);

    stack_debug->hide();
    set_child(*box_pos);
}

void Pos::carga_señales()
{
    btn_add_prov->signal_clicked().connect(sigc::mem_fun(*this, &Pos::on_btn_add_clicked));
    cell1->signal_edited().connect(sigc::mem_fun(*this, &Pos::on_cell1_edited));
    cell2->signal_edited().connect(sigc::mem_fun(*this, &Pos::on_cell2_edited));
    cell3->signal_edited().connect(sigc::mem_fun(*this, &Pos::on_cell3_edited));
    cell4->signal_edited().connect(sigc::mem_fun(*this, &Pos::on_cell4_edited));
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

    for (int i = 0; i < result.size(); i++)
    {
        row = *(m_refTreeModel->append());
        row[m_Columns.id] = std::atoi(result[i][0].c_str());
        row[m_Columns.m_col_name] = result[i][1];
        row[m_Columns.numero] = std::atoi(result[i][2].c_str());
        row[m_Columns.empresa] = result[i][3];
        row[m_Columns.correo] = result[i][4];
    }

    // row = *(m_refTreeModel->append());
    // row[m_Columns.id] = 1;
    // row[m_Columns.m_col_name] = "Juan";
    // row[m_Columns.numero] = 123456789;
    // row[m_Columns.empresa] = "Empresa";
    // row[m_Columns.correo] = "algun_correo@correo.com";


    tree_prov->set_search_column(m_Columns.m_col_name);
    tree_prov->set_enable_search(true);
    tree_prov->set_visible(true);

    tree_prov->set_headers_visible(true);
}

void Pos::on_cell1_edited(const Glib::ustring &path_string, const Glib::ustring &new_text)
{
    auto dialog = new Gtk::MessageDialog(*this, "Editar", false, Gtk::MessageType::QUESTION, Gtk::ButtonsType::OK_CANCEL, true);
    dialog->set_secondary_text("¿Desea editar el campo?");
    dialog->signal_response().connect(sigc::bind(sigc::mem_fun(*this, &Pos::on_prov_dialog_edit_response), dialog, path_string, new_text, COLUMNS::ColumnProveedor::NOMBRE));
    dialog->set_default_response(Gtk::ResponseType::OK);
    dialog->show();
}

void Pos::on_cell2_edited(const Glib::ustring &path_string, const Glib::ustring &new_text)
{
    auto dialog = new Gtk::MessageDialog(*this, "Editar", false, Gtk::MessageType::QUESTION, Gtk::ButtonsType::OK_CANCEL, true);
    dialog->set_secondary_text("¿Desea editar el campo?");
    dialog->signal_response().connect(sigc::bind(sigc::mem_fun(*this, &Pos::on_prov_dialog_edit_response), dialog, path_string, new_text, COLUMNS::ColumnProveedor::TELEFONO));
    dialog->set_default_response(Gtk::ResponseType::OK);
    dialog->show();
}

void Pos::on_cell3_edited(const Glib::ustring &path_string, const Glib::ustring &new_text)
{
    auto dialog = new Gtk::MessageDialog(*this, "Editar", false, Gtk::MessageType::QUESTION, Gtk::ButtonsType::OK_CANCEL, true);
    dialog->set_secondary_text("¿Desea editar el campo?");
    dialog->signal_response().connect(sigc::bind(sigc::mem_fun(*this, &Pos::on_prov_dialog_edit_response), dialog, path_string, new_text, COLUMNS::ColumnProveedor::EMPRESA));
    dialog->set_default_response(Gtk::ResponseType::OK);
    dialog->show();
}

void Pos::on_cell4_edited(const Glib::ustring &path_string, const Glib::ustring &new_text)
{
    auto dialog = new Gtk::MessageDialog(*this, "Editar", false, Gtk::MessageType::QUESTION, Gtk::ButtonsType::OK_CANCEL, true);
    dialog->set_secondary_text("¿Desea editar el campo?");
    dialog->signal_response().connect(sigc::bind(sigc::mem_fun(*this, &Pos::on_prov_dialog_edit_response), dialog, path_string, new_text, COLUMNS::ColumnProveedor::EMAIL));
    dialog->set_default_response(Gtk::ResponseType::OK);
    dialog->show();
}

void Pos::on_btn_add_clicked()
{
    row = *(m_refTreeModel->append());
    row[m_Columns.id] = 0;
    row[m_Columns.m_col_name] = "<i>Editame</i>";
    row[m_Columns.numero] = 0;
    row[m_Columns.empresa] = "<i>Editame</i>";
    row[m_Columns.correo] = "<i>Editame</i>";
}

void Pos::on_prov_dialog_edit_response(int response_id, Gtk::MessageDialog *dialog, const Glib::ustring &path_string, const Glib::ustring &new_text, const int &column)
{
    switch (response_id)
    {
    case Gtk::ResponseType::OK:
    {
        auto iter = tree_prov->get_model()->get_iter(path_string);
        if (iter)
        {
            switch (column)
            {
            case COLUMNS::ColumnProveedor::NOMBRE:
            {

                (*iter)[m_Columns.m_col_name] = new_text;
            }
            break;
            case COLUMNS::ColumnProveedor::TELEFONO:
            {

                (*iter)[m_Columns.numero] = std::atoi(new_text.c_str());
            }
            break;
            case COLUMNS::ColumnProveedor::EMPRESA:
            {

                (*iter)[m_Columns.empresa] = new_text;
            }
            break;
            case COLUMNS::ColumnProveedor::EMAIL:
            {

                (*iter)[m_Columns.correo] = new_text;
            }
            break;
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