#pragma once
#include "builder.hpp"
#include <memory>
#include <iostream>

class Bienvenida : public Gtk::Window
{
public:
    Bienvenida();
    ~Bienvenida();
    void run(){
        // window->show();
    };

private:
    std::unique_ptr<Builder> builder = std::make_unique<Builder>();
    void cargar_glade();
    void funciones();

protected:
    Gtk::Button adelante, atras, cancelar, *cancel_info, *salir_info,*btn_catalogo;
    Gtk::HeaderBar header_bar;
    Gtk::Stack *stack_bienvenida;
    Gtk::StackSidebar *stack_sidebar;
    Gtk::Box *box1, *box2, *box3, *box4;
    Gtk::CheckButton *chk_local, *chk_server;
    Gtk::Revealer *revealer_conceccion, *revealer_info;
    Gtk::Entry *ety_user, *ety_host, *ety_port;
    Gtk::PasswordEntry *ety_passwd;
    Gtk::Label *lbl_info;
    Gtk::InfoBar *info_bar;
    Gtk::Popover *pop_consideracion;

    void cerrar();
    void on_file_dialog_response(int , Gtk::FileChooserDialog*);
};

Bienvenida::Bienvenida()
{
    // set_type_hint(Gdk::WINDOW_TYPE_HINT_SPLASHSCREEN);
    adelante.set_label("Adelante");
    atras.set_label("Atras");
    cancelar.set_label("Cancelar");
    header_bar.set_show_title_buttons();
    header_bar.pack_start(atras);
    header_bar.pack_start(cancelar);
    header_bar.pack_end(adelante);
    set_titlebar(header_bar);
    set_title("Bienvenido a NeoPOS");
    set_default_size(800, 600);
    set_deletable(false);
    cargar_glade();
    funciones();
    set_resizable(false);
}

Bienvenida::~Bienvenida()
{
    std::cout << "Bienvenida destroyed" << std::endl;
}

void Bienvenida::cargar_glade()
{
    auto box_ini_bienvenida = builder->m_refBuilder->get_widget<Gtk::Box>("box_ini_bienvenida");
    set_child(*box_ini_bienvenida);
    stack_bienvenida = builder->m_refBuilder->get_widget<Gtk::Stack>("stack_bienvenida");
    stack_sidebar = builder->m_refBuilder->get_widget<Gtk::StackSidebar>("stack_sidebar");
    box1 = builder->m_refBuilder->get_widget<Gtk::Box>("box1");
    box2 = builder->m_refBuilder->get_widget<Gtk::Box>("box2");
    box3 = builder->m_refBuilder->get_widget<Gtk::Box>("box3");
    box4 = builder->m_refBuilder->get_widget<Gtk::Box>("box4");
    btn_catalogo = builder->m_refBuilder->get_widget<Gtk::Button>("btn_catalogo");
    chk_local = builder->m_refBuilder->get_widget<Gtk::CheckButton>("chk_local");
    chk_server = builder->m_refBuilder->get_widget<Gtk::CheckButton>("chk_server");
    revealer_conceccion = builder->m_refBuilder->get_widget<Gtk::Revealer>("revealer_conceccion");
    revealer_info = builder->m_refBuilder->get_widget<Gtk::Revealer>("revealer_info");
    lbl_info = builder->m_refBuilder->get_widget<Gtk::Label>("lbl_info");
    info_bar = builder->m_refBuilder->get_widget<Gtk::InfoBar>("info_bar");
    ety_user = builder->m_refBuilder->get_widget<Gtk::Entry>("ety_user");
    ety_passwd = builder->m_refBuilder->get_widget<Gtk::PasswordEntry>("ety_passwd");
    ety_host = builder->m_refBuilder->get_widget<Gtk::Entry>("ety_host");
    ety_port = builder->m_refBuilder->get_widget<Gtk::Entry>("ety_port");
    pop_consideracion = builder->m_refBuilder->get_widget<Gtk::Popover>("pop_consideracion");

    stack_bienvenida->set_visible_child(*box2);
    stack_bienvenida->set_visible_child(*box1);
    cancel_info = info_bar->add_button("_Cancelar", 0);
    salir_info = info_bar->add_button("_Salir", 1);
}

