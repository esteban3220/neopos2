#pragma once

#include "Pos.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>

void
Pos::init_config_ticket ()
{
  std::string xml = "<interface>"
          "<object class=\"GtkWindow\" id=\"window_conf_ticket\">"
            "<property name=\"default-height\">400</property>"
            "<property name=\"title\">Configuracion de Tickets.</property>"
            "<child>"
              "<object class=\"GtkBox\">"
                "<child>"
                  "<object class=\"GtkScrolledWindow\">"
                    "<property name=\"hexpand\">0</property>"
                    "<property name=\"hscrollbar-policy\">never</property>"
                    "<property name=\"min-content-height\">200</property>"
                    "<property name=\"vexpand\">1</property>"
                    "<child>"
                      "<object class=\"GtkViewport\">"
                        "<property name=\"scroll-to-focus\">1</property>"
                        "<child>"
                          "<object class=\"GtkBox\">"
                            "<property name=\"margin-bottom\">30</property>"
                            "<property name=\"margin-end\">60</property>"
                            "<property name=\"margin-start\">60</property>"
                            "<property name=\"margin-top\">30</property>"
                            "<property name=\"orientation\">vertical</property>"
                            "<child>"
                              "<object class=\"GtkLabel\">"
                                "<property name=\"label\">Visualización</property>"
                                "<property name=\"margin-bottom\">10</property>"
                                "<property name=\"xalign\">0</property>"
                                "<style>"
                                  "<class name=\"title-2\"/>"
                                "</style>"
                              "</object>"
                            "</child>"
                            "<child>"
                              "<object class=\"GtkListBox\" id=\"list_config_visualizacion\">"
                                "<property name=\"selection-mode\">none</property>"
                                "<child>"
                                  "<object class=\"GtkListBoxRow\">"
                                    "<child>"
                                      "<object class=\"GtkBox\">"
                                        "<child>"
                                          "<object class=\"GtkLabel\" id=\"switch_label\">"
                                            "<property name=\"halign\">start</property>"
                                            "<property name=\"hexpand\">1</property>"
                                            "<property name=\"label\">Mensaje de Agradecimiento</property>"
                                            "<property name=\"valign\">center</property>"
                                            "<property name=\"xalign\">0</property>"
                                          "</object>"
                                        "</child>"
                                        "<child>"
                                          "<object class=\"GtkCheckButton\" id=\"check_config_1\">"
                                            "<property name=\"active\">1</property>"
                                            "<property name=\"halign\">end</property>"
                                            "<property name=\"margin-end\">10</property>"
                                            "<property name=\"margin-start\">10</property>"
                                            "<property name=\"valign\">center</property>"
                                          "</object>"
                                        "</child>"
                                      "</object>"
                                    "</child>"
                                  "</object>"
                                "</child>"
                                "<child>"
                                  "<object class=\"GtkListBoxRow\">"
                                    "<child>"
                                      "<object class=\"GtkBox\">"
                                        "<child>"
                                          "<object class=\"GtkLabel\" id=\"check_label\">"
                                            "<property name=\"halign\">start</property>"
                                            "<property name=\"hexpand\">1</property>"
                                            "<property name=\"label\">Fecha</property>"
                                            "<property name=\"valign\">center</property>"
                                            "<property name=\"xalign\">0</property>"
                                          "</object>"
                                        "</child>"
                                        "<child>"
                                          "<object class=\"GtkCheckButton\" id=\"check_config_2\">"
                                            "<property name=\"active\">1</property>"
                                            "<property name=\"halign\">end</property>"
                                            "<property name=\"margin-end\">10</property>"
                                            "<property name=\"margin-start\">10</property>"
                                            "<property name=\"valign\">center</property>"
                                          "</object>"
                                        "</child>"
                                      "</object>"
                                    "</child>"
                                  "</object>"
                                "</child>"
                                "<child>"
                                  "<object class=\"GtkListBoxRow\">"
                                    "<child>"
                                      "<object class=\"GtkBox\">"
                                        "<child>"
                                          "<object class=\"GtkLabel\" id=\"check_label_2\">"
                                            "<property name=\"halign\">start</property>"
                                            "<property name=\"hexpand\">1</property>"
                                            "<property name=\"label\">Direccion</property>"
                                            "<property name=\"valign\">center</property>"
                                            "<property name=\"xalign\">0</property>"
                                          "</object>"
                                        "</child>"
                                        "<child>"
                                          "<object class=\"GtkCheckButton\" id=\"check_config_3\">"
                                            "<property name=\"active\">1</property>"
                                            "<property name=\"halign\">end</property>"
                                            "<property name=\"margin-end\">10</property>"
                                            "<property name=\"margin-start\">10</property>"
                                            "<property name=\"valign\">center</property>"
                                          "</object>"
                                        "</child>"
                                      "</object>"
                                    "</child>"
                                  "</object>"
                                "</child>"
                                "<child>"
                                  "<object class=\"GtkListBoxRow\">"
                                    "<child>"
                                      "<object class=\"GtkBox\">"
                                        "<child>"
                                          "<object class=\"GtkLabel\" id=\"check_label_3\">"
                                            "<property name=\"halign\">start</property>"
                                            "<property name=\"hexpand\">1</property>"
                                            "<property name=\"label\">RFC</property>"
                                            "<property name=\"valign\">center</property>"
                                            "<property name=\"xalign\">0</property>"
                                          "</object>"
                                        "</child>"
                                        "<child>"
                                          "<object class=\"GtkCheckButton\" id=\"check_config_4\">"
                                            "<property name=\"active\">1</property>"
                                            "<property name=\"halign\">end</property>"
                                            "<property name=\"margin-end\">10</property>"
                                            "<property name=\"margin-start\">10</property>"
                                            "<property name=\"valign\">center</property>"
                                          "</object>"
                                        "</child>"
                                      "</object>"
                                    "</child>"
                                  "</object>"
                                "</child>"
                                "<child>"
                                  "<object class=\"GtkListBoxRow\">"
                                    "<child>"
                                      "<object class=\"GtkBox\">"
                                        "<child>"
                                          "<object class=\"GtkLabel\" id=\"check_label_4\">"
                                            "<property name=\"halign\">start</property>"
                                            "<property name=\"hexpand\">1</property>"
                                            "<property name=\"label\">Vendedor</property>"
                                            "<property name=\"valign\">center</property>"
                                            "<property name=\"xalign\">0</property>"
                                          "</object>"
                                        "</child>"
                                        "<child>"
                                          "<object class=\"GtkCheckButton\" id=\"check_config_5\">"
                                            "<property name=\"active\">1</property>"
                                            "<property name=\"halign\">end</property>"
                                            "<property name=\"margin-end\">10</property>"
                                            "<property name=\"margin-start\">10</property>"
                                            "<property name=\"valign\">center</property>"
                                          "</object>"
                                        "</child>"
                                      "</object>"
                                    "</child>"
                                  "</object>"
                                "</child>"
                                "<child>"
                                  "<object class=\"GtkListBoxRow\">"
                                    "<child>"
                                      "<object class=\"GtkBox\">"
                                        "<child>"
                                          "<object class=\"GtkLabel\" id=\"check_label_5\">"
                                            "<property name=\"halign\">start</property>"
                                            "<property name=\"hexpand\">1</property>"
                                            "<property name=\"label\">Contacto</property>"
                                            "<property name=\"valign\">center</property>"
                                            "<property name=\"xalign\">0</property>"
                                          "</object>"
                                        "</child>"
                                        "<child>"
                                          "<object class=\"GtkCheckButton\" id=\"check_config_6\">"
                                            "<property name=\"active\">1</property>"
                                            "<property name=\"halign\">end</property>"
                                            "<property name=\"margin-end\">10</property>"
                                            "<property name=\"margin-start\">10</property>"
                                            "<property name=\"valign\">center</property>"
                                          "</object>"
                                        "</child>"
                                      "</object>"
                                    "</child>"
                                  "</object>"
                                "</child>"
                                "<style>"
                                  "<class name=\"rich-list\"/>"
                                  "<class name=\"boxed-list\"/>"
                                "</style>"
                              "</object>"
                            "</child>"
                            "<child>"
                              "<object class=\"GtkLabel\">"
                                "<property name=\"label\">Datos</property>"
                                "<property name=\"margin-bottom\">10</property>"
                                "<property name=\"margin-top\">30</property>"
                                "<property name=\"xalign\">0</property>"
                                "<style>"
                                  "<class name=\"title-2\"/>"
                                "</style>"
                              "</object>"
                            "</child>"
                            "<child>"
                              "<object class=\"GtkListBox\" id=\"list_config_datos\">"
                                "<property name=\"selection-mode\">none</property>"
                                "<child>"
                                  "<object class=\"GtkListBoxRow\">"
                                    "<property name=\"activatable\">0</property>"
                                    "<child>"
                                      "<object class=\"GtkBox\">"
                                        "<child>"
                                          "<object class=\"GtkLabel\" id=\"entry_label_7\">"
                                            "<property name=\"halign\">start</property>"
                                            "<property name=\"hexpand\">1</property>"
                                            "<property name=\"label\">Razón social</property>"
                                            "<property name=\"valign\">center</property>"
                                            "<property name=\"xalign\">0</property>"
                                          "</object>"
                                        "</child>"
                                        "<child>"
                                          "<object class=\"GtkEntry\" id=\"ety_conf_razon\">"
                                            "<property name=\"halign\">end</property>"
                                            "<property name=\"placeholder-text\">Type here…</property>"
                                            "<property name=\"valign\">center</property>"
                                          "</object>"
                                        "</child>"
                                      "</object>"
                                    "</child>"
                                  "</object>"
                                "</child>"
                                "<child>"
                                  "<object class=\"GtkListBoxRow\">"
                                    "<property name=\"activatable\">0</property>"
                                    "<child>"
                                      "<object class=\"GtkBox\">"
                                        "<child>"
                                          "<object class=\"GtkLabel\" id=\"entry_label_3\">"
                                            "<property name=\"halign\">start</property>"
                                            "<property name=\"hexpand\">True</property>"
                                            "<property name=\"label\">Direccion</property>"
                                            "<property name=\"valign\">center</property>"
                                            "<property name=\"xalign\">0</property>"
                                          "</object>"
                                        "</child>"
                                        "<child>"
                                          "<object class=\"GtkEntry\" id=\"ety_conf_direccion\">"
                                            "<property name=\"halign\">end</property>"
                                            "<property name=\"placeholder-text\">Type here…</property>"
                                            "<property name=\"valign\">center</property>"
                                          "</object>"
                                        "</child>"
                                      "</object>"
                                    "</child>"
                                  "</object>"
                                "</child>"
                                "<child>"
                                  "<object class=\"GtkListBoxRow\">"
                                    "<property name=\"activatable\">0</property>"
                                    "<child>"
                                      "<object class=\"GtkBox\">"
                                        "<child>"
                                          "<object class=\"GtkLabel\" id=\"entry_label\">"
                                            "<property name=\"halign\">start</property>"
                                            "<property name=\"hexpand\">True</property>"
                                            "<property name=\"label\">RFC</property>"
                                            "<property name=\"valign\">center</property>"
                                            "<property name=\"xalign\">0</property>"
                                          "</object>"
                                        "</child>"
                                        "<child>"
                                          "<object class=\"GtkEntry\" id=\"ety_conf_rfc\">"
                                            "<property name=\"halign\">end</property>"
                                            "<property name=\"placeholder-text\">Type here…</property>"
                                            "<property name=\"valign\">center</property>"
                                          "</object>"
                                        "</child>"
                                      "</object>"
                                    "</child>"
                                  "</object>"
                                "</child>"
                                "<child>"
                                  "<object class=\"GtkListBoxRow\">"
                                    "<property name=\"activatable\">0</property>"
                                    "<child>"
                                      "<object class=\"GtkBox\">"
                                        "<child>"
                                          "<object class=\"GtkLabel\" id=\"entry_label_4\">"
                                            "<property name=\"halign\">start</property>"
                                            "<property name=\"hexpand\">1</property>"
                                            "<property name=\"label\">Contacto</property>"
                                            "<property name=\"valign\">center</property>"
                                            "<property name=\"xalign\">0</property>"
                                          "</object>"
                                        "</child>"
                                        "<child>"
                                          "<object class=\"GtkEntry\" id=\"ety_conf_contacto\">"
                                            "<property name=\"halign\">end</property>"
                                            "<property name=\"placeholder-text\">Type here…</property>"
                                            "<property name=\"valign\">center</property>"
                                          "</object>"
                                        "</child>"
                                      "</object>"
                                    "</child>"
                                  "</object>"
                                "</child>"
                                "<child>"
                                  "<object class=\"GtkListBoxRow\">"
                                    "<property name=\"activatable\">0</property>"
                                    "<child>"
                                      "<object class=\"GtkBox\">"
                                        "<child>"
                                          "<object class=\"GtkLabel\" id=\"entry_label_5\">"
                                            "<property name=\"halign\">start</property>"
                                            "<property name=\"hexpand\">1</property>"
                                            "<property name=\"label\">Agradecimiento</property>"
                                            "<property name=\"valign\">center</property>"
                                            "<property name=\"xalign\">0</property>"
                                          "</object>"
                                        "</child>"
                                        "<child>"
                                          "<object class=\"GtkEntry\" id=\"ety_conf_thanks\">"
                                            "<property name=\"halign\">end</property>"
                                            "<property name=\"placeholder-text\">Type here…</property>"
                                            "<property name=\"valign\">center</property>"
                                          "</object>"
                                        "</child>"
                                      "</object>"
                                    "</child>"
                                  "</object>"
                                "</child>"
                                "<style>"
                                  "<class name=\"rich-list\"/>"
                                  "<class name=\"boxed-list\"/>"
                                "</style>"
                              "</object>"
                            "</child>"
                            "<child>"
                              "<object class=\"GtkLabel\">"
                               "<property name=\"label\">Test</property>"
                                "<property name=\"margin-bottom\">10</property>"
                                "<property name=\"margin-top\">30</property>"
                                "<property name=\"xalign\">0</property>"
                                "<style>"
                                  "<class name=\"title-2\"/>"
                                "</style>"
                              "</object>"
                            "</child>"
                            "<child>"
                              "<object class=\"GtkListBox\" id=\"list_config_test\">"
                                "<property name=\"selection-mode\">none</property>"
                                "<child>"
                                  "<object class=\"GtkListBoxRow\">"
                                    "<child>"
                                      "<object class=\"GtkBox\">"
                                        "<child>"
                                          "<object class=\"GtkLabel\" id=\"entry_label_8\">"
                                            "<property name=\"halign\">start</property>"
                                            "<property name=\"hexpand\">True</property>"
                                            "<property name=\"label\">Impresion de Prueba</property>"
                                            "<property name=\"valign\">center</property>"
                                            "<property name=\"xalign\">0</property>"
                                          "</object>"
                                        "</child>"
                                        "<child>"
                                          "<object class=\"GtkImage\">"
                                            "<property name=\"halign\">end</property>"
                                            "<property name=\"icon-name\">printer-symbolic</property>"
                                          "</object>"
                                        "</child>"
                                      "</object>"
                                    "</child>"
                                  "</object>"
                                "</child>"
                                "<style>"
                                  "<class name=\"rich-list\"/>"
                                  "<class name=\"boxed-list\"/>"
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
                  "<object class=\"GtkScrolledWindow\">"
                    "<property name=\"hexpand\">True</property>"
                    "<property name=\"margin-bottom\">20</property>"
                    "<property name=\"margin-end\">10</property>"
                    "<property name=\"margin-start\">30</property>"
                    "<property name=\"margin-top\">20</property>"
                    "<child>"
                      "<object class=\"GtkTextView\" id=\"text_ticket\">"
                        "<property name=\"cursor-visible\">False</property>"
                        "<property name=\"editable\">False</property>"
                        "<property name=\"input-purpose\">pin</property>"
                        "<property name=\"left-margin\">5</property>"
                        "<property name=\"monospace\">True</property>"
                        "<property name=\"pixels-above-lines\">5</property>"
                        "<property name=\"pixels-below-lines\">5</property>"
                        "<property name=\"pixels-inside-wrap\">5</property>"
                        "<property name=\"right-margin\">5</property>"
                        "<property name=\"top-margin\">5</property>"
                        "<property name=\"wrap-mode\">word-char</property>"
                      "</object>"
                    "</child>"
                  "</object>"
                "</child>"
              "</object>"
            "</child>"
          "</object>"
          "<object class=\"GtkSizeGroup\">"
            "<property name=\"mode\">horizontal</property>"
          "</object>"
        "</interface>";

  auto builder_config_ticket_ = Gtk::Builder::create ();
  try
    {
      builder_config_ticket_->add_from_string (xml);
    }
  catch (const Glib::Error &ex)
    {
      std::cerr << "building toolbar failed: " << ex.what ();
    }
  window_conf_ticket
      = builder_config_ticket_->get_widget<Gtk::Window> ("window_conf_ticket");
  list_config_visualizacion
      = builder_config_ticket_->get_widget<Gtk::ListBox> (
          "list_config_visualizacion");
  list_config_datos
      = builder_config_ticket_->get_widget<Gtk::ListBox> ("list_config_datos");
  list_config_test
      = builder_config_ticket_->get_widget<Gtk::ListBox> ("list_config_test");
  text_ticket
      = builder_config_ticket_->get_widget<Gtk::TextView> ("text_ticket");

  ety_conf_razon
      = builder_config_ticket_->get_widget<Gtk::Entry> ("ety_conf_razon");
  ety_conf_rfc
      = builder_config_ticket_->get_widget<Gtk::Entry> ("ety_conf_rfc");
  ety_conf_direccion
      = builder_config_ticket_->get_widget<Gtk::Entry> ("ety_conf_direccion");
  ety_conf_contacto
      = builder_config_ticket_->get_widget<Gtk::Entry> ("ety_conf_contacto");
  ety_conf_thanks
      = builder_config_ticket_->get_widget<Gtk::Entry> ("ety_conf_thanks");

  for (int i = 0; i < 6; i++)
    {
      vec_check[i] = builder_config_ticket_->get_widget<Gtk::CheckButton> (
          "check_config_" + std::to_string (i + 1));
    }
  for (int i = 0; i < 6; i++)
    {
      vec_check[i]->signal_toggled ().connect (
          sigc::mem_fun (*this, &Pos::edit_ticket));
    }

  ety_conf_razon->signal_changed ().connect (
      sigc::mem_fun (*this, &Pos::edit_ticket));
  ety_conf_rfc->signal_changed ().connect (
      sigc::mem_fun (*this, &Pos::edit_ticket));
  ety_conf_direccion->signal_changed ().connect (
      sigc::mem_fun (*this, &Pos::edit_ticket));
  ety_conf_contacto->signal_changed ().connect (
      sigc::mem_fun (*this, &Pos::edit_ticket));
  ety_conf_thanks->signal_changed ().connect (
      sigc::mem_fun (*this, &Pos::edit_ticket));
  window_conf_ticket->signal_close_request ().connect (
      sigc::mem_fun (*this, &Pos::on_window_conf_ticket_delete_event), false);

  window_conf_ticket->set_transient_for (*this);
  window_conf_ticket->set_modal (true);
  window_conf_ticket->set_hide_on_close (true);
  window_conf_ticket->set_default_size (900, 500);
  window_conf_ticket->set_resizable (false);

  initconf ();
  edit_ticket ();

  list_config_test->signal_row_activated ().connect (
      [this] (Gtk::ListBoxRow *row) {
        std::ofstream archivoTemp ("tempo.txt");
        archivoTemp << ticket_config.str ();
        archivoTemp.close ();
#ifdef __APPLE__
        std::system ("lpr tempo.txt");
#endif
#ifdef __linux__
        std::system ("lp tempo.txt");
#endif
#ifdef _WIN32
        std::system ("print tempo.txt");
#endif
        remove ("tempo.txt");
      });
  list_config_visualizacion->signal_row_activated ().connect (
      [this] (Gtk::ListBoxRow *row) {
        if (vec_check[row->get_index ()]->get_active ())
          vec_check[row->get_index ()]->set_active (false);
        else
          vec_check[row->get_index ()]->set_active (true);
        edit_ticket ();
      });
}

