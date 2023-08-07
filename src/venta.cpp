#pragma once

#include "Pos.hpp"

void Pos::init_reporte()
{
    m_refTreeModel_reporte = Gtk::ListStore::create(m_Columns_reporte);
    tree_repor->set_model(m_refTreeModel_reporte);

    tree_repor->append_column("Folio", m_Columns_reporte.id);
    tree_repor->append_column("Tipo de Venta", m_Columns_reporte.tipo);
    tree_repor->append_column_numeric("Total", m_Columns_reporte.total, "$%.2f");
    tree_repor->append_column_numeric("Ingreso", m_Columns_reporte.ingreso, "$%.2f");
    tree_repor->append_column_numeric("Cambio", m_Columns_reporte.cambio, "$%.2f");
    tree_repor->append_column("Folio Tarjeta", m_Columns_reporte.folio);
    tree_repor->append_column("Fecha", m_Columns_reporte.fecha);

    db->command("SELECT * FROM venta ORDER BY id");

    for (size_t i = 0; i < db->get_result().size(); i++)
    {
        row_reporte = *(m_refTreeModel_reporte->prepend());
        row_reporte[m_Columns_reporte.id] = std::stoll(db->get_result()[i][0]);
        row_reporte[m_Columns_reporte.tipo] = db->get_result()[i][1];
        row_reporte[m_Columns_reporte.total] = std::stof(db->get_result()[i][2]);
        row_reporte[m_Columns_reporte.ingreso] = std::stof(db->get_result()[i][3]);
        row_reporte[m_Columns_reporte.cambio] = std::stof(db->get_result()[i][4]);
        row_reporte[m_Columns_reporte.folio] = db->get_result()[i][5];
        row_reporte[m_Columns_reporte.fecha] = db->get_result()[i][6];
        row_reporte[m_Columns_reporte.datos] = db->get_result()[i][7];
    }
    result.clear();
}

void Pos::init_detalle_venta()
{
    Modeldetalle_venta = Gtk::ListStore::create(m_Columns_detalle_venta);
    tree_detalle_venta->set_model(Modeldetalle_venta);

    // tree_detalle_venta->append_column("Código", m_Columns_detalle_venta.sku);
    tree_detalle_venta->append_column_numeric("Cantidad", m_Columns_detalle_venta.cantidad, "%d");
    tree_detalle_venta->append_column("Descripción", m_Columns_detalle_venta.nombre);
    tree_detalle_venta->append_column_numeric("Precio", m_Columns_detalle_venta.precio_u, "$%.2f");
    tree_detalle_venta->append_column_numeric("Total", m_Columns_detalle_venta.precio_t, "$%.2f");
}

void Pos::on_tree_detalle_venta_row_activated(const Gtk::TreeModel::Path &path, Gtk::TreeViewColumn *column)
{
    auto iter = m_refTreeModel_reporte->get_iter(path);
    if (iter)
    {
        if (!Modeldetalle_venta->children().empty())
            Modeldetalle_venta->clear();
        std::istringstream iss((*iter)[m_Columns_reporte.datos].operator Glib::ustring());
        std::string token;
        std::vector<std::string> tokens;
        while (std::getline(iss, token, '|'))
        {
            tokens.push_back(token);
            if (tokens.size() == 5)
            {
                row_detalle_venta = *(Modeldetalle_venta->append());
                row_detalle_venta[m_Columns_detalle_venta.sku] = std::stoll(tokens[0]);
                row_detalle_venta[m_Columns_detalle_venta.cantidad] = std::stoi(tokens[1]);
                row_detalle_venta[m_Columns_detalle_venta.nombre] = tokens[2];
                row_detalle_venta[m_Columns_detalle_venta.precio_u] = std::stof(tokens[3]);
                row_detalle_venta[m_Columns_detalle_venta.precio_t] = std::stof(tokens[1]) * std::stof(tokens[3]);
                tokens.clear();
            }
        }
    }
}

void Pos::on_popup_button_pressed(int /* n_press */, double x, double y)
{
    if (tree_repor->is_focus())
    {
        const Gdk::Rectangle rect(x, y - 110, 1, 1);
        m_MenuPopup.set_pointing_to(rect);
        m_MenuPopup.popup();
    }
}

void Pos::on_menu_file_popup_generic()
{
    std::cout << "A popup menu item was selected." << std::endl;

    auto refSelection = tree_repor->get_selection();
    if (refSelection)
    {
        auto iter = refSelection->get_selected();
        if (iter)
        {
            dialog.reset(new Gtk::MessageDialog(*this, "Cancelacion de Venta.", false, Gtk::MessageType::INFO, Gtk::ButtonsType::CANCEL, true));
            dialog->set_secondary_text("Escriba el motivo de la cancelacion.");
            dialog->get_content_area()->append(ety_folio);
            dialog->add_button("Cancelar Venta", Gtk::ResponseType::OK)->set_css_classes({"destructive-action"});
            ety_folio.show();
            dialog->signal_response().connect([=](int response){
                if(response == Gtk::ResponseType::OK){
                    if(!ety_folio.get_text().empty()){

                        std::istringstream iss((*iter)[m_Columns_reporte.datos].operator Glib::ustring());
                        std::string token;
                        std::vector<std::string> tokens;
                        while (std::getline(iss, token, '|'))
                        {
                            tokens.push_back(token);
                            if (tokens.size() == 5)
                            {   
                                std::cout << std::stoll(tokens[0]) << std::endl;
                                std::cout << tokens[0] << std::endl;
                                for (auto i : m_refTreeModel_prod->children()){
                                    if(i[m_Columns_prod.sku] == std::stoll(tokens[0])){
                                        auto a = i[m_Columns_prod.piezas] + std::stoi(tokens[1]);
                                        db->command("UPDATE producto SET piezas = " + std::to_string(a) + " WHERE sku = " + std::to_string(std::stoll(tokens[0])));
                                        (i)[m_Columns_prod.piezas] = a ;
                                        break;
                                    }
                                }
                                Modeldetalle_venta->clear();
                                tokens.clear();
                            }
                        }
                    db->command("DELETE FROM venta WHERE id = " + std::to_string((*iter)[m_Columns_reporte.id]));
                    m_refTreeModel_reporte->erase(iter);
                    dialog->hide();
                    }
                }
                else
                    dialog->hide();
            });
            ety_folio.grab_focus();
            dialog->show();
        }
    }
}