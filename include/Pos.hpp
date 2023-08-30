#pragma once

#include "builder.hpp"
#include <memory>
#include <iostream>
#include <map>
#include <vector>
#include "sqlite.hpp"
#include <sstream>
#include <map>

class Pos : public Gtk::Window
{
private:
    /* data */
    std::unique_ptr<Builder> builder ;
    void cargar_glade();
    void init();
    void init_producto();
    void init_config_ticket();
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

    Gtk::TreeView *tree_prov, *tree_venta, *tree_repor, *tree_detalle_venta;
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
            add(granel);
            add(categoria);
            add(subcategoria);
        }

        Gtk::TreeModelColumn<long long> sku;
        Gtk::TreeModelColumn<Glib::ustring> nombre;
        Gtk::TreeModelColumn<Glib::ustring> caducidad;
        Gtk::TreeModelColumn<Glib::ustring> marca;
        Gtk::TreeModelColumn<Glib::ustring> nota;
        Gtk::TreeModelColumn<Glib::ustring> piezas;
        Gtk::TreeModelColumn<float> precio_u;
        Gtk::TreeModelColumn<bool> granel;
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
    Gtk::CellRendererToggle *cell_granel = Gtk::manage(new Gtk::CellRendererToggle());
    Gtk::CellRendererCombo *cell_categoria = Gtk::make_managed<Gtk::CellRendererCombo>();
    Gtk::CellRendererCombo *cell_subcategoria = Gtk::make_managed<Gtk::CellRendererCombo>();

    Gtk::TreeViewColumn *col_sku = nullptr;
    Gtk::TreeViewColumn *col_nombre = nullptr;
    Gtk::TreeViewColumn *col_caducidad = nullptr;
    Gtk::TreeViewColumn *col_marca = nullptr;
    Gtk::TreeViewColumn *col_nota = nullptr;
    Gtk::TreeViewColumn *col_piezas = nullptr;
    Gtk::TreeViewColumn *col_precio_u = nullptr;
    Gtk::TreeViewColumn *col_granel = nullptr;
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
        Gtk::TreeModelColumn<float> cantidad;
        Gtk::TreeModelColumn<Glib::ustring> nombre;
        Gtk::TreeModelColumn<float> precio_u;
        Gtk::TreeModelColumn<float> precio_t;
    };
    ModelCarroVenta m_Columns_venta;

    Glib::RefPtr<Gtk::ListStore> ModelCarroVenta;

    //)==================================Venta==================================(
    class ModelDetalleVenta : public Gtk::TreeModel::ColumnRecord
    {
    public:
        ModelDetalleVenta()
        {
            add(sku);
            add(nombre);
            add(cantidad);
            add(precio_u);
            add(precio_t);
        }

        Gtk::TreeModelColumn<size_t> sku;
        Gtk::TreeModelColumn<float> cantidad;
        Gtk::TreeModelColumn<Glib::ustring> nombre;
        Gtk::TreeModelColumn<float> precio_u;
        Gtk::TreeModelColumn<float> precio_t;
    };
    ModelDetalleVenta m_Columns_detalle_venta;

    Glib::RefPtr<Gtk::ListStore> Modeldetalle_venta;

    void carga_señales();
    void init_venta();
    void init_reporte();
    void init_detalle_venta();
    void add_articulo_venta();
    bool add_match_arcticulo(const Gtk::TreeModel::iterator &iter);
    bool add_match_producto(const Gtk::TreeModel::iterator &iter);
    bool on_window_conf_ticket_delete_event();
    void on_spin_ingreso_changed();
    void on_btn_pago_efectivo_clicked();
    void on_btn_pago_tarjeta_clicked();
    void cierra_dialogo(int response_id);

    Gtk::TreeModel::Row row_venta, row_detalle_venta;
    std::stringstream ticket_config;

    void on_btn_add_clicked();
    void on_btn_remove_clicked();
    void on_btn_remove_prod_clicked();
    void cierra_venta();
    void initconf();
    void init_popover_articulo();
    void add_articulo_venta_popover();
    void add_btn_articulo_venta_popover();
    bool on_spin_ingreso_activate(guint keyval, guint, Gdk::ModifierType state);
    void on_tree_detalle_venta_row_activated(const Gtk::TreeModel::Path &path, Gtk::TreeViewColumn *column);
    float total_vcarrito = 0.0f;
    bool pag_efectivo = false, pag_tarjeta = false;
    std::stringstream folio_tarjetaa;
    Glib::RefPtr<Gtk::GestureClick> refGesture = Gtk::GestureClick::create();

    void on_popup_button_pressed(int n_press, double x, double y);
    void on_menu_file_popup_generic();
    void act_dashboard();
    void edit_ticket();
    void on_ety_barras_icon_press(Gtk::Entry::IconPosition icon_position);

    Glib::RefPtr<Gtk::EntryCompletion> completion_pos = Gtk::EntryCompletion::create();
    Glib::RefPtr<Gtk::EntryCompletion> completion_producto = Gtk::EntryCompletion::create();
    Glib::RefPtr<Gio::SimpleAction> impresion_act;
    Glib::RefPtr<Gtk::TextBuffer> m_refTextBuffer1 = Gtk::TextBuffer::create();

    std::string razon_social,direccion,rfc,contacto,regreats;

protected:
    Gtk::Window *window_conf_ticket;
    Gtk::Box *box_pos;
    Gtk::TreeView *tree_prod;
    Gtk::Label *lbl_precio_total;
    Gtk::HeaderBar header_bar;
    Gtk::StackSwitcher stack_switcher;
    Gtk::Stack *stack_main_pos;
    Gtk::MenuButton menu_button;
    Gtk::Label *lbl_cambio, lbl_articulo_popover;
    Gtk::Label *lbl_venta_dia,*lbl_clientes_dia,*lbl_venta_mes,*lbl_venta_min_mes,*lbl_venta_max_mes,*lbl_venta_anio,*lbl_venta_min_anio,*lbl_venta_max_anio,*lbl_venta_anio_anterior;
    Gtk::Popover popover_ingreso_articulos,popover_cantidad_articulo,popover_precio_articulo;
    Gtk::PopoverMenu m_MenuPopup;
    Gtk::SpinButton *spin_ingreso;
    Gtk::Button *btn_pago_efectivo, *btn_pago_tarjeta, btn_add_articulo_popover, *btn_add_piezas;
    Gtk::Entry ety_folio, ety_articulo_popover;
    Gtk::SpinButton spin_cantidad_articulo_popover;
    Gtk::SpinButton spin_cantiad_point, spin_precio_piezas,spin_precio_articulo;
    Gtk::PopoverMenu m_MenuPopup_main;
    Gtk::TextView *text_ticket;
    Gtk::ListBox *list_config_visualizacion,*list_config_datos,*list_config_test;
    Gtk::Entry *ety_conf_razon,*ety_conf_direccion,*ety_conf_rfc,*ety_conf_contacto,*ety_conf_thanks;

    Gtk::CheckButton *check_config_1,*check_config_2,*check_config_3,*check_config_4,*check_config_5,*check_config_6;

    std::map<short,Gtk::CheckButton*> vec_check{{0,check_config_1},{1,check_config_2},{2,check_config_3},{3,check_config_4},{4,check_config_5},{5,check_config_6}};

public:
    Pos(const Glib::RefPtr<Gtk::Application>& app);
    ~Pos() {m_MenuPopup.unparent(); m_MenuPopup_main.unparent(); popover_ingreso_articulos.unparent(); popover_precio_articulo.unparent(); popover_cantidad_articulo.unparent();}
};
