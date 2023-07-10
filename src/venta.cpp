#pragma once

#include "Pos.hpp"

void Pos::init_reporte(){
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

    for(size_t i = 0; i < db->get_result().size() ; i++){
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

}