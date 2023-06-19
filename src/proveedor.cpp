#include "Pos.hpp"
Pos::Pos()
{
    cargar_glade();
    set_title("POS");
    set_default_size(800, 600);
    set_titlebar(header_bar);
    header_bar.pack_start(menu_button);
    header_bar.set_title_widget(stack_switcher);
    init();
}

void Pos::cargar_glade()
{
    box_pos = builder->m_refBuilder->get_widget<Gtk::Box>("box_pos");
    stack_main_pos = builder->m_refBuilder->get_widget<Gtk::Stack>("stack_main_pos");
    auto stack_debug = builder->m_refBuilder->get_widget<Gtk::StackSwitcher>("stack_debug");
    tree_prov = builder->m_refBuilder->get_widget<Gtk::TreeView>("tree_prov");
    lbl_cont_prod = builder->m_refBuilder->get_widget<Gtk::Label>("lbl_cont_prod");
    btn_add = builder->m_refBuilder->get_widget<Gtk::Button>("btn_add");
    btn_remove = builder->m_refBuilder->get_widget<Gtk::Button>("btn_remove");
    btn_edit = builder->m_refBuilder->get_widget<Gtk::Button>("btn_edit");
    lbl_precio_total = builder->m_refBuilder->get_widget<Gtk::Label>("lbl_precio_total");

    lbl_precio_total->set_markup("<span font_desc='50'>$0.00</span>");
    stack_switcher.set_stack(*stack_main_pos);
    stack_switcher.set_child_visible(true);
    stack_main_pos->set_transition_type(Gtk::StackTransitionType::SLIDE_LEFT_RIGHT);

    stack_debug->hide();
    set_child(*box_pos);
}

void Pos::init(){

    m_refTreeModel = Gtk::ListStore::create(m_Columns);
    tree_prov->set_model(m_refTreeModel);

    row = *(m_refTreeModel->append());
    row[m_Columns.id] = 1;
    row[m_Columns.m_col_name] = "Juan";
    row[m_Columns.numero] = 123456789;
    row[m_Columns.empresa] = "Empresa";
    row[m_Columns.correo] = "algun_correo@correo.com";

    tree_prov->append_column("ID", m_Columns.id);
    tree_prov->append_column("Nombre", m_Columns.m_col_name);
    tree_prov->append_column("Numero", m_Columns.numero);
    tree_prov->append_column("Empresa", m_Columns.empresa);
    tree_prov->append_column("Correo", m_Columns.correo);

    tree_prov->set_search_column(m_Columns.m_col_name);
    tree_prov->set_enable_search(true);
    tree_prov->set_visible(true);

    tree_prov->set_headers_visible(true);

}