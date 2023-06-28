#pragma once

#include "Pos.hpp"
#include "columns.hpp"
#include <string>
#include <sstream>
#include <iomanip>

void Pos::init_producto()
{
    //)==================================Producto==================================(
    // Create the Tree model:
    int id = 0;
    m_refTreeModel_prod = Gtk::ListStore::create(m_Columns_prod);
    tree_prod->set_model(m_refTreeModel_prod);

    id = tree_prod->append_column("SKU", *cell_sku);
    col_sku = tree_prod->get_column(id - 1);
    id = tree_prod->append_column("Nombre", *cell_nombre);
    col_nombre = tree_prod->get_column(id - 1);
    id = tree_prod->append_column("Caducidad", *cell_caducidad);
    col_caducidad = tree_prod->get_column(id - 1);

    id = tree_prod->append_column("Marca", *cell_marca);
    col_marca = tree_prod->get_column(id - 1);

    id = tree_prod->append_column("Nota", *cell_nota);
    col_nota = tree_prod->get_column(id - 1);
    id = tree_prod->append_column("Piezas", *cell_piezas);
    col_piezas = tree_prod->get_column(id - 1);
    id = tree_prod->append_column("Precio Unitario", *cell_precio_u);
    col_precio_u = tree_prod->get_column(id - 1);
    id = tree_prod->append_column("Categoria", *cell_categoria);
    col_categoria = tree_prod->get_column(id - 1);
    id = tree_prod->append_column("Subcategoria", *cell_subcategoria);
    col_subcategoria = tree_prod->get_column(id - 1);

    // Add the TreeView's view columns:
    // This number will be shown with the default numeric formatting.
    col_sku->add_attribute(cell_sku->property_text(), m_Columns_prod.sku);
    col_nombre->add_attribute(cell_nombre->property_text(), m_Columns_prod.nombre);
    col_caducidad->add_attribute(cell_caducidad->property_text(), m_Columns_prod.caducidad);
    col_marca->add_attribute(cell_marca->property_text(), m_Columns_prod.marca);
    col_nota->add_attribute(cell_nota->property_text(), m_Columns_prod.nota);
    col_piezas->add_attribute(cell_piezas->property_text(), m_Columns_prod.piezas);
    col_precio_u->add_attribute(cell_precio_u->property_text(), m_Columns_prod.precio_u);
    col_categoria->add_attribute(cell_categoria->property_text(), m_Columns_prod.categoria);
    col_subcategoria->add_attribute(cell_subcategoria->property_text(), m_Columns_prod.subcategoria);
    col_precio_u->set_cell_data_func(*cell_precio_u, sigc::mem_fun(*this, &Pos::on_cell_data_func_u));
    col_sku->pack_start(*cell_sku);
    col_nombre->pack_start(*cell_nombre);
    col_caducidad->pack_start(*cell_caducidad);
    col_marca->pack_start(*cell_marca);
    col_nota->pack_start(*cell_nota);
    col_piezas->pack_start(*cell_piezas);
    col_precio_u->pack_start(*cell_precio_u);
    col_categoria->pack_start(*cell_categoria);
    col_subcategoria->pack_start(*cell_subcategoria);

    // Make all the columns reorderable and resizable:
    for (auto &column : tree_prod->get_columns())
    {
        column->set_reorderable();
        column->set_resizable(true);
    }

    cell_sku->property_editable() = true;
    cell_nombre->property_editable() = true;
    cell_caducidad->property_editable() = true;
    cell_nota->property_editable() = true;
    cell_piezas->property_editable() = false;
    cell_precio_u->property_editable() = true;
    cell_compra_t->property_editable() = true;
    cell_categoria->property_editable() = true;
    cell_subcategoria->property_editable() = true;

    cell_marca->property_editable() = true;
    cell_marca->property_text_column() = 0;
    cell_marca->property_has_entry() = false;
    cell_marca->property_model() = m_refTreeModelCombo;

    cell_precio_u->property_adjustment() = Gtk::Adjustment::create(0.0, 0.0, 100000.0, 1.0, 2.0, 2.0);
    cell_precio_u->property_digits() = 2;

    cell_compra_t->property_adjustment() = Gtk::Adjustment::create(0.0, 0.0, 100000.0, 1.0, 2.0, 2.0);
    cell_compra_t->property_digits() = 2;

    // Add some data:
    db->command("SELECT * FROM producto");
    result = db->get_result();

    for (int i = 0; i < result.size(); i++)
    {
        row_producto = *(m_refTreeModel_prod->append());
        row_producto[m_Columns_prod.sku] = std::stoi(result[i][0]);
        row_producto[m_Columns_prod.nombre] = result[i][1];
        row_producto[m_Columns_prod.caducidad] = result[i][2];
        row_producto[m_Columns_prod.marca] = result[i][3];
        row_producto[m_Columns_prod.nota] = result[i][4];
        row_producto[m_Columns_prod.piezas] = std::stoi(result[i][5]);
        row_producto[m_Columns_prod.precio_u] = std::stod(result[i][6]);
        row_producto[m_Columns_prod.categoria] = result[i][7];
        row_producto[m_Columns_prod.subcategoria] = result[i][8];
    }

    result.clear();

    cont_prod = m_refTreeModel_prod->children().size();
    lbl_cont_prod->set_text("Productos: " + std::to_string(cont_prod));
}

