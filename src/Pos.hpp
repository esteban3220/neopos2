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
    void init_producto();

    std::unique_ptr<SQLite> db = std::make_unique<SQLite>();

    Gtk::TreeModel::Row row_producto;

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
    void on_prov_dialog_remove_response(int response_id, Gtk::MessageDialog *dialog);


    void on_produ_dialog_edit_response(int response_id, Gtk::MessageDialog *dialog, const Glib::ustring &path_string, const Glib::ustring &new_text, const int &column);

    void on_cell_cantidad_edited(const Glib::ustring &path_string, const Glib::ustring &new_text);
    
    void on_cell_marca_changed(int response_id,Gtk::MessageDialog *dialog,const Glib::ustring &path_string, const Gtk::TreeModel::iterator &);

    void on_cell_data_func_u(Gtk::CellRenderer* renderer,const Gtk::TreeModel::const_iterator& iter);
    void on_cell_data_func_c(Gtk::CellRenderer* renderer,const Gtk::TreeModel::const_iterator& iter);

    Gtk::TreeView *tree_prov;
    Gtk::Label *lbl_cont_prod, *lbl_con_prov;
    Gtk::Button *btn_add_prov, *btn_remove_prov, *btn_edit_prov , *btn_add_produ, *btn_remove_produ;

    size_t cont_prov = 0;
    size_t cont_prod = 0;
    size_t cont_vent = 0;

    //)==================================Producto==================================(
    Gtk::TreeModel::Row row;

    class ModelPrroductos : public Gtk::TreeModel::ColumnRecord
    {
    public:
        ModelPrroductos()
        {
            add(sku);
            add(nombre);
            add(caducidad);
            add(marca);
            add(nota);
            add(piezas);
            add(precio_u);
            add(categoria);
            add(subcategoria);
        }

        Gtk::TreeModelColumn<int> sku;
        Gtk::TreeModelColumn<Glib::ustring> nombre;
        Gtk::TreeModelColumn<Glib::ustring> caducidad;
        Gtk::TreeModelColumn<Glib::ustring> marca;
        Gtk::TreeModelColumn<Glib::ustring> nota;
        Gtk::TreeModelColumn<int> piezas;
        Gtk::TreeModelColumn<float> precio_u;
        Gtk::TreeModelColumn<Glib::ustring> categoria;
        Gtk::TreeModelColumn<Glib::ustring> subcategoria;
    };
    ModelPrroductos m_Columns_prod;

    Glib::RefPtr<Gtk::ListStore> m_refTreeModel_prod;

    Gtk::CellRendererText *cell_sku = Gtk::manage(new Gtk::CellRendererText());
    Gtk::CellRendererText *cell_nombre = Gtk::manage(new Gtk::CellRendererText());
    Gtk::CellRendererText *cell_caducidad = Gtk::manage(new Gtk::CellRendererText());
    Gtk::CellRendererCombo *cell_marca = Gtk::make_managed<Gtk::CellRendererCombo>();
    Gtk::CellRendererText *cell_nota = Gtk::manage(new Gtk::CellRendererText());
    Gtk::CellRendererText *cell_piezas = Gtk::manage(new Gtk::CellRendererText());
    Gtk::CellRendererSpin *cell_precio_u = Gtk::manage(new Gtk::CellRendererSpin());
    Gtk::CellRendererSpin *cell_compra_t = Gtk::manage(new Gtk::CellRendererSpin());
    Gtk::CellRendererCombo *cell_categoria = Gtk::make_managed<Gtk::CellRendererCombo>();
    Gtk::CellRendererCombo *cell_subcategoria = Gtk::make_managed<Gtk::CellRendererCombo>();

    Gtk::TreeViewColumn *col_sku = nullptr;
    Gtk::TreeViewColumn *col_nombre = nullptr;
    Gtk::TreeViewColumn *col_caducidad = nullptr;
    Gtk::TreeViewColumn *col_marca = nullptr;
    Gtk::TreeViewColumn *col_nota = nullptr;
    Gtk::TreeViewColumn *col_piezas = nullptr;
    Gtk::TreeViewColumn *col_precio_u = nullptr;
    Gtk::TreeViewColumn *col_compra_t = nullptr;
    Gtk::TreeViewColumn *col_categoria = nullptr;
    Gtk::TreeViewColumn *col_subcategoria = nullptr;

    class ModelColumnsCombo : public Gtk::TreeModel::ColumnRecord
    {
    public:
        ModelColumnsCombo()
        {
            add(m_col_name);
        }

        // Gtk::TreeModelColumn<int> id;
        Gtk::TreeModelColumn<Glib::ustring> m_col_name;
    };

    ModelColumnsCombo m_ColumnsCombo;
    Glib::RefPtr<Gtk::ListStore> m_refTreeModelCombo;

    //)==================================Producto==================================(

    void carga_señales();

    void on_btn_add_clicked();
    void on_btn_remove_clicked();

protected:
    Gtk::Box *box_pos;
    Gtk::TreeView *tree_prod;
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

#endif // POS_HPP