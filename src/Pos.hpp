#ifndef POS_HPP
#define POS_HPP
#include "builder.hpp"
#include <memory>
#include <iostream>
#include <map>
#include <vector>
#include "sqlite.cpp"
#include <sstream>

class Pos : public Gtk::Window
{
private:
    /* data */
    std::unique_ptr<Builder> builder = std::make_unique<Builder>("../test/mainpos.ui");
    void cargar_glade();
    void init();
    void init_producto();
    void llena_subca();

    std::map<std::string, std::vector<std::string>> subcategoria_map;

    std::unique_ptr<SQLite> db = std::make_unique<SQLite>();

    Gtk::TreeModel::Row row_producto;
    Gtk::TreeModel::Row row_subcategoria;
    Gtk::TreeModel::Row row_reporte;

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
    std::unique_ptr<Gtk::MessageDialog> dialog;
    std::unique_ptr<Gtk::MessageDialog> dialog_error;

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
    void on_prov_dialog_edit_response(int response_id, const Glib::ustring &path_string, const Glib::ustring &new_text, const int &column);
    void on_prov_dialog_remove_response(int response_id);

    void on_produ_dialog_edit_response(int response_id, const Glib::ustring &path_string, const Glib::ustring &new_text, const int &column);

    void on_cell_cantidad_edited(const Glib::ustring &path_string, const Glib::ustring &new_text);

    void on_cell_marca_changed(int response_id, const Glib::ustring &path_string, const Gtk::TreeModel::iterator &);
    void on_cell_categoria_changed(int response_id, const Glib::ustring &path_string, const Gtk::TreeModel::iterator &);
    void on_cell_subcategoria_changed(int response_id, const Glib::ustring &path_string, const Gtk::TreeModel::iterator &);

    void on_cell_data_func_u(Gtk::CellRenderer *renderer, const Gtk::TreeModel::const_iterator &iter);
    void on_cell_data_func_c(Gtk::CellRenderer *renderer, const Gtk::TreeModel::const_iterator &iter);

    Gtk::TreeView *tree_prov,*tree_venta,*tree_repor;
    Gtk::Label *lbl_cont_prod, *lbl_con_prov;
    Gtk::Button *btn_add_prov, *btn_remove_prov, *btn_edit_prov, *btn_add_produ, *btn_remove_produ;
    Gtk::Entry *ety_barras;

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

        Gtk::TreeModelColumn<size_t> sku;
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

    class ModelVenta : public Gtk::TreeModel::ColumnRecord
    {
    public:
        ModelVenta()
        {
            add(id);
            add(tipo);
            add(total);
            add(ingreso);
            add(cambio);
            add(folio);
            add(fecha);
            add(datos);
        }

        Gtk::TreeModelColumn<size_t> id;
        Gtk::TreeModelColumn<Glib::ustring> tipo;
        Gtk::TreeModelColumn<float> total;
        Gtk::TreeModelColumn<float> ingreso;
        Gtk::TreeModelColumn<float> cambio;
        Gtk::TreeModelColumn<Glib::ustring> folio;
        Gtk::TreeModelColumn<Glib::ustring> fecha;
        Gtk::TreeModelColumn<Glib::ustring> datos;
    };
    ModelVenta m_Columns_reporte;

    Glib::RefPtr<Gtk::ListStore> m_refTreeModel_reporte;

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

    //=========================================================================

    class ModelColumnsCategoria : public Gtk::TreeModel::ColumnRecord
    {
    public:
        ModelColumnsCategoria()
        {
            add(m_col_name);
        }

        Gtk::TreeModelColumn<Glib::ustring> m_col_name;
    };

    ModelColumnsCategoria m_ColumnsCategoria;
    Glib::RefPtr<Gtk::ListStore> m_refTreeModelCategoria;

    class ModelColumnsSubCategoria : public Gtk::TreeModel::ColumnRecord
    {
    public:
        ModelColumnsSubCategoria()
        {
            add(m_col_name);
        }

        Gtk::TreeModelColumn<Glib::ustring> m_col_name;
    };

    ModelColumnsSubCategoria m_ColumnsSubCategoria;
    Glib::RefPtr<Gtk::ListStore> m_refTreeModelSubCategoria;

    //)==================================Producto==================================(


    class ModelCarroVenta : public Gtk::TreeModel::ColumnRecord
    {
    public:
        ModelCarroVenta()
        {
            add(sku);
            add(nombre);
            add(cantidad);
            add(precio_u);
            add(precio_t);
        }

        Gtk::TreeModelColumn<size_t> sku;
        Gtk::TreeModelColumn<size_t> cantidad;
        Gtk::TreeModelColumn<Glib::ustring> nombre;
        Gtk::TreeModelColumn<float> precio_u;
        Gtk::TreeModelColumn<float> precio_t;
    };
    ModelCarroVenta m_Columns_venta;

    Glib::RefPtr<Gtk::ListStore> ModelCarroVenta;

    void carga_señales();
    void init_venta();
    void init_reporte();
    void add_articulo_venta();
    bool add_match_arcticulo(const Gtk::TreeModel::iterator& iter);
    void on_spin_ingreso_changed();
    void on_btn_pago_efectivo_clicked();
    void on_btn_pago_tarjeta_clicked();
    void cierra_dialogo(int response_id);

    Gtk::TreeModel::Row row_venta;

    void on_btn_add_clicked();
    void on_btn_remove_clicked();
    void on_btn_remove_prod_clicked();
    void cierra_venta();
    void init_popover_articulo();
    void add_articulo_venta_popover();
    void add_btn_articulo_venta_popover();
    bool on_spin_ingreso_activate(guint keyval, guint, Gdk::ModifierType state);
    float total_vcarrito = 0.0f;
    bool pag_efectivo = false, pag_tarjeta = false;
    std::stringstream folio_tarjetaa;

    Glib::RefPtr<Gtk::EntryCompletion> completion_pos = Gtk::EntryCompletion::create();

protected:
    Gtk::Box *box_pos;
    Gtk::TreeView *tree_prod;
    Gtk::Label *lbl_precio_total;
    Gtk::HeaderBar header_bar;
    Gtk::StackSwitcher stack_switcher;
    Gtk::Stack *stack_main_pos;
    Gtk::MenuButton menu_button;
    Gtk::Label *lbl_cambio,lbl_articulo_popover;
    Gtk::Popover popover_ingreso_articulos;
    Gtk::SpinButton *spin_ingreso;
    Gtk::Button *btn_pago_efectivo,*btn_pago_tarjeta,btn_add_articulo_popover,*btn_add_piezas;
    Gtk::Entry ety_folio,ety_articulo_popover;
    Gtk::SpinButton spin_cantidad_articulo_popover;


public:
    Pos(/* args */);
    ~Pos() {}
};

#endif // POS_HPP