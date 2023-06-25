#pragma once

#include "Pos.hpp"
#include "columns.hpp"
#include <string>

void Pos::init_producto()
{
    //)==================================Producto==================================(
    // Create the Tree model:
    int id = 0;
    m_refTreeModel_prod = Gtk::ListStore::create(m_Columns_prod);
    tree_prod->set_model(m_refTreeModel_prod);

    // This number will be shown with the default numeric formatting.
    tree_prod->append_column_editable("SKU", m_Columns_prod.sku);
    tree_prod->append_column_editable("Nombre", m_Columns_prod.nombre);
    tree_prod->append_column_editable("Caducidad", m_Columns_prod.caducidad);

    // This number will be shown with a custom numeric formatting.
    auto cell = Gtk::make_managed<Gtk::CellRendererCombo>();
    id = tree_prod->append_column("Marca", *cell);
    col_marca = tree_prod->get_column(id - 1);
    col_marca->pack_start(*cell);

    col_marca->add_attribute(cell->property_text(), m_Columns_prod.marca);
    col_marca->add_attribute(cell->property_model(), m_Columns_prod.marca);

    cell->property_editable() = true;
    cell->property_text_column() = 0;
    cell->property_has_entry() = false;

    m_refTreeModelCombo = Gtk::ListStore::create(m_ColumnsCombo);
    cell->property_model() = m_refTreeModelCombo;

    auto iter_ = m_refTreeModelCombo->append();
    (*iter_)[m_ColumnsCombo.m_col_name] = "Coca Cola";

    iter_ = m_refTreeModelCombo->append();
    (*iter_)[m_ColumnsCombo.m_col_name] = "Coca Cola 2";
    iter_ = m_refTreeModelCombo->append();
    (*iter_)[m_ColumnsCombo.m_col_name] = "Coca Cola 4";

    cell->property_model() = m_refTreeModelCombo;
    // tree_prod->append_column_editable("Marca", m_Columns_prod.marca);
    tree_prod->append_column_editable("Nota", m_Columns_prod.nota);
    tree_prod->append_column_editable("Piezas", m_Columns_prod.piezas);
    tree_prod->append_column_numeric_editable("Precio Unitario", m_Columns_prod.precio_u, "%.2f");
    tree_prod->append_column_numeric_editable("Compra Total", m_Columns_prod.compra_t, "%.2f");
    tree_prod->append_column_editable("Categoria", m_Columns_prod.categoria);
    tree_prod->append_column_editable("Subcategoria", m_Columns_prod.subcategoria);

    // Make all the columns reorderable and resizable:
    for (auto &column : tree_prod->get_columns())
    {
        column->set_reorderable();
        column->set_resizable(true);
    }

    // Add some data:
    row_producto = *(m_refTreeModel_prod->append());
    row_producto[m_Columns_prod.sku] = 1;
    row_producto[m_Columns_prod.nombre] = "Coca Cola";
    row_producto[m_Columns_prod.caducidad] = "2021-12-12";

    row_producto[m_Columns_prod.marca] = "Coca Cola";

    row_producto[m_Columns_prod.nota] = "Sin azucar";
    row_producto[m_Columns_prod.piezas] = "12";
    row_producto[m_Columns_prod.precio_u] = 12.5;
    row_producto[m_Columns_prod.compra_t] = 150;
    row_producto[m_Columns_prod.categoria] = "Bebidas";
    row_producto[m_Columns_prod.subcategoria] = "Refrescos";
}