#ifndef POS_HPP
#define POS_HPP 
#include "builder.hpp"
#include <memory>
#include <iostream>

class Pos : public Gtk::Window
{
private:
    /* data */
    std::unique_ptr<Builder> builder = std::make_unique<Builder>("../test/mainpos.ui");
    void cargar_glade();
    void init();
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

        Gtk::TreeModelColumn<unsigned int> id;
        Gtk::TreeModelColumn<Glib::ustring> m_col_name;
        Gtk::TreeModelColumn<Glib::ustring> empresa;
        Gtk::TreeModelColumn<unsigned> numero;
        Gtk::TreeModelColumn<Glib::ustring> correo;
    };
    ModelColumns m_Columns;
    Glib::RefPtr<Gtk::ListStore> m_refTreeModel;

    Gtk::TreeView *tree_prov;
    Gtk::Label *lbl_cont_prod;
    Gtk::Button *btn_add, *btn_remove, *btn_edit;


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