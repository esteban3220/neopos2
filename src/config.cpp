#pragma once

#include "Pos.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>

void Pos::init_config_ticket(){
    std::string xml = "<interface>"
  "<object class='GtkWindow' id='window_conf_ticket'>"
    "<property name='default-height'>400</property>"
    "<property name='title'>Configuracion de Tickets.</property>"
    "<child>"
      "<object class='GtkBox'>"
        "<child>"
          "<object class='GtkScrolledWindow'>"
            "<property name='hexpand'>0</property>"
            "<property name='hscrollbar-policy'>never</property>"
            "<property name='min-content-height'>200</property>"
            "<property name='vexpand'>1</property>"
            "<child>"
              "<object class='GtkViewport'>"
                "<property name='scroll-to-focus'>1</property>"
                "<child>"
                  "<object class='GtkBox'>"
                    "<property name='margin-bottom'>30</property>"
                    "<property name='margin-end'>60</property>"
                    "<property name='margin-start'>60</property>"
                    "<property name='margin-top'>30</property>"
                    "<property name='orientation'>vertical</property>"
                    "<child>"
                      "<object class='GtkLabel'>"
                        "<property name='label'>Visualización</property>"
                        "<property name='margin-bottom'>10</property>"
                        "<property name='xalign'>0</property>"
                        "<style>"
                          "<class name='title-2'/>"
                        "</style>"
                      "</object>"
                    "</child>"
                    "<child>"
                      "<object class='GtkListBox' id='list_config_visualizacion'>"
                        "<property name='selection-mode'>none</property>"
                        "<child>"
                          "<object class='GtkListBoxRow'>"
                            "<child>"
                              "<object class='GtkBox'>"
                                "<child>"
                                  "<object class='GtkLabel' id='switch_label'>"
                                    "<property name='halign'>start</property>"
                                    "<property name='hexpand'>1</property>"
                                    "<property name='label'>Mensaje de Agradecimiento</property>"
                                    "<property name='valign'>center</property>"
                                    "<property name='xalign'>0</property>"
                                  "</object>"
                                "</child>"
                                "<child>"
                                  "<object class='GtkCheckButton' id='check_config_1'>"
                                    "<property name='active'>1</property>"
                                    "<property name='halign'>end</property>"
                                    "<property name='margin-end'>10</property>"
                                    "<property name='margin-start'>10</property>"
                                    "<property name='valign'>center</property>"
                                  "</object>"
                                "</child>"
                              "</object>"
                            "</child>"
                          "</object>"
                        "</child>"
                        "<child>"
                          "<object class='GtkListBoxRow'>"
                            "<child>"
                              "<object class='GtkBox'>"
                                "<child>"
                                  "<object class='GtkLabel' id='check_label'>"
                                    "<property name='halign'>start</property>"
                                    "<property name='hexpand'>1</property>"
                                    "<property name='label'>Fecha</property>"
                                    "<property name='valign'>center</property>"
                                    "<property name='xalign'>0</property>"
                                  "</object>"
                                "</child>"
                                "<child>"
                                  "<object class='GtkCheckButton' id='check_config_2'>"
                                    "<property name='active'>1</property>"
                                    "<property name='halign'>end</property>"
                                    "<property name='margin-end'>10</property>"
                                    "<property name='margin-start'>10</property>"
                                    "<property name='valign'>center</property>"
                                  "</object>"
                                "</child>"
                              "</object>"
                            "</child>"
                          "</object>"
                        "</child>"
                        "<child>"
                          "<object class='GtkListBoxRow'>"
                            "<child>"
                              "<object class='GtkBox'>"
                                "<child>"
                                  "<object class='GtkLabel' id='check_label_2'>"
                                    "<property name='halign'>start</property>"
                                    "<property name='hexpand'>1</property>"
                                    "<property name='label'>Direccion</property>"
                                    "<property name='valign'>center</property>"
                                    "<property name='xalign'>0</property>"
                                  "</object>"
                                "</child>"
                                "<child>"
                                  "<object class='GtkCheckButton' id='check_config_3'>"
                                    "<property name='active'>1</property>"
                                    "<property name='halign'>end</property>"
                                    "<property name='margin-end'>10</property>"
                                    "<property name='margin-start'>10</property>"
                                    "<property name='valign'>center</property>"
                                  "</object>"
                                "</child>"
                              "</object>"
                            "</child>"
                          "</object>"
                        "</child>"
                        "<child>"
                          "<object class='GtkListBoxRow'>"
                            "<child>"
                              "<object class='GtkBox'>"
                                "<child>"
                                  "<object class='GtkLabel' id='check_label_3'>"
                                    "<property name='halign'>start</property>"
                                    "<property name='hexpand'>1</property>"
                                    "<property name='label'>RFC</property>"
                                    "<property name='valign'>center</property>"
                                    "<property name='xalign'>0</property>"
                                  "</object>"
                                "</child>"
                                "<child>"
                                  "<object class='GtkCheckButton' id='check_config_4'>"
                                    "<property name='active'>1</property>"
                                    "<property name='halign'>end</property>"
                                    "<property name='margin-end'>10</property>"
                                    "<property name='margin-start'>10</property>"
                                    "<property name='valign'>center</property>"
                                  "</object>"
                                "</child>"
                              "</object>"
                            "</child>"
                          "</object>"
                        "</child>"
                        "<child>"
                          "<object class='GtkListBoxRow'>"
                            "<child>"
                              "<object class='GtkBox'>"
                                "<child>"
                                  "<object class='GtkLabel' id='check_label_4'>"
                                    "<property name='halign'>start</property>"
                                    "<property name='hexpand'>1</property>"
                                    "<property name='label'>Vendedor</property>"
                                    "<property name='valign'>center</property>"
                                    "<property name='xalign'>0</property>"
                                  "</object>"
                                "</child>"
                                "<child>"
                                  "<object class='GtkCheckButton' id='check_config_5'>"
                                    "<property name='active'>1</property>"
                                    "<property name='halign'>end</property>"
                                    "<property name='margin-end'>10</property>"
                                    "<property name='margin-start'>10</property>"
                                    "<property name='valign'>center</property>"
                                  "</object>"
                                "</child>"
                              "</object>"
                            "</child>"
                          "</object>"
                        "</child>"
                        "<child>"
                          "<object class='GtkListBoxRow'>"
                            "<child>"
                              "<object class='GtkBox'>"
                                "<child>"
                                  "<object class='GtkLabel' id='check_label_5'>"
                                    "<property name='halign'>start</property>"
                                    "<property name='hexpand'>1</property>"
                                    "<property name='label'>Contacto</property>"
                                    "<property name='valign'>center</property>"
                                    "<property name='xalign'>0</property>"
                                  "</object>"
                                "</child>"
                                "<child>"
                                  "<object class='GtkCheckButton' id='check_config_6'>"
                                    "<property name='active'>1</property>"
                                    "<property name='halign'>end</property>"
                                    "<property name='margin-end'>10</property>"
                                    "<property name='margin-start'>10</property>"
                                    "<property name='valign'>center</property>"
                                  "</object>"
                                "</child>"
                              "</object>"
                            "</child>"
                          "</object>"
                        "</child>"
                        "<style>"
                          "<class name='rich-list'/>"
                          "<class name='boxed-list'/>"
                        "</style>"
                      "</object>"
                    "</child>"
                    "<child>"
                      "<object class='GtkLabel'>"
                        "<property name='label'>Datos</property>"
                        "<property name='margin-bottom'>10</property>"
                        "<property name='margin-top'>30</property>"
                        "<property name='xalign'>0</property>"
                        "<style>"
                          "<class name='title-2'/>"
                        "</style>"
                      "</object>"
                    "</child>"
                    "<child>"
                      "<object class='GtkListBox' id='list_config_datos'>"
                        "<property name='selection-mode'>none</property>"
                        "<child>"
                          "<object class='GtkListBoxRow'>"
                            "<property name='activatable'>0</property>"
                            "<child>"
                              "<object class='GtkBox'>"
                                "<child>"
                                  "<object class='GtkLabel' id='entry_label_7'>"
                                    "<property name='halign'>start</property>"
                                    "<property name='hexpand'>1</property>"
                                    "<property name='label'>Razón social</property>"
                                    "<property name='valign'>center</property>"
                                    "<property name='xalign'>0</property>"
                                  "</object>"
                                "</child>"
                                "<child>"
                                  "<object class='GtkEntry' id='ety_conf_razon'>"
                                    "<property name='halign'>end</property>"
                                    "<property name='placeholder-text'>Type here…</property>"
                                    "<property name='valign'>center</property>"
                                  "</object>"
                                "</child>"
                              "</object>"
                            "</child>"
                          "</object>"
                        "</child>"
                        "<child>"
                          "<object class='GtkListBoxRow'>"
                            "<property name='activatable'>0</property>"
                            "<child>"
                              "<object class='GtkBox'>"
                                "<child>"
                                  "<object class='GtkLabel' id='entry_label_3'>"
                                    "<property name='halign'>start</property>"
                                    "<property name='hexpand'>True</property>"
                                    "<property name='label'>Direccion</property>"
                                    "<property name='valign'>center</property>"
                                    "<property name='xalign'>0</property>"
                                  "</object>"
                                "</child>"
                                "<child>"
                                  "<object class='GtkEntry' id='ety_conf_direccion'>"
                                    "<property name='halign'>end</property>"
                                    "<property name='placeholder-text'>Type here…</property>"
                                    "<property name='valign'>center</property>"
                                  "</object>"
                                "</child>"
                              "</object>"
                            "</child>"
                          "</object>"
                        "</child>"
                        "<child>"
                          "<object class='GtkListBoxRow'>"
                            "<property name='activatable'>0</property>"
                            "<child>"
                              "<object class='GtkBox'>"
                                "<child>"
                                  "<object class='GtkLabel' id='entry_label'>"
                                    "<property name='halign'>start</property>"
                                    "<property name='label'>RFC</property>"
                                    "<property name='valign'>center</property>"
                                    "<property name='xalign'>0</property>"
                                  "</object>"
                                "</child>"
                                "<child>"
                                  "<object class='GtkEntry' id='ety_conf_rfc'>"
                                    "<property name='halign'>end</property>"
                                    "<property name='hexpand'>True</property>"
                                    "<property name='placeholder-text'>Type here…</property>"
                                    "<property name='valign'>center</property>"
                                  "</object>"
                                "</child>"
                              "</object>"
                            "</child>"
                          "</object>"
                        "</child>"
                        "<child>"
                          "<object class='GtkListBoxRow'>"
                            "<property name='activatable'>0</property>"
                            "<child>"
                              "<object class='GtkBox'>"
                                "<child>"
                                  "<object class='GtkLabel' id='entry_label_4'>"
                                    "<property name='halign'>start</property>"
                                    "<property name='hexpand'>1</property>"
                                    "<property name='label'>Contacto</property>"
                                    "<property name='valign'>center</property>"
                                    "<property name='xalign'>0</property>"
                                  "</object>"
                                "</child>"
                                "<child>"
                                  "<object class='GtkEntry' id='ety_conf_contacto'>"
                                    "<property name='halign'>end</property>"
                                    "<property name='placeholder-text'>Type here…</property>"
                                    "<property name='valign'>center</property>"
                                  "</object>"
                                "</child>"
                              "</object>"
                            "</child>"
                          "</object>"
                        "</child>"
                        "<child>"
                          "<object class='GtkListBoxRow'>"
                            "<property name='activatable'>0</property>"
                            "<child>"
                              "<object class='GtkBox'>"
                                "<child>"
                                  "<object class='GtkLabel' id='entry_label_5'>"
                                    "<property name='halign'>start</property>"
                                    "<property name='hexpand'>1</property>"
                                    "<property name='label'>Agradecimiento</property>"
                                    "<property name='valign'>center</property>"
                                    "<property name='xalign'>0</property>"
                                  "</object>"
                                "</child>"
                                "<child>"
                                  "<object class='GtkEntry' id='ety_conf_thanks'>"
                                    "<property name='halign'>end</property>"
                                    "<property name='placeholder-text'>Type here…</property>"
                                    "<property name='valign'>center</property>"
                                  "</object>"
                                "</child>"
                              "</object>"
                            "</child>"
                          "</object>"
                        "</child>"
                        "<style>"
                          "<class name='rich-list'/>"
                          "<class name='boxed-list'/>"
                        "</style>"
                      "</object>"
                    "</child>"
                    "<child>"
                      "<object class='GtkLabel'>"
                        "<property name='label'>Test</property>"
                        "<property name='margin-bottom'>10</property>"
                        "<property name='margin-top'>30</property>"
                        "<property name='xalign'>0</property>"
                        "<style>"
                          "<class name='title-2'/>"
                        "</style>"
                      "</object>"
                    "</child>"
                    "<child>"
                      "<object class='GtkListBox' id='list_config_test'>"
                        "<property name='selection-mode'>none</property>"
                        "<child>"
                          "<object class='GtkListBoxRow'>"
                            "<child>"
                              "<object class='GtkBox'>"
                                "<child>"
                                  "<object class='GtkLabel' id='entry_label_8'>"
                                    "<property name='halign'>start</property>"
                                    "<property name='hexpand'>True</property>"
                                    "<property name='label'>Impresion de Prueba</property>"
                                    "<property name='valign'>center</property>"
                                    "<property name='xalign'>0</property>"
                                  "</object>"
                                "</child>"
                                "<child>"
                                  "<object class='GtkImage'>"
                                    "<property name='halign'>end</property>"
                                    "<property name='icon-name'>printer-symbolic</property>"
                                  "</object>"
                                "</child>"
                              "</object>"
                            "</child>"
                          "</object>"
                        "</child>"
                        "<style>"
                          "<class name='rich-list'/>"
                          "<class name='boxed-list'/>"
                        "</style>"
                      "</object>"
                    "</child>"
                  "</object>"
                "</child>"
              "</object>"
            "</child>"
          "</object>"
        "</child>"
        "<child>"
          "<object class='GtkScrolledWindow'>"
            "<property name='hexpand'>True</property>"
            "<property name='margin-bottom'>20</property>"
            "<property name='margin-end'>10</property>"
            "<property name='margin-start'>30</property>"
            "<property name='margin-top'>20</property>"
            "<child>"
              "<object class='GtkTextView' id='text_ticket'>"
                "<property name='editable'>False</property>"
                "<property name='monospace'>True</property>"
              "</object>"
            "</child>"
          "</object>"
        "</child>"
      "</object>"
    "</child>"
  "</object>"
  "<object class='GtkSizeGroup'>"
    "<property name='mode'>horizontal</property>"
    "<widgets>"
      "<widget name='switch_label'/>"
      "<widget name='check_label'/>"
      "<widget name='entry_label'/>"
    "</widgets>"
  "</object>"
"</interface>" ;

    auto  builder_config_ticket_ = Gtk::Builder::create();
    try
  {
    builder_config_ticket_->add_from_string(xml);
  }catch(const Glib::Error& ex)
  {
    std::cerr << "building toolbar failed: " << ex.what();
  }
    window_conf_ticket = builder_config_ticket_->get_widget<Gtk::Window>("window_conf_ticket");
    list_config_visualizacion = builder_config_ticket_->get_widget<Gtk::ListBox>("list_config_visualizacion");
    list_config_datos = builder_config_ticket_->get_widget<Gtk::ListBox>("list_config_datos");
    list_config_test = builder_config_ticket_->get_widget<Gtk::ListBox>("list_config_test");
    text_ticket = builder_config_ticket_->get_widget<Gtk::TextView>("text_ticket");

    ety_conf_razon = builder_config_ticket_->get_widget<Gtk::Entry>("ety_conf_razon");
    ety_conf_rfc = builder_config_ticket_->get_widget<Gtk::Entry>("ety_conf_rfc");
    ety_conf_direccion = builder_config_ticket_->get_widget<Gtk::Entry>("ety_conf_direccion");
    ety_conf_contacto = builder_config_ticket_->get_widget<Gtk::Entry>("ety_conf_contacto");
    ety_conf_thanks = builder_config_ticket_->get_widget<Gtk::Entry>("ety_conf_thanks");

    for (int i = 0; i < 6; i++)
    {
        vec_check[i] = builder_config_ticket_->get_widget<Gtk::CheckButton>("check_config_"+std::to_string(i+1));
    }
    for (int i = 0; i < 6; i++)
    {
        vec_check[i]->signal_toggled().connect(sigc::mem_fun(*this,&Pos::edit_ticket));
    }

    ety_conf_razon->signal_changed().connect(sigc::mem_fun(*this,&Pos::edit_ticket));
    ety_conf_rfc->signal_changed().connect(sigc::mem_fun(*this,&Pos::edit_ticket));
    ety_conf_direccion->signal_changed().connect(sigc::mem_fun(*this,&Pos::edit_ticket));
    ety_conf_contacto->signal_changed().connect(sigc::mem_fun(*this,&Pos::edit_ticket));
    ety_conf_thanks->signal_changed().connect(sigc::mem_fun(*this,&Pos::edit_ticket));

    window_conf_ticket->set_transient_for(*this);
    window_conf_ticket->set_modal(true);
    window_conf_ticket->set_hide_on_close(true);
    window_conf_ticket->set_default_size(900, 500);
    window_conf_ticket->set_resizable(false);

    m_refTextBuffer1->set_text(" ***************** TICKET DE COMPRA ****************\n"
                               " ---------------------------------------------------\n"
                               " Articulo de prueba          10         6        60\n"
                               " ---------------------------------------------------\n"
                               " Total:                                       60.00\n"
                               " Tipo de Pago:                             Efectivo\n"
                               " ---------------------------------------------------\n"
                               " Ingreso:                                     90.00\n"
                               " Cambio:                                      30.00\n"
                               " ---------------------------------------------------\n"
                               " Folio Tarjeta:                                    \n"
                               " ---------------------------------------------------\n"
                               " Fecha:                         2023-07-13 14:45:50\n"
                               " No. Ticket:                                      5\n"
                               " ---------------------------------------------------\n"
                               " ************** Gracias por su compra **************\n");

    text_ticket->set_buffer(m_refTextBuffer1);
    list_config_test->signal_row_activated().connect([this](Gtk::ListBoxRow* row){ 

      std::ofstream archivoTemp("tempo.txt");
        archivoTemp << ticket_config.str();
        archivoTemp.close();

        std::system("lp tempo.txt");
        remove("tempo.txt");

      });
    list_config_visualizacion->signal_row_activated().connect([this](Gtk::ListBoxRow* row){ 

      if(vec_check[row->get_index()]->get_active())
         vec_check[row->get_index()]->set_active(false);
      else
         vec_check[row->get_index()]->set_active(true);
         edit_ticket();
      });
}

