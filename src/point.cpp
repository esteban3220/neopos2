#pragma once

#include "Pos.hpp"
#include "columns.hpp"
#include <vector>
#include <iomanip>
#include <cmath>
#include <fstream>

void Pos::init_venta()
{
    ModelCarroVenta = Gtk::ListStore::create(m_Columns_venta);
    tree_venta->set_model(ModelCarroVenta);

    tree_venta->append_column("Cantidad", m_Columns_venta.cantidad);
    tree_venta->append_column("Articulo", m_Columns_venta.nombre);
    tree_venta->append_column_numeric("Precio U", m_Columns_venta.precio_u, "$%.2f");
    tree_venta->append_column_numeric("Precio T", m_Columns_venta.precio_t, "$%.2f");
}

void Pos::cierra_venta()
{
    pag_efectivo = true;
    on_btn_pago_efectivo_clicked();
}

void Pos::on_btn_pago_efectivo_clicked()
{
    if (total_vcarrito != 0)
    {
        std::stringstream ss;
        std::stringstream ticket;
        std::string tipo;

        ticket << "***************** TICKET DE COMPRA ****************" << std::endl;
        ticket << "---------------------------------------------------" << std::endl;

        for (auto row : ModelCarroVenta->children())
        {
            ss << std::to_string(row[m_Columns_venta.sku]) << "|" << row[m_Columns_venta.cantidad] << "|" << row[m_Columns_venta.nombre] << "|" << row[m_Columns_venta.precio_u] << "|" << row[m_Columns_venta.precio_t] << "|";
            ticket << std::left << std::setw(20) << row[m_Columns_venta.nombre] << std::right << std::setw(10) << row[m_Columns_venta.cantidad] << std::setw(10) << row[m_Columns_venta.precio_u] << std::setw(10) << row[m_Columns_venta.precio_t] << std::endl;

            for (auto row_prod : m_refTreeModel_prod->children())
            {
                if (row[m_Columns_venta.sku] == row_prod[m_Columns_prod.sku])
                {
                    int diff = row_prod[m_Columns_prod.piezas] - row[m_Columns_venta.cantidad];
                    if (diff >= 0)
                        db->command("UPDATE producto SET piezas = " + std::to_string(diff) + " WHERE sku = " + std::to_string(row_prod[m_Columns_prod.sku]) + ";");
                    row_prod[m_Columns_prod.piezas] = diff;
                    break;
                }
            }
        }

        if (pag_tarjeta)
            tipo = "Tarjeta";
        if (pag_efectivo)
            tipo = "Efectivo";
        if (pag_efectivo && pag_tarjeta)
            tipo = "Mixto";
        auto rowid = m_refTreeModel_reporte->get_iter("0");
        auto id = (*rowid)[m_Columns_reporte.id] + 1;

        ticket << "---------------------------------------------------" << std::endl;
        ticket << std::left << std::setw(20) << "Total:" << std::right << std::setw(30) << std::fixed << std::setprecision(2) << total_vcarrito << std::endl;
        ticket << std::left << std::setw(20) << "Tipo de Pago:" << std::right << std::setw(30) << tipo << std::endl;
        ticket << "---------------------------------------------------" << std::endl;
        ticket << std::left << std::setw(20) << "Ingreso:" << std::right << std::setw(30) << std::fixed << std::setprecision(2) << spin_ingreso->get_value() << std::endl;
        ticket << std::left << std::setw(20) << "Cambio:" << std::right << std::setw(30) << std::fixed << std::setprecision(2) << spin_ingreso->get_value() - total_vcarrito << std::endl;
        ticket << "---------------------------------------------------" << std::endl;
        ticket << std::left << std::setw(20) << "Folio Tarjeta:" << std::right << std::setw(30) << folio_tarjetaa.str() << std::endl;
        ticket << "---------------------------------------------------" << std::endl;
        ticket << std::left << std::setw(20) << "Fecha:" << std::right << std::setw(30) << Glib::DateTime::create_now_local().format("%Y-%m-%d %H:%M:%S") << std::endl;
        //ticket << std::left << std::setw(20) << "Vendedor:" << std::right << std::setw(30) << ss.str() << std::endl;
        ticket << std::left << std::setw(20) << "No. Ticket:" << std::right << std::setw(30) << id << std::endl;
        ticket << "---------------------------------------------------" << std::endl;
        ticket << "************** Gracias por su compra **************" << std::endl;
        
        std::cout << ticket.str() << std::endl;

        std::ofstream archivoTemp("temp.txt");
        archivoTemp << ticket.str();
        archivoTemp.close();

        std::system("lp temp.txt");
        remove("temp.txt");

        db->command("INSERT INTO venta VALUES (" + std::to_string(id) + ",'" + tipo + "', " + std::to_string(total_vcarrito) + ", " + spin_ingreso->get_text() + " , " + lbl_cambio->get_text().substr(1, lbl_cambio->get_text().size()) + ",'" + folio_tarjetaa.str() + "' , datetime('now','localtime') , '" + ss.str() + "');");

        row_reporte = *(m_refTreeModel_reporte->prepend());
        row_reporte[m_Columns_reporte.id] = id;
        row_reporte[m_Columns_reporte.tipo] = tipo;
        row_reporte[m_Columns_reporte.total] = total_vcarrito;
        row_reporte[m_Columns_reporte.ingreso] = (float)spin_ingreso->get_value();
        row_reporte[m_Columns_reporte.cambio] = (float)spin_ingreso->get_value() - total_vcarrito;
        row_reporte[m_Columns_reporte.folio] = folio_tarjetaa.str();
        row_reporte[m_Columns_reporte.fecha] = Glib::DateTime::create_now_local().format("%Y-%m-%d %H:%M:%S");
        row_reporte[m_Columns_reporte.datos] = ss.str();

        folio_tarjetaa.str("");
        folio_tarjetaa.clear();
        pag_efectivo = false;
        pag_tarjeta = false;
        total_vcarrito = 0.0f;
        lbl_precio_total->set_markup("$<span font_desc='50'>0.00</span>");
        ModelCarroVenta->clear();
    }
}

