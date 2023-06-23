#ifndef POS_HPP
#define POS_HPP 
#include "builder.hpp"
#include <memory>
#include <iostream>
#include "sqlite.cpp"

class Pos : public Gtk::Window
{
private:
    /* data */
    std::unique_ptr<Builder> builder = std::make_unique<Builder>("../test/mainpos.ui");
    void cargar_glade();
    void init();

    std::unique_ptr<SQLite> db = std::make_unique<SQLite>();

    Gtk::TreeModel::Row row;

    class ModelColumns : public Gtk::TreeModel::ColumnRecord
    {
    public:
        ModelColumns()
        {
            add(id);
            add(m_col_name);
            add(numero);
            add(empresa);
            add(correo);
        }

        Gtk::TreeModelColumn<int> id;
        Gtk::TreeModelColumn<Glib::ustring> m_col_name;
        Gtk::TreeModelColumn<Glib::ustring> empresa;
        Gtk::TreeModelColumn<Glib::ustring> numero;
        Gtk::TreeModelColumn<Glib::ustring> correo;
    };
    ModelColumns m_Columns;
    Glib::RefPtr<Gtk::ListStore> m_refTreeModel;
    Gtk::CellRendererText m_cellrenderer_validated;
    Gtk::TreeView::Column m_treeviewcolumn_validated;
    Glib::ustring m_invalid_text_for_retry;

    //)==================================Proveedor==================================(
    Gtk::CellRendererText *cell1 = Gtk::manage(new Gtk::CellRendererText());
    Gtk::CellRendererText *cell2 = Gtk::manage(new Gtk::CellRendererText());
    Gtk::CellRendererText *cell3 = Gtk::manage(new Gtk::CellRendererText());
    Gtk::CellRendererText *cell4 = Gtk::manage(new Gtk::CellRendererText());

    Gtk::TreeViewColumn *col1 = nullptr;
    Gtk::TreeViewColumn *col2 = nullptr;
    Gtk::TreeViewColumn *col3 = nullptr;
    Gtk::TreeViewColumn *col4 = nullptr;
    //)==================================Proveedor==================================(

    void on_cell1_edited(const Glib::ustring &path_string, const Glib::ustring &new_text);
    void on_cell2_edited(const Glib::ustring &path_string, const Glib::ustring &new_text);
    void on_cell3_edited(const Glib::ustring &path_string, const Glib::ustring &new_text);
    void on_cell4_edited(const Glib::ustring &path_string, const Glib::ustring &new_text);
    void on_prov_dialog_edit_response(int response_id, Gtk::MessageDialog *dialog, const Glib::ustring &path_string, const Glib::ustring &new_text, const int &column);

    Gtk::TreeView *tree_prov;
    Gtk::Label *lbl_cont_prod,*lbl_con_prov;
    Gtk::Button *btn_add_prov, *btn_remove_prov, *btn_edit_prov;

    size_t cont_prov = 0;
    size_t cont_prod = 0;
    size_t cont_vent = 0;


    void carga_señales();

    void on_btn_add_clicked();

protected:
    Gtk::Box *box_pos;
    Gtk::Label *lbl_precio_total;
    Gtk::HeaderBar header_bar;
    Gtk::StackSwitcher stack_switcher;
    Gtk::Stack *stack_main_pos;
    Gtk::MenuButton menu_button;
    Gtk::Label lbl_total;

public:
    Pos(/* args */);
    ~Pos() {}

};

#endif //POS_HPP