bool
Pos::on_window_conf_ticket_delete_event ()
{
  dialog.reset (new Gtk::MessageDialog (*window_conf_ticket, "Config. Tickets",
                                        false, Gtk::MessageType::QUESTION,
                                        Gtk::ButtonsType::NONE, true));
  dialog->set_secondary_text ("Desea guardar los cambios?");
  dialog->add_button ("Cancelar", Gtk::ResponseType::CANCEL);
  dialog->add_button ("No", Gtk::ResponseType::NO)
      ->get_style_context ()
      ->add_class ("destructive-action");
  dialog->add_button ("Si", Gtk::ResponseType::YES);

  bool ret = false;

  dialog->signal_response ().connect ([=] (int response) {
    if (response == Gtk::ResponseType::CANCEL)
      dialog->hide ();
    if (response == Gtk::ResponseType::NO)
      {
        dialog->hide ();
        initconf ();
        window_conf_ticket->hide ();
      }
    if (response == Gtk::ResponseType::YES)
      {
        dialog->hide ();
        window_conf_ticket->hide ();
        db->command ("UPDATE conf SET "
                     "v1 = '"
                     + std::to_string (vec_check[0]->get_active ())
                     + "', "
                       "v2 = '"
                     + std::to_string (vec_check[1]->get_active ())
                     + "', "
                       "v3 = '"
                     + std::to_string (vec_check[2]->get_active ())
                     + "', "
                       "v4 = '"
                     + std::to_string (vec_check[3]->get_active ())
                     + "', "
                       "v5 = '"
                     + std::to_string (vec_check[4]->get_active ())
                     + "', "
                       "v6 = '"
                     + std::to_string (vec_check[5]->get_active ()) + "'");
        db->command ("UPDATE data_conf SET "
                     "razon = '"
                     + ety_conf_razon->get_text ()
                     + "', "
                       "direccion = '"
                     + ety_conf_direccion->get_text ()
                     + "', "
                       "rfc = '"
                     + ety_conf_rfc->get_text ()
                     + "', "
                       "contacto = '"
                     + ety_conf_contacto->get_text ()
                     + "', "
                       "regreat = '"
                     + ety_conf_thanks->get_text () + "'");
      }
  });
  dialog->set_hide_on_close (true);
  dialog->show ();
  return true;
}