void Pos::add_articulo_venta()
{
    if (ety_barras->get_text().empty())
    {
        spin_ingreso->grab_focus();
        return;
    }
    std::stringstream ss;
    try
    {
        for (auto row : m_refTreeModel_prod->children())
        {
            if (row[m_Columns_prod.sku] == std::stoll(ety_barras->get_text()))
            {
                for (auto row_venta : ModelCarroVenta->children())
                {
                    if (row_venta[m_Columns_venta.sku] == row[m_Columns_prod.sku])
                    {
                        row_venta[m_Columns_venta.cantidad] = row_venta[m_Columns_venta.cantidad].operator std::size_t() + 1;
                        row_venta[m_Columns_venta.precio_t] = row_venta[m_Columns_venta.cantidad].operator std::size_t() * row_venta[m_Columns_venta.precio_u].operator float();
                        total_vcarrito += row_venta[m_Columns_venta.precio_u].operator float();
                        ety_barras->set_text("");
                        ss << std::fixed << std::setprecision(2) << total_vcarrito;
                        lbl_precio_total->set_markup("$<span font_desc='50'>" + ss.str() + "</span>");
                        on_spin_ingreso_changed();
                        return;
                    }
                }
                row_venta = *(ModelCarroVenta->append());
                row_venta[m_Columns_venta.sku] = row[m_Columns_prod.sku].operator long long();
                row_venta[m_Columns_venta.cantidad] = 1;
                row_venta[m_Columns_venta.nombre] = row[m_Columns_prod.nombre].operator Glib::ustring();
                row_venta[m_Columns_venta.precio_u] = row[m_Columns_prod.precio_u].operator float();
                row_venta[m_Columns_venta.precio_t] = row[m_Columns_prod.precio_u].operator float();
                total_vcarrito += row[m_Columns_prod.precio_u];
                ss << std::fixed << std::setprecision(2) << total_vcarrito;
                ety_barras->set_text("");
                lbl_precio_total->set_markup("$<span font_desc='50'>" + ss.str() + "</span>");
                on_spin_ingreso_changed();
                break;
            }
        }
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}

void Pos::on_spin_ingreso_changed()
{
    std::stringstream ss, total;
    ss << std::fixed << std::setprecision(2) << (float)spin_ingreso->get_value() - total_vcarrito;
    if (std::stof(ss.str()) < 0)
    {
        lbl_cambio->set_markup("$<span font_desc='50' foreground='red'>" + ss.str() + "</span>");
        btn_pago_efectivo->set_sensitive(false);
    }
    else
    {
        lbl_cambio->set_markup("$<span font_desc='50'>" + ss.str() + "</span>");
        btn_pago_efectivo->set_sensitive(true);
    }
}

bool Pos::on_spin_ingreso_activate(guint keyval, guint, Gdk::ModifierType state)
{
    if (keyval == GDK_KEY_F11)
    {
        cierra_venta();
        std::cout << "F11" << std::endl;
        return true;
    }
    if (keyval == GDK_KEY_F12)
    {
        on_btn_pago_tarjeta_clicked();
        std::cout << "F12" << std::endl;
        return true;
    }
    return false;
}

void Pos::on_btn_pago_tarjeta_clicked()
{
    if (((float)spin_ingreso->get_value() - total_vcarrito) >= 0.01f)
    {
        dialog.reset(new Gtk::MessageDialog(*this, "El monto ingresado es mayor a la cuenta", false, Gtk::MessageType::ERROR, Gtk::ButtonsType::OK, true));
        dialog->set_title("Pago con Tarjeta");
        dialog->signal_response().connect(sigc::mem_fun(*this, &Pos::cierra_dialogo));
        dialog->set_hide_on_close(true);
        dialog->show();
        return;
    }
    if (total_vcarrito != 0 && spin_ingreso->get_value() != 0)
    {
        dialog.reset(new Gtk::MessageDialog(*this, "Inserte el Numero de Folio de Transaccion Aprobada.", false, Gtk::MessageType::INFO, Gtk::ButtonsType::OK_CANCEL, true));
        dialog->set_secondary_text("Si no se inserta el numero de folio, la venta no se registrara.");
        dialog->set_title("Pago con Tarjeta");
        dialog->set_modal(true);
        dialog->signal_response().connect([&](int response_id)
                                          {
            if (response_id == Gtk::ResponseType::OK)
            {
                if (ety_folio.get_text().empty())
                    return;
                if(total_vcarrito - spin_ingreso->get_value() < 0.001)
                {
                    folio_tarjetaa  << ety_folio.get_text() << " - " << spin_ingreso->get_text() <<" | ";
                    pag_tarjeta = true;
                    on_btn_pago_efectivo_clicked();
                    dialog->close();
                    return;
                }
                else
                {
                    std::stringstream ss;
                    total_vcarrito -= spin_ingreso->get_value();
                    ss << std::fixed << std::setprecision(2) << total_vcarrito;
                    lbl_precio_total->set_markup("$<span font_desc='50'>" + ss.str() + "</span>");
                    folio_tarjetaa  << ety_folio.get_text() << " - " << spin_ingreso->get_text() <<" | ";
                    pag_tarjeta = true;
                    spin_ingreso->set_value(0);
                    spin_ingreso->grab_focus();
                    dialog->close();
                    return;
                }
            }if(response_id == Gtk::ResponseType::CANCEL)
            dialog->close(); });
        dialog->get_content_area()->append(ety_folio);
        ety_folio.show();
        ety_folio.grab_focus();
        dialog->show();
    }
}

bool Pos::add_match_arcticulo(const Gtk::TreeModel::iterator &iter)
{
    std::stringstream ss;

    for (auto row_venta : ModelCarroVenta->children())
    {
        if (row_venta[m_Columns_venta.sku] == iter->get_value(m_Columns_prod.sku))
        {
            row_venta[m_Columns_venta.cantidad] = row_venta[m_Columns_venta.cantidad].operator std::size_t() + 1;
            row_venta[m_Columns_venta.precio_t] = row_venta[m_Columns_venta.cantidad].operator std::size_t() * row_venta[m_Columns_venta.precio_u].operator float();
            total_vcarrito += row_venta[m_Columns_venta.precio_u].operator float();
            ety_barras->set_text("");
            ss << std::fixed << std::setprecision(2) << total_vcarrito;
            lbl_precio_total->set_markup("$<span font_desc='50'>" + ss.str() + "</span>");
            on_spin_ingreso_changed();
            return true;
        }
    }
    row_venta = *(ModelCarroVenta->append());
    row_venta[m_Columns_venta.sku] = iter->get_value(m_Columns_prod.sku);
    row_venta[m_Columns_venta.cantidad] = 1;
    row_venta[m_Columns_venta.nombre] = iter->get_value(m_Columns_prod.nombre);
    row_venta[m_Columns_venta.precio_u] = iter->get_value(m_Columns_prod.precio_u);
    row_venta[m_Columns_venta.precio_t] = iter->get_value(m_Columns_prod.precio_u);
    total_vcarrito += iter->get_value(m_Columns_prod.precio_u);
    ss << std::fixed << std::setprecision(2) << total_vcarrito;
    ety_barras->set_text("");
    lbl_precio_total->set_markup("$<span font_desc='50'>" + ss.str() + "</span>");
    on_spin_ingreso_changed();
    return true;
}