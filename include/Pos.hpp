#include "builder.hpp"
#include <memory>
#include <iostream>

class Pos : public Gtk::Window
{
private:
    /* data */
    std::unique_ptr<Builder> builder = std::make_unique<Builder>("../test/mainpos.ui");
    void cargar_glade();


protected:
    Gtk::Box *box_pos;
    Gtk::Label *lbl_precio_total;
    Gtk::HeaderBar header_bar;
    Gtk::StackSwitcher stack_switcher;
    Gtk::Stack *stack_main_pos;
    Gtk::MenuButton menu_button;

public:
    Pos(/* args */)
    {
        cargar_glade();
        set_title("POS");
        set_default_size(800, 600);
        set_titlebar(header_bar);
        header_bar.pack_start(menu_button);
        header_bar.set_title_widget(stack_switcher);
    }
    ~Pos() {}

};

void Pos::cargar_glade()
{
    box_pos = builder->m_refBuilder->get_widget<Gtk::Box>("box_pos");
    stack_main_pos = builder->m_refBuilder->get_widget<Gtk::Stack>("stack_main_pos");
    auto stack_debug = builder->m_refBuilder->get_widget<Gtk::StackSwitcher>("stack_debug");
    stack_debug->hide();

    lbl_precio_total = builder->m_refBuilder->get_widget<Gtk::Label>("lbl_precio_total");
    set_child(*box_pos);

    lbl_precio_total->set_markup("<span font_desc='50'>$0.00</span>");
    stack_switcher.set_stack(*stack_main_pos);
    stack_switcher.set_child_visible(true);
}