void Pos::on_cell_marca_changed(int response_id, Gtk::MessageDialog *dialog, const Glib::ustring &path_string, const Gtk::TreeModel::iterator &val)
{
    switch (response_id)
    {
    case Gtk::ResponseType::OK:
    {
        Gtk::TreeModel::iterator iter = m_refTreeModel_prod->get_iter(path_string);
        if (iter)
        {
            row_producto = *iter;
            row_producto[m_Columns_prod.marca] = (*val)[m_ColumnsCombo.m_col_name].operator Glib::ustring();
        }
        dialog->hide();
    }
    break;
    case Gtk::ResponseType::CANCEL:
        dialog->hide();
        break;

    default:
        dialog->hide();
        break;
    
    }
}

void Pos::on_cell_data_func_u(Gtk::CellRenderer *renderer, const Gtk::TreeModel::const_iterator &iter)
{
    if (iter)
    {
        double value = (*iter)[m_Columns_prod.precio_u];
        char buffer[32];
        sprintf(buffer, "$%.2f", value);
        cell_precio_u->property_text() = buffer;
    }
}

void Pos::on_produ_dialog_edit_response(int response_id, Gtk::MessageDialog *dialog, const Glib::ustring &path_string, const Glib::ustring &new_text, const int &column)
{
    switch (response_id)
    {
    case Gtk::ResponseType::OK:
    {
        auto iter = m_refTreeModel_prod->get_iter(path_string);
        if (iter)
        {
            try
            {
                switch (column)
                {
                case COLUMNS::ColumnProducto::SKU:
                    (*iter)[m_Columns_prod.sku] = std::stoi(new_text);
                    break;

                case COLUMNS::ColumnProducto::NOMBRE_PRODUCTO:

                    (*iter)[m_Columns_prod.nombre] = new_text;
                    break;

                case COLUMNS::ColumnProducto::CADUCIDAD:
                    (*iter)[m_Columns_prod.caducidad] = new_text;
                    break;

                case COLUMNS::ColumnProducto::MARCA:
                    (*iter)[m_Columns_prod.marca] = new_text;
                    break;

                case COLUMNS::ColumnProducto::NOTA:
                    (*iter)[m_Columns_prod.nota] = new_text;
                    break;

                case COLUMNS::ColumnProducto::PIEZAS:
                    (*iter)[m_Columns_prod.piezas] = std::stoi(new_text);
                    break;

                case COLUMNS::ColumnProducto::PRECIO_U:
                    (*iter)[m_Columns_prod.precio_u] = std::stod(new_text);
                    break;

                case COLUMNS::ColumnProducto::CATEGORIA:
                    (*iter)[m_Columns_prod.categoria] = new_text;
                    break;

                case COLUMNS::ColumnProducto::SUBCATEGORIA:
                    (*iter)[m_Columns_prod.subcategoria] = new_text;
                    break;
                }
            }
            catch (std::exception &e)
            {
                std::cout << e.what() << std::endl;
                auto dialog = new Gtk::MessageDialog(*this, "Error al editar un Registro", false, Gtk::MessageType::ERROR, Gtk::ButtonsType::OK, true);
                dialog->set_secondary_text(e.what());
                dialog->set_hide_on_close(true);
                dialog->show();
            }
        }
        dialog->hide();
    }
    break;
    case Gtk::ResponseType::CANCEL:
        dialog->hide();
        break;
    default:
        dialog->hide();
        break;
    }
}