void Bienvenida::funciones()
{
    adelante.signal_clicked().connect([this]()
                                      {
                                            if(stack_bienvenida->get_visible_child() == box1)
                                                stack_bienvenida->set_visible_child(*box2);
                                            else if(stack_bienvenida->get_visible_child() == box2)
                                                if(chk_server->get_active())
                                                {
                                                    if(chk_server->get_active() && (ety_user->get_text().empty() || ety_passwd->get_text().empty() || ety_host->get_text().empty() || ety_port->get_text().empty()))
                                                    {
                                                        revealer_info->set_reveal_child();
                                                        lbl_info->set_text("Debe llenar todos los campos.");
                                                        info_bar->set_message_type(Gtk::MessageType::INFO);
                                                        cancel_info->hide();
                                                        salir_info->hide();
                                                    }
                                                }else if(chk_server->get_active() && chk_local->get_active()  || !chk_server->get_active() && !chk_local->get_active())
                                                {
                                                    revealer_info->set_reveal_child();
                                                    lbl_info->set_text("Debe seleccionar almenos una opción.");
                                                    info_bar->set_message_type(Gtk::MessageType::INFO);
                                                    cancel_info->hide();
                                                    salir_info->hide();
                                                }else
                                                    stack_bienvenida->set_visible_child(*box3);
                                            else if(stack_bienvenida->get_visible_child() == box3)
                                                stack_bienvenida->set_visible_child(*box4); });

    atras.signal_clicked().connect([this]()
                                   { stack_bienvenida->set_visible_child(*box1); });
    cancelar.signal_clicked().connect([this]()
                                      {
                                        revealer_info->set_reveal_child();
                                        lbl_info->set_text("¿Desea salir de NeoPOS?");
                                        info_bar->set_message_type(Gtk::MessageType::QUESTION);
                                        cancel_info->show();
                                        salir_info->show(); });

    info_bar->signal_response().connect([this](int response_id)
                                        {
                                            if(response_id == 1)
                                                cerrar();
                                            else{
                                                revealer_info->set_reveal_child(false);
                                                cancel_info->hide();
                                                salir_info->hide();
                                            } });

    chk_server->signal_toggled().connect([this]()
                                         {
        if(chk_server->get_active())
            revealer_conceccion->set_reveal_child();
        else
            revealer_conceccion->set_reveal_child(false); });

    btn_catalogo->signal_clicked().connect([this]()
                                           {
                                            auto dialog = new Gtk::FileChooserDialog("Seleccione el archivo de catálogo", Gtk::FileChooser::Action::OPEN, true);
                                            dialog->add_button("_Abrir", Gtk::ResponseType::OK);
                                            dialog->add_button("_Cancelar", Gtk::ResponseType::CANCEL);
                                            dialog->set_transient_for(*this);
                                            dialog->set_modal(true);
                                            dialog->show();

                                            dialog->signal_response().connect(sigc::bind(sigc::mem_fun(*this, &Bienvenida::on_file_dialog_response), dialog));

                                            });
    
}

void Bienvenida::on_file_dialog_response(int response_id, Gtk::FileChooserDialog* dialog)
{
  //Handle the response:
  switch (response_id)
  {
    case Gtk::ResponseType::OK:
    {
      std::cout << "Open clicked." << std::endl;

      //Notice that this is a std::string, not a Glib::ustring.
      auto filename = dialog->get_file()->get_path();
      std::cout << "File selected: " <<  filename << std::endl;

      btn_catalogo->set_label(dialog->get_file()->get_basename());
      break;
    }
    case Gtk::ResponseType::CANCEL:
    {
      std::cout << "Cancel clicked." << std::endl;
      break;
    }
    default:
    {
      std::cout << "Unexpected button clicked." << std::endl;
      break;
    }
  }
  delete dialog;
}


void Bienvenida::cerrar()
{
    hide();
}