void
Pos::initconf ()
{
  db->command ("SELECT * FROM conf");
  for (int i = 0; i < 6; i++)
    {
      vec_check[i]->set_active (std::stoi (db->get_result ()[0][i]));
    }
	
  db->clear_result();

  db->command ("SELECT * FROM data_conf");
  ety_conf_razon->set_text (db->get_result ()[0][0]);
  ety_conf_direccion->set_text (db->get_result ()[0][1]);
  ety_conf_rfc->set_text (db->get_result ()[0][2]);
  ety_conf_contacto->set_text (db->get_result ()[0][3]);
  ety_conf_thanks->set_text (db->get_result ()[0][4]);

  db->clear_result();
}

void
Pos::edit_ticket ()
{
  ticket_config.str ("");
  ticket_config.clear ();

  ticket_config << "****** TICKET DE COMPRA ******\n"
                << "--------------------------------\n\n"
                << std::left << std::setw (20) << ety_conf_razon->get_text ()
                << "\n\n";

  if (vec_check[2]->get_active ())
    {
      ticket_config << "Dirección: " << ety_conf_direccion->get_text () << "\n"
                    << "--------------------------------\n";
    }

  if (vec_check[3]->get_active ())
    {
      ticket_config << "RFC: " << ety_conf_rfc->get_text () << "\n"
                    << "--------------------------------\n";
    }
  if (vec_check[1]->get_active ())
    ticket_config << "Fecha: "
                  << Glib::DateTime::create_now_local ().format (
                         "%Y-%m-%d %H:%M:%S")
                  << "\n";
  ticket_config << "No. Ticket: 0001"
                << "\n";
  if (vec_check[4]->get_active ())
    ticket_config << std::left << std::setw (10) << "Le atendió: "
                  << "Juan Perez"
                  << "\n\n"
                  << "--------------------------------\n";
  ticket_config << std::left << std::setw (20) << "Articulo" << std::setw (5)
                << "Cnt." << std::setw (5) << "P.U."
                << "T.\n"
                << "--------------------------------\n";
  ticket_config << std::left << std::setw (20) << "Articulo de prueba"
                << std::setw (5) << "10" << std::setw (5) << "6"
                << std::setw (5) << "60"
                << "\n"
                << "--------------------------------\n";
  ticket_config << std::left << std::setw (20) << "Total:"
                << "60.00\n";
  ticket_config << std::left << std::setw (20) << "Tipo de Pago:"
                << "Efectivo\n"
                << "--------------------------------\n";
  ticket_config << std::left << std::setw (20) << "Ingreso:"
                << "90.00\n";
  ticket_config << std::left << std::setw (20) << "Cambio:"
                << "30.00\n"
                << "--------------------------------\n";
  if (vec_check[5]->get_active ())
    ticket_config << "**" << ety_conf_contacto->get_text () << "**"
                  << "\n"
                  << "--------------------------------\n";
  if (vec_check[0]->get_active ())
    ticket_config << "**" << ety_conf_thanks->get_text () << "**"
                  << "\n"
                  << "--------------------------------\n";
  m_refTextBuffer1->set_text (ticket_config.str ());
  text_ticket->set_buffer (m_refTextBuffer1);
}