void Pos::edit_ticket(){
  //razon_social = "Razon Social";
  //direccion = "Direccion";
  //rfc = "RFC";
  ticket_config.str("");
  ticket_config.clear();

  ticket_config << " ***************** TICKET DE COMPRA ****************\n"
         << " ---------------------------------------------------\n\n"
         << std::left << std::setw(20) << ety_conf_razon->get_text() << "\n";

  if(vec_check[2]->get_active())
  {
    ticket_config << std::left << std::setw(20) << "Dirección: " << ety_conf_direccion->get_text() << "\n"
    << " ---------------------------------------------------\n";
  }
  
  if(vec_check[3]->get_active())
  {
    ticket_config << std::left << std::setw(20) << "RFC: " << ety_conf_rfc->get_text() << "\n"
    << " ---------------------------------------------------\n";
  }
  if(vec_check[1]->get_active())
  ticket_config << std::left << std::setw(20) << "Fecha: " << Glib::DateTime::create_now_local().format("%Y-%m-%d %H:%M:%S") << "\n";
  ticket_config << std::left << std::setw(20) << "No. Ticket: 0001"  << "\n";
  if(vec_check[4]->get_active())       
  ticket_config << std::left << std::setw(20) << "Le atendió: " << "Juan Perez" << "\n\n"
         << " ---------------------------------------------------\n";
  ticket_config << std::left << std::setw(20) << "Articulo" << std::setw(10) << "Cantidad" << std::setw(10) << "Precio" << std::setw(10) << "Total" << "\n"
         << " ---------------------------------------------------\n";
  ticket_config << std::left << std::setw(20) << "Articulo de prueba" << std::setw(10) << "10" << std::setw(10) << "6" << std::setw(10) << "60" << "\n"
         << " ---------------------------------------------------\n";
  ticket_config << std::left << std::setw(20) << "Total:" << std::setw(40) << "60.00" << "\n";
  ticket_config << std::left << std::setw(20) << "Tipo de Pago:" << std::setw(40) << "Efectivo" << "\n"
         << " ---------------------------------------------------\n";
  ticket_config << std::left << std::setw(20) << "Ingreso:" << std::setw(40) << "90.00" << "\n";
  ticket_config << std::left << std::setw(20) << "Cambio:" << std::setw(40) << "30.00" << "\n"
         << " ---------------------------------------------------\n";
  if(vec_check[5]->get_active())
  ticket_config << std::left << std::setw(20) << "** "<< ety_conf_contacto->get_text() <<"**" << "\n"
         << " ---------------------------------------------------\n";
  if(vec_check[0]->get_active())   
  ticket_config << std::left << std::setw(20) << "** "<< ety_conf_thanks->get_text() <<"**" << "\n"
         << " ---------------------------------------------------\n";

  std::cout << ticket_config.str() << std::endl;
  m_refTextBuffer1->set_text(ticket_config.str());

}