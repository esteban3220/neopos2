// File: proveedor.cpp

#include "Pos.hpp"
#include "columns.hpp"
#include <string>

Pos::Pos(const Glib::RefPtr<Gtk::Application>& app): builder(std::make_unique<Builder>("<interface>"
  "<object class=\"GtkAdjustment\" id=\"pos_main\"/>"
  "<object class=\"GtkBox\" id=\"box_pos\">"
    "<property name=\"hexpand\">true</property>"
    "<property name=\"orientation\">1</property>"
    "<property name=\"vexpand\">true</property>"
    "<child>"
      "<object class=\"GtkStackSwitcher\" id=\"stack_debug\">"
        "<property name=\"stack\">stack_main_pos</property>"
      "</object>"
    "</child>"
    "<child>"
      "<object class=\"GtkStack\" id=\"stack_main_pos\">"
        "<property name=\"margin-bottom\">10</property>"
        "<property name=\"margin-end\">10</property>"
        "<property name=\"margin-start\">10</property>"
        "<property name=\"margin-top\">10</property>"
        "<child>"
          "<object class=\"GtkStackPage\">"
            "<property name=\"child\">"
              "<object class=\"GtkBox\" id=\"box_pos1\">"
                "<property name=\"orientation\">1</property>"
                "<property name=\"spacing\">10</property>"
                "<child>"
                  "<object class=\"GtkBox\">"
                    "<property name=\"spacing\">5</property>"
                    "<child>"
                      "<object class=\"GtkEntry\" id=\"ety_barras\">"
                        "<property name=\"hexpand\">true</property>"
                        "<property name=\"placeholder-text\">Ingresa un Codigo de Barras.</property>"
                        "<property name=\"primary-icon-name\">edit-find-replace-symbolic</property>"
                        "<property name=\"primary-icon-tooltip-text\">Añadir con Cantidad Custom</property>"
                        "<property name=\"secondary-icon-name\">edit-paste-symbolic</property>"
                        "<property name=\"secondary-icon-tooltip-text\">Añadir con Précio Custom</property>"
                      "</object>"
                    "</child>"
                  "</object>"
                "</child>"
                "<child>"
                  "<object class=\"GtkBox\">"
                    "<property name=\"spacing\">5</property>"
                    "<child>"
                      "<object class=\"GtkScrolledWindow\">"
                        "<property name=\"hexpand\">true</property>"
                        "<property name=\"hexpand-set\">true</property>"
                        "<property name=\"vexpand\">true</property>"
                        "<property name=\"vexpand-set\">true</property>"
                        "<child>"
                          "<object class=\"GtkTreeView\" id=\"tree_venta\">"
                            "<property name=\"enable-grid-lines\">2</property>"
                            "<property name=\"enable-search\">false</property>"
                          "</object>"
                        "</child>"
                      "</object>"
                    "</child>"
                    "<child>"
                      "<object class=\"GtkBox\">"
                        "<property name=\"orientation\">1</property>"
                        "<property name=\"spacing\">10</property>"
                        "<child>"
                          "<object class=\"GtkBox\">"
                            "<child>"
                              "<object class=\"GtkLabel\">"
                                "<property name=\"halign\">1</property>"
                                "<property name=\"valign\">1</property>"
                              "</object>"
                            "</child>"
                            "<child>"
                              "<object class=\"GtkLabel\">"
                                "<property name=\"halign\">2</property>"
                                "<property name=\"justify\">1</property>"
                                "<property name=\"valign\">2</property>"
                              "</object>"
                            "</child>"
                          "</object>"
                        "</child>"
                        "<child>"
                          "<object class=\"GtkFrame\">"
                            "<property name=\"child\">"
                              "<object class=\"GtkLabel\" id=\"lbl_precio_total\">"
                                "<property name=\"ellipsize\">2</property>"
                                "<property name=\"justify\">2</property>"
                                "<property name=\"label\">$ &lt;span font_desc='50'&gt;0.00&lt;/span&gt;</property>"
                                "<property name=\"use-markup\">true</property>"
                                "<property name=\"width-chars\">0</property>"
                                "<property name=\"width-request\">300</property>"
                              "</object>"
                            "</property>"
                            "<property name=\"label\">Total</property>"
                            "<property name=\"label-xalign\">0.5</property>"
                            "<property name=\"vexpand\">true</property>"
                            "<property name=\"vexpand-set\">true</property>"
                          "</object>"
                        "</child>"
                        "<child>"
                          "<object class=\"GtkFrame\">"
                            "<property name=\"child\">"
                              "<object class=\"GtkSpinButton\" id=\"spin_ingreso\">"
                                "<property name=\"adjustment\">pos_main</property>"
                                "<property name=\"digits\">2</property>"
                                "<property name=\"margin-bottom\">10</property>"
                                "<property name=\"margin-end\">10</property>"
                                "<property name=\"margin-start\">10</property>"
                                "<property name=\"numeric\">true</property>"
                              "</object>"
                            "</property>"
                            "<property name=\"label\">Ingreso</property>"
                            "<property name=\"label-xalign\">0.5</property>"
                          "</object>"
                        "</child>"
                        "<child>"
                          "<object class=\"GtkFrame\">"
                            "<property name=\"child\">"
                              "<object class=\"GtkLabel\" id=\"lbl_cambio\">"
                                "<property name=\"label\">$&lt;span font_desc='30'&gt;0.00&lt;/span&gt;</property>"
                                "<property name=\"margin-bottom\">10</property>"
                                "<property name=\"margin-end\">10</property>"
                                "<property name=\"margin-start\">10</property>"
                                "<property name=\"use-markup\">true</property>"
                              "</object>"
                            "</property>"
                            "<property name=\"label\">Cambio</property>"
                            "<property name=\"label-xalign\">0.5</property>"
                          "</object>"
                        "</child>"
                        "<child>"
                          "<object class=\"GtkBox\">"
                            "<property name=\"homogeneous\">true</property>"
                            "<property name=\"spacing\">5</property>"
                            "<child>"
                              "<object class=\"GtkButton\" id=\"btn_pago_efectivo\">"
                                "<property name=\"accessible-role\">3</property>"
                                "<property name=\"css-classes\">suggested-action</property>"
                                "<property name=\"icon-name\">system-switch-user-symbolic</property>"
                                "<property name=\"label\">Efectivo</property>"
                              "</object>"
                            "</child>"
                            "<child>"
                              "<object class=\"GtkButton\" id=\"btn_pago_tarjeta\">"
                                "<property name=\"css-classes\">suggested-action</property>"
                                "<property name=\"icon-name\">system-switch-user-symbolic</property>"
                                "<property name=\"label\">Tarjeta</property>"
                              "</object>"
                            "</child>"
                          "</object>"
                        "</child>"
                      "</object>"
                    "</child>"
                  "</object>"
                "</child>"
              "</object>"
            "</property>"
            "<property name=\"title\">POS</property>"
          "</object>"
        "</child>"
        "<child>"
          "<object class=\"GtkStackPage\">"
            "<property name=\"child\">"
              "<object class=\"GtkBox\">"
                "<property name=\"orientation\">1</property>"
                "<property name=\"spacing\">5</property>"
                "<child>"
                  "<object class=\"GtkScrolledWindow\" id=\"scroll_tree\">"
                    "<property name=\"child\">"
                      "<object class=\"GtkTreeView\" id=\"tree_prov\">"
                        "<property name=\"enable-grid-lines\">2</property>"
                      "</object>"
                    "</property>"
                    "<property name=\"hexpand\">true</property>"
                    "<property name=\"hexpand-set\">true</property>"
                    "<property name=\"vexpand\">true</property>"
                    "<property name=\"vexpand-set\">true</property>"
                  "</object>"
                "</child>"
                "<child>"
                  "<object class=\"GtkBox\">"
                    "<property name=\"margin-end\">5</property>"
                    "<property name=\"margin-start\">0</property>"
                    "<property name=\"orientation\">0</property>"
                    "<property name=\"spacing\">5</property>"
                    "<child>"
                      "<object class=\"GtkLabel\" id=\"lbl_con_prov\">"
                        "<property name=\"label\">Proveedores: 0</property>"
                      "</object>"
                    "</child>"
                    "<child>"
                      "<object class=\"GtkBox\">"
                        "<property name=\"halign\">2</property>"
                        "<property name=\"hexpand\">true</property>"
                        "<property name=\"hexpand-set\">true</property>"
                        "<child>"
                          "<object class=\"GtkButton\" id=\"btn_add_prov\">"
                            "<property name=\"icon-name\">list-add-symbolic</property>"
                            "<property name=\"margin-bottom\">0</property>"
                            "<property name=\"tooltip-text\">Añade un nuevo registro.</property>"
                          "</object>"
                        "</child>"
                        "<child>"
                          "<object class=\"GtkButton\" id=\"btn_remove_prov\">"
                            "<property name=\"css-classes\">destructive-action</property>"
                            "<property name=\"icon-name\">list-remove-symbolic</property>"
                            "<property name=\"margin-bottom\">0</property>"
                            "<property name=\"tooltip-text\">Elimina un registro.</property>"
                          "</object>"
                        "</child>"
                      "</object>"
                    "</child>"
                  "</object>"
                "</child>"
              "</object>"
            "</property>"
            "<property name=\"title\">Proveedores</property>"
          "</object>"
        "</child>"
        "<child>"
          "<object class=\"GtkStackPage\">"
            "<property name=\"child\">"
              "<object class=\"GtkBox\">"
                "<property name=\"orientation\">1</property>"
                "<property name=\"spacing\">5</property>"
                "<child>"
                  "<object class=\"GtkScrolledWindow\">"
                    "<property name=\"hexpand\">true</property>"
                    "<property name=\"hexpand-set\">true</property>"
                    "<property name=\"vexpand\">true</property>"
                    "<property name=\"vexpand-set\">true</property>"
                    "<child>"
                      "<object class=\"GtkTreeView\" id=\"tree_prod\">"
                        "<property name=\"enable-grid-lines\">both</property>"
                      "</object>"
                    "</child>"
                  "</object>"
                "</child>"
                "<child>"
                  "<object class=\"GtkBox\">"
                    "<property name=\"margin-end\">5</property>"
                    "<property name=\"margin-start\">0</property>"
                    "<property name=\"orientation\">0</property>"
                    "<child>"
                      "<object class=\"GtkLabel\" id=\"lbl_cont_prod\">"
                        "<property name=\"label\">Productos: 0</property>"
                      "</object>"
                    "</child>"
                    "<child>"
                      "<object class=\"GtkBox\">"
                        "<property name=\"halign\">2</property>"
                        "<property name=\"hexpand\">true</property>"
                        "<property name=\"hexpand-set\">true</property>"
                        "<child>"
                          "<object class=\"GtkButton\" id=\"btn_add_piezas\">"
                            "<property name=\"css-classes\">suggested-action</property>"
                            "<property name=\"icon-name\">insert-object-symbolic</property>"
                            "<property name=\"tooltip-text\">Recibe pedido.</property>"
                          "</object>"
                        "</child>"
                        "<child>"
                          "<object class=\"GtkButton\" id=\"btn_add_produ\">"
                            "<property name=\"icon-name\">list-add-symbolic</property>"
                            "<property name=\"margin-bottom\">0</property>"
                            "<property name=\"tooltip-text\">Añade un nuevo registro.</property>"
                          "</object>"
                        "</child>"
                        "<child>"
                          "<object class=\"GtkButton\" id=\"btn_remove_produ\">"
                            "<property name=\"css-classes\">destructive-action</property>"
                            "<property name=\"icon-name\">list-remove-symbolic</property>"
                            "<property name=\"margin-bottom\">0</property>"
                            "<property name=\"tooltip-text\">Elimina un registro.</property>"
                          "</object>"
                        "</child>"
                      "</object>"
                    "</child>"
                  "</object>"
                "</child>"
              "</object>"
            "</property>"
            "<property name=\"title\">Productos</property>"
          "</object>"
        "</child>"
        "<child>"
          "<object class=\"GtkStackPage\">"
            "<property name=\"child\">"
              "<object class=\"GtkBox\">"
                "<child>"
                  "<object class=\"GtkBox\">"
                    "<property name=\"orientation\">1</property>"
                    "<property name=\"spacing\">5</property>"
                    "<child>"
                      "<object class=\"GtkFrame\">"
                        "<property name=\"label\">Busqueda de Ventas.</property>"
                        "<child>"
                          "<object class=\"GtkBox\">"
                            "<property name=\"margin-bottom\">5</property>"
                            "<property name=\"margin-end\">5</property>"
                            "<property name=\"margin-start\">5</property>"
                            "<property name=\"spacing\">5</property>"
                            "<child>"
                              "<object class=\"GtkSpinButton\"/>"
                            "</child>"
                            "<child>"
                              "<object class=\"GtkMenuButton\">"
                                "<property name=\"halign\">2</property>"
                                "<property name=\"hexpand\">true</property>"
                                "<property name=\"label\">Fecha</property>"
                              "</object>"
                            "</child>"
                          "</object>"
                        "</child>"
                      "</object>"
                    "</child>"
                    "<child>"
                      "<object class=\"GtkBox\">"
                        "<property name=\"spacing\">5</property>"
                        "<child>"
                          "<object class=\"GtkFrame\">"
                            "<child>"
                              "<object class=\"GtkScrolledWindow\">"
                                "<property name=\"hexpand\">true</property>"
                                "<property name=\"hexpand-set\">true</property>"
                                "<property name=\"vexpand\">true</property>"
                                "<property name=\"vexpand-set\">true</property>"
                                "<child>"
                                  "<object class=\"GtkTreeView\" id=\"tree_repor\">"
                                    "<property name=\"activate-on-single-click\">true</property>"
                                    "<property name=\"enable-grid-lines\">1</property>"
                                  "</object>"
                                "</child>"
                              "</object>"
                            "</child>"
                          "</object>"
                        "</child>"
                        "<child>"
                          "<object class=\"GtkFrame\">"
                            "<property name=\"width-request\">450</property>"
                            "<child>"
                              "<object class=\"GtkScrolledWindow\">"
                                "<child>"
                                  "<object class=\"GtkTreeView\" id=\"tree_detalle_venta\">"
                                    "<property name=\"enable-grid-lines\">2</property>"
                                  "</object>"
                                "</child>"
                              "</object>"
                            "</child>"
                          "</object>"
                        "</child>"
                      "</object>"
                    "</child>"
                  "</object>"
                "</child>"
              "</object>"
            "</property>"
            "<property name=\"title\">Reportes</property>"
          "</object>"
        "</child>"
        "<child>"
          "<object class=\"GtkStackPage\">"
            "<property name=\"child\">"
              "<object class=\"GtkGrid\">"
                "<property name=\"column-homogeneous\">true</property>"
                "<property name=\"column-spacing\">5</property>"
                "<property name=\"row-homogeneous\">true</property>"
                "<property name=\"row-spacing\">5</property>"
                "<property name=\"valign\">4</property>"
                "<child>"
                  "<object class=\"GtkFrame\">"
                    "<property name=\"child\">"
                      "<object class=\"GtkLabel\" id=\"lbl_venta_dia\">"
                        "<property name=\"label\">$0.00</property>"
                        "<property name=\"use-markup\">true</property>"
                      "</object>"
                    "</property>"
                    "<property name=\"label\">Venta del día</property>"
                    "<layout>"
                      "<property name=\"column\">0</property>"
                      "<property name=\"column-span\">1</property>"
                      "<property name=\"row\">0</property>"
                      "<property name=\"row-span\">2</property>"
                    "</layout>"
                  "</object>"
                "</child>"
                "<child>"
                  "<object class=\"GtkFrame\">"
                    "<property name=\"child\">"
                      "<object class=\"GtkLabel\" id=\"lbl_venta_min_mes\">"
                        "<property name=\"label\">$0.00</property>"
                        "<property name=\"use-markup\">true</property>"
                      "</object>"
                    "</property>"
                    "<property name=\"label\">Venta Minima del Mes</property>"
                    "<layout>"
                      "<property name=\"column\">1</property>"
                      "<property name=\"column-span\">1</property>"
                      "<property name=\"row\">1</property>"
                      "<property name=\"row-span\">1</property>"
                    "</layout>"
                  "</object>"
                "</child>"
                "<child>"
                  "<object class=\"GtkFrame\">"
                    "<property name=\"child\">"
                      "<object class=\"GtkLabel\" id=\"lbl_clientes_dia\">"
                        "<property name=\"label\">10</property>"
                        "<property name=\"use-markup\">true</property>"
                      "</object>"
                    "</property>"
                    "<property name=\"label\">Clientes del día</property>"
                    "<layout>"
                      "<property name=\"column\">0</property>"
                      "<property name=\"column-span\">1</property>"
                      "<property name=\"row\">2</property>"
                      "<property name=\"row-span\">2</property>"
                    "</layout>"
                  "</object>"
                "</child>"
                "<child>"
                  "<object class=\"GtkFrame\">"
                    "<property name=\"child\">"
                      "<object class=\"GtkLabel\" id=\"lbl_venta_mes\">"
                        "<property name=\"label\">$0.00</property>"
                        "<property name=\"use-markup\">true</property>"
                      "</object>"
                    "</property>"
                    "<property name=\"label\">Venta del Mes</property>"
                    "<layout>"
                      "<property name=\"column\">1</property>"
                      "<property name=\"column-span\">1</property>"
                      "<property name=\"row\">0</property>"
                      "<property name=\"row-span\">1</property>"
                    "</layout>"
                  "</object>"
                "</child>"
                "<child>"
                  "<object class=\"GtkFrame\">"
                    "<property name=\"child\">"
                      "<object class=\"GtkLabel\" id=\"lbl_venta_min_anio\">"
                        "<property name=\"label\">$0.00</property>"
                        "<property name=\"use-markup\">true</property>"
                      "</object>"
                    "</property>"
                    "<property name=\"label\">Venta Minima del Año</property>"
                    "<layout>"
                      "<property name=\"column\">2</property>"
                      "<property name=\"column-span\">1</property>"
                      "<property name=\"row\">1</property>"
                      "<property name=\"row-span\">1</property>"
                    "</layout>"
                  "</object>"
                "</child>"
                "<child>"
                  "<object class=\"GtkFrame\">"
                    "<property name=\"child\">"
                      "<object class=\"GtkLabel\" id=\"lbl_venta_anio\">"
                        "<property name=\"label\">$0.00</property>"
                        "<property name=\"use-markup\">true</property>"
                      "</object>"
                    "</property>"
                    "<property name=\"label\">Venta del Año</property>"
                    "<layout>"
                      "<property name=\"column\">2</property>"
                      "<property name=\"row\">0</property>"
                      "<property name=\"row-span\">1</property>"
                    "</layout>"
                  "</object>"
                "</child>"
                "<child>"
                  "<object class=\"GtkFrame\">"
                    "<property name=\"child\">"
                      "<object class=\"GtkLabel\" id=\"lbl_venta_anio_anterior\">"
                        "<property name=\"label\">$&lt;span font_desc='50'&gt;0.00 &lt;/span&gt;</property>"
                        "<property name=\"use-markup\">true</property>"
                      "</object>"
                    "</property>"
                    "<property name=\"label\">Venta del Año Anterior</property>"
                    "<layout>"
                      "<property name=\"column\">1</property>"
                      "<property name=\"column-span\">2</property>"
                      "<property name=\"row\">3</property>"
                    "</layout>"
                  "</object>"
                "</child>"
                "<child>"
                  "<object class=\"GtkFrame\">"
                    "<property name=\"child\">"
                      "<object class=\"GtkLabel\" id=\"lbl_venta_max_mes\">"
                        "<property name=\"label\">$0.00</property>"
                        "<property name=\"use-markup\">true</property>"
                      "</object>"
                    "</property>"
                    "<property name=\"label\">Venta Maxima del mes</property>"
                    "<layout>"
                      "<property name=\"column\">1</property>"
                      "<property name=\"column-span\">1</property>"
                      "<property name=\"row\">2</property>"
                    "</layout>"
                  "</object>"
                "</child>"
                "<child>"
                  "<object class=\"GtkFrame\">"
                    "<property name=\"child\">"
                      "<object class=\"GtkLabel\" id=\"lbl_venta_max_anio\">"
                        "<property name=\"label\">$0.00</property>"
                        "<property name=\"use-markup\">true</property>"
                      "</object>"
                    "</property>"
                    "<property name=\"label\">Venta Maxima del Año</property>"
                    "<layout>"
                      "<property name=\"column\">2</property>"
                      "<property name=\"column-span\">1</property>"
                      "<property name=\"row\">2</property>"
                    "</layout>"
                  "</object>"
                "</child>"
              "</object>"
            "</property>"
            "<property name=\"title\">Estadisticas</property>"
          "</object>"
        "</child>"
      "</object>"
    "</child>"
  "</object>"
"</interface>"))
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
    act_dashboard();
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
    db->clear_result();

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
    lbl_venta_dia = builder->m_refBuilder->get_widget<Gtk::Label>("lbl_venta_dia");
    lbl_venta_mes = builder->m_refBuilder->get_widget<Gtk::Label>("lbl_venta_mes");
    lbl_venta_anio = builder->m_refBuilder->get_widget<Gtk::Label>("lbl_venta_anio");
    lbl_clientes_dia = builder->m_refBuilder->get_widget<Gtk::Label>("lbl_clientes_dia");
    lbl_venta_min_mes = builder->m_refBuilder->get_widget<Gtk::Label>("lbl_venta_min_mes");
    lbl_venta_min_anio = builder->m_refBuilder->get_widget<Gtk::Label>("lbl_venta_min_anio");
    lbl_venta_max_mes = builder->m_refBuilder->get_widget<Gtk::Label>("lbl_venta_max_mes");
    lbl_venta_max_anio = builder->m_refBuilder->get_widget<Gtk::Label>("lbl_venta_max_anio");
    lbl_venta_anio_anterior = builder->m_refBuilder->get_widget<Gtk::Label>("lbl_venta_anio_anterior");


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
    ety_barras->signal_icon_press().connect(sigc::mem_fun(*this, &Pos::on_ety_barras_icon_press));
    completion_pos->signal_match_selected().connect(sigc::mem_fun(*this, &Pos::add_match_arcticulo), false);
    completion_producto->signal_match_selected().connect(sigc::mem_fun(*this, &Pos::add_match_producto), false);
    spin_ingreso->signal_changed().connect(sigc::mem_fun(*this, &Pos::on_spin_ingreso_changed));
    controller->signal_key_pressed().connect(sigc::mem_fun(*this, &Pos::on_spin_ingreso_activate), false);
    btn_pago_efectivo->signal_clicked().connect(sigc::mem_fun(*this, &Pos::cierra_venta));
    btn_pago_tarjeta->signal_clicked().connect(sigc::mem_fun(*this, &Pos::on_btn_pago_tarjeta_clicked));
    btn_remove_produ->signal_clicked().connect(sigc::mem_fun(*this, &Pos::on_btn_remove_prod_clicked));
    btn_add_piezas->signal_clicked().connect([this]() { popover_ingreso_articulos.popup(); });
    ety_articulo_popover.signal_activate().connect(sigc::mem_fun(*this, &Pos::add_articulo_venta_popover));
    btn_add_articulo_popover.signal_clicked().connect(sigc::mem_fun(*this, &Pos::add_btn_articulo_venta_popover));
    tree_repor->signal_row_activated().connect(sigc::mem_fun(*this, &Pos::on_tree_detalle_venta_row_activated));
    refGesture->signal_pressed().connect(sigc::mem_fun(*this, &Pos::on_popup_button_pressed));
    spin_cantiad_point.signal_value_changed().connect([this](){
        if (spin_cantiad_point.get_value() > 0){
            ety_barras->set_css_classes({"warning"});
            ety_barras->set_placeholder_text("Cantidad: " + spin_cantiad_point.get_text() + " Ingrese Codigo de Barras" );
        }
        else{
            ety_barras->set_css_classes({"entry"});
            ety_barras->set_placeholder_text("Ingrese Codigo de Barras" );
        }
    });

    spin_precio_articulo.signal_value_changed().connect([this](){
        if (spin_precio_articulo.get_value() > 0){
            ety_barras->set_css_classes({"warning"});
            ety_barras->set_placeholder_text("Precio: $" + spin_precio_articulo.get_text() + " Ingrese Codigo de Barras" );
        }
        else{
            ety_barras->set_css_classes({"entry"});
            ety_barras->set_placeholder_text("Ingrese Codigo de Barras" );
        }
    });

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
                                            {
                                                try{
                                                row_producto = *(m_refTreeModel_prod->append()); 
                                                row_producto[m_Columns_prod.sku] = cont_prod + 9;
                                                db->command("insert into producto (sku) values (" + std::to_string(row_producto[m_Columns_prod.sku]) + ")");
                                                lbl_cont_prod->set_text("Productos: " + std::to_string(++cont_prod)); 
                                                }catch(std::exception &e){
                                                    try{
                                                    std::cout << e.what() << std::endl;
                                                    auto row_size = m_refTreeModel_prod->children().size() - 1;
                                                    m_refTreeModel_prod->erase(m_refTreeModel_prod->get_iter(std::to_string(row_size)));

                                                    row_producto = *(m_refTreeModel_prod->append());
                                                    row_producto[m_Columns_prod.sku] = cont_prod + 101;
                                                    db->command("insert into producto (sku) values (" + std::to_string(row_producto[m_Columns_prod.sku]) + ")");
                                                    lbl_cont_prod->set_text("Productos: " + std::to_string(++cont_prod));
                                                    }
                                                    catch(std::exception &e){
                                                        std::cout << e.what() << std::endl;
                                                        auto row_size = m_refTreeModel_prod->children().size() - 1;
                                                        m_refTreeModel_prod->erase(m_refTreeModel_prod->get_iter(std::to_string(row_size)));

                                                        row_producto = *(m_refTreeModel_prod->append());
                                                        lbl_cont_prod->set_text("Productos: " + std::to_string(++cont_prod));
                                                    }
                                                }
                                            });

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

    cell_granel->signal_toggled().connect([this](const Glib::ustring &path_string)
                                          {dialog.reset(new Gtk::MessageDialog(*this, "Editar", false, Gtk::MessageType::QUESTION, Gtk::ButtonsType::OK_CANCEL, true));
                                            dialog->set_secondary_text("¿Desea habilitar/deshabilitar la venta a Granel de este Producto?");
                                            dialog->signal_response().connect(sigc::bind(sigc::mem_fun(*this, &Pos::on_produ_dialog_edit_response),path_string, "", COLUMNS::ColumnProducto::GRANEL));
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

    m_refTreeModelCombo = Gtk::ListStore::create(m_ColumnsCombo);
    auto iter_ = Gtk::TreeModel::iterator();

    for (int i = 0; i < db->get_result().size(); i++)
    {
        row = *(m_refTreeModel->append());
        row[m_Columns.id] = std::stol(db->get_result()[i][0]);
        row[m_Columns.m_col_name] = db->get_result()[i][1];
        row[m_Columns.numero] = db->get_result()[i][2];
        row[m_Columns.empresa] = db->get_result()[i][3];
        row[m_Columns.correo] = db->get_result()[i][4];
        iter_ = m_refTreeModelCombo->append();
        (*iter_)[m_ColumnsCombo.m_col_name] = db->get_result()[i][3];
    }
    db->clear_result();

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