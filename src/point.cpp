#pragma once

#include "Pos.hpp"
#include "columns.hpp"
#include <vector>
#include <sstream>
#include <iomanip>

void Pos::init_venta()
{
    ModelCarroVenta = Gtk::ListStore::create(m_Columns_venta);
    tree_venta->set_model(ModelCarroVenta);

    tree_venta->append_column("Cantidad", m_Columns_venta.cantidad);
    tree_venta->append_column("Articulo", m_Columns_venta.nombre);
    tree_venta->append_column_numeric("Precio U", m_Columns_venta.precio_u, "$%.2f");
    tree_venta->append_column_numeric("Precio T", m_Columns_venta.precio_t, "$%.2f");
}

void Pos::on_btn_pago_efectivo_clicked()
{
    if (total_vcarrito != 0)
    {
        for (auto row : ModelCarroVenta->children())
        {
            for (auto row_prod : m_refTreeModel_prod->children())
            {
                if (row[m_Columns_venta.sku] == row_prod[m_Columns_prod.sku])
                {
                    int diff = row_prod[m_Columns_prod.piezas] - row[m_Columns_venta.cantidad];
                    if (diff >= 0)
                        db->command("UPDATE producto SET piezas = " + std::to_string(diff) + " WHERE sku = " + std::to_string(row_prod[m_Columns_prod.sku]) + ";");
                    row_prod[m_Columns_prod.piezas] = diff;
                }
            }
        }
        // db->command("INSERT INTO venta (total, fecha) VALUES (" + std::to_string(total_vcarrito) + ", CURRENT_TIMESTAMP);");

        // db->command("INSERT INTO pago (tipo, monto, cambio, fecha) VALUES ('Efectivo', " + std::to_string(total_vcarrito) + ", " + std::to_string(spin_ingreso->get_value() - total_vcarrito) + ", CURRENT_TIMESTAMP);");
        total_vcarrito = 0;
        //spin_ingreso->set_value(0);
        // lbl_cambio->set_markup("$<span font_desc='50'>0.00</span>");
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
                row_venta[m_Columns_venta.sku] = row[m_Columns_prod.sku].operator std::size_t();
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
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << spin_ingreso->get_value() - total_vcarrito;
    if (spin_ingreso->get_value() - total_vcarrito < 0)
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
        on_btn_pago_efectivo_clicked();
        std::cout << "F11" << std::endl;
        return true;
    }
    return false;
}

void Pos::on_btn_pago_tarjeta_clicked()
{
    if (total_vcarrito - spin_ingreso->get_value() < 0)
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
                if(total_vcarrito == spin_ingreso->get_value())
                {
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
                    //lbl_cambio->set_markup("$<span font_desc='50'>0.00</span>");
                    spin_ingreso->set_value(0);
                    ety_barras->grab_focus();
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