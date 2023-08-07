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
    for (auto& column : tree_prod->get_columns())
    {
        column->set_reorderable();
        column->set_resizable(true);
    }

    //SORT

    col_sku->set_sort_column(m_Columns_prod.sku);
    col_nombre->set_sort_column(m_Columns_prod.nombre);
    col_caducidad->set_sort_column(m_Columns_prod.caducidad);
    col_marca->set_sort_column(m_Columns_prod.marca);
    col_nota->set_sort_column(m_Columns_prod.nota);
    col_piezas->set_sort_column(m_Columns_prod.piezas);
    col_precio_u->set_sort_column(m_Columns_prod.precio_u);
    col_categoria->set_sort_column(m_Columns_prod.categoria);
    col_subcategoria->set_sort_column(m_Columns_prod.subcategoria);

    cell_sku->property_editable() = true;
    cell_nombre->property_editable() = true;
    cell_caducidad->property_editable() = true;
    cell_nota->property_editable() = true;
    cell_piezas->property_editable() = false;
    cell_precio_u->property_editable() = true;
    cell_compra_t->property_editable() = true;
    cell_subcategoria->property_editable() = true;

    m_refTreeModelCategoria = Gtk::ListStore::create(m_ColumnsCategoria);
    std::cout << "Subcate: " << subcategoria_map.size() << std::endl;

    cell_categoria->property_editable() = true;
    cell_categoria->property_text_column() = 0;
    cell_categoria->property_has_entry() = false;
    cell_categoria->property_model() = m_refTreeModelCategoria;

    cell_marca->property_editable() = true;
    cell_marca->property_text_column() = 0;
    cell_marca->property_has_entry() = false;
    cell_marca->property_model() = m_refTreeModelCombo;

    cell_subcategoria->property_editable() = true;
    cell_subcategoria->property_text_column() = 0;
    cell_subcategoria->property_has_entry() = false;
    cell_subcategoria->property_model() = m_refTreeModelSubCategoria;

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
        row_producto[m_Columns_prod.sku] = std::stoll(result[i][0]);
        row_producto[m_Columns_prod.nombre] = result[i][1];
        row_producto[m_Columns_prod.caducidad] = result[i][2];
        row_producto[m_Columns_prod.marca] = result[i][3];
        cell_marca->property_placeholder_text() = result[i][3];
        row_producto[m_Columns_prod.nota] = result[i][4];
        row_producto[m_Columns_prod.piezas] = result[i][5] == "NULL" ? 0 : std::stoi(result[i][5]);
        row_producto[m_Columns_prod.precio_u] = result[i][6] == "NULL" ? 0 : std::stod(result[i][6]);
        row_producto[m_Columns_prod.categoria] = result[i][7];
        cell_categoria->property_placeholder_text() = result[i][7];
        row_producto[m_Columns_prod.subcategoria] = result[i][8];
    }

    result.clear();

    cont_prod = m_refTreeModel_prod->children().size();
    lbl_cont_prod->set_text("Productos: " + std::to_string(cont_prod));
}

void Pos::on_cell_marca_changed(int response_id, const Glib::ustring& path_string, const Gtk::TreeModel::iterator& val)
{
    switch (response_id)
    {
    case Gtk::ResponseType::OK:
    {
        Gtk::TreeModel::iterator iter = m_refTreeModel_prod->get_iter(path_string);
        if (iter)
        {
            db->command("update producto set marca = '" + (*val)[m_ColumnsCombo.m_col_name].operator Glib::ustring() + "' where sku = " + std::to_string((*iter)[m_Columns_prod.sku]));
            row_producto = *iter;
            row_producto[m_Columns_prod.marca] = (*val)[m_ColumnsCombo.m_col_name].operator Glib::ustring();
        }
        dialog->close();
    }
    break;
    case Gtk::ResponseType::CANCEL:
        dialog->close();
        break;

    default:
        dialog->close();
        break;
    }
}

void Pos::on_cell_categoria_changed(int response_id, const Glib::ustring& path_string, const Gtk::TreeModel::iterator& val)
{
    switch (response_id)
    {
    case Gtk::ResponseType::OK:
    {
        Gtk::TreeModel::iterator iter = m_refTreeModel_prod->get_iter(path_string);
        if (iter)
        {
            db->command("update producto set categoria = '" + (*val)[m_ColumnsCategoria.m_col_name].operator Glib::ustring() + "' where sku = " + std::to_string((*iter)[m_Columns_prod.sku]));
            row_producto = *iter;
            row_producto[m_Columns_prod.categoria] = (*val)[m_ColumnsCategoria.m_col_name].operator Glib::ustring();
            if (subcategoria_map.find((*val)[m_ColumnsCategoria.m_col_name].operator Glib::ustring()) != subcategoria_map.end())
            {
                m_refTreeModelSubCategoria = Gtk::ListStore::create(m_ColumnsSubCategoria);
                for (auto& sub : subcategoria_map[(*val)[m_ColumnsCategoria.m_col_name].operator Glib::ustring()])
                {
                    row_subcategoria = *(m_refTreeModelSubCategoria->append());
                    row_subcategoria[m_ColumnsSubCategoria.m_col_name] = sub;
                }
                cell_subcategoria->property_model() = m_refTreeModelSubCategoria;
            }
        }
        dialog->close();
    }
    break;
    case Gtk::ResponseType::CANCEL:
        dialog->close();
        break;

    default:
        dialog->close();
        break;
    }
}

void Pos::on_cell_subcategoria_changed(int response_id, const Glib::ustring& path_string, const Gtk::TreeModel::iterator& val)
{
    switch (response_id)
    {
    case Gtk::ResponseType::OK:
    {
        Gtk::TreeModel::iterator iter = m_refTreeModel_prod->get_iter(path_string);
        if (iter)
        {
            db->command("update producto set subcategoria = '" + (*val)[m_ColumnsSubCategoria.m_col_name].operator Glib::ustring() + "' where sku = " + std::to_string((*iter)[m_Columns_prod.sku]));
            row_producto = *iter;
            row_producto[m_Columns_prod.subcategoria] = (*val)[m_ColumnsSubCategoria.m_col_name].operator Glib::ustring();
        }
        dialog->close();
    }
    break;
    case Gtk::ResponseType::CANCEL:
        dialog->close();
        break;

    default:
        dialog->close();
        break;
    }
}

void Pos::on_cell_data_func_u(Gtk::CellRenderer* renderer, const Gtk::TreeModel::const_iterator& iter)
{
    if (iter)
    {
        double value = (*iter)[m_Columns_prod.precio_u];
        char buffer[32];
        sprintf(buffer, "$%.2f", value);
        cell_precio_u->property_text() = buffer;
    }
}

void Pos::on_btn_remove_prod_clicked()
{
    dialog.reset(new Gtk::MessageDialog(*this, "Eliminar", true, Gtk::MessageType::QUESTION, Gtk::ButtonsType::CANCEL, true));
    dialog->set_secondary_text("¿Desea eliminar el producto?");
    dialog->add_button("Eliminar", Gtk::ResponseType::OK)->set_css_classes({ "destructive-action" });
    dialog->signal_response().connect([this](int response)
        {
            if (response == Gtk::ResponseType::OK) {
                auto iter = tree_prod->get_selection()->get_selected();
                if (iter) {
                    db->command("delete from producto where sku = " + std::to_string((*iter)[m_Columns_prod.sku]));
                    m_refTreeModel_prod->erase(iter);
                    lbl_cont_prod->set_text("Productos: " + std::to_string(m_refTreeModel_prod->children().size()));
                }
            }
            dialog->close(); });
    dialog->show();
}

void Pos::on_produ_dialog_edit_response(int response_id, const Glib::ustring& path_string, const Glib::ustring& new_text, const int& column)
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
                {
                    auto sku_nue = std::stol(new_text);
                    auto sku_ant = std::to_string((*iter)[m_Columns_prod.sku]);
                    if ((*iter)[m_Columns_prod.sku] != sku_nue && (*iter)[m_Columns_prod.sku] != 0)
                    {
                        std::cout << "insert into producto (sku,nombre,caducidad,marca,nota,piezas,precio_u,categoria,subcategoria) select " + new_text + ",nombre,caducidad,marca,nota,piezas,precio_u,categoria,subcategoria from producto where sku = " + sku_ant << std::endl;
                        db->command("insert into producto (sku,nombre,caducidad,marca,nota,piezas,precio_u,categoria,subcategoria) select " + new_text + ",nombre,caducidad,marca,nota,piezas,precio_u,categoria,subcategoria from producto where sku = " + sku_ant + "");
                        db->command("delete from producto where sku = " + sku_ant);
                    }
                    else
                        db->command("Insert into producto (sku) values (" + new_text + ")");

                    (*iter)[m_Columns_prod.sku] = sku_nue;
                }
                break;

                case COLUMNS::ColumnProducto::NOMBRE_PRODUCTO:
                {
                    db->command("update producto set nombre = '" + new_text + "' where sku = " + std::to_string((*iter)[m_Columns_prod.sku]));
                    (*iter)[m_Columns_prod.nombre] = new_text;
                }
                break;

                case COLUMNS::ColumnProducto::CADUCIDAD:
                {

                    db->command("update producto set caducidad = DATE('" + new_text + "') where sku = " + std::to_string((*iter)[m_Columns_prod.sku]));
                    (*iter)[m_Columns_prod.caducidad] = new_text;
                    break;
                }
                case COLUMNS::ColumnProducto::MARCA:
                {
                    db->command("update producto set marca = '" + new_text + "' where sku = " + std::to_string((*iter)[m_Columns_prod.sku]));
                    (*iter)[m_Columns_prod.marca] = new_text;
                    break;
                }
                case COLUMNS::ColumnProducto::NOTA:
                {
                    db->command("update producto set nota = '" + new_text + "' where sku = " + std::to_string((*iter)[m_Columns_prod.sku]));
                    (*iter)[m_Columns_prod.nota] = new_text;
                    break;
                }
                case COLUMNS::ColumnProducto::PIEZAS:
                {
                    db->command("update producto set piezas = " + new_text + " where sku = " + std::to_string((*iter)[m_Columns_prod.sku]));
                    (*iter)[m_Columns_prod.piezas] = std::stoi(new_text);
                    break;
                }
                case COLUMNS::ColumnProducto::PRECIO_U:
                {
                    db->command("update producto set precio_u = " + new_text + " where sku = " + std::to_string((*iter)[m_Columns_prod.sku]));
                    (*iter)[m_Columns_prod.precio_u] = std::stod(new_text);
                    break;
                }
                case COLUMNS::ColumnProducto::CATEGORIA:
                {
                    db->command("update producto set categoria = '" + new_text + "' where sku = " + std::to_string((*iter)[m_Columns_prod.sku]));
                    (*iter)[m_Columns_prod.categoria] = new_text;
                    break;
                }
                case COLUMNS::ColumnProducto::SUBCATEGORIA:
                {
                    db->command("update producto set subcategoria = '" + new_text + "' where sku = " + std::to_string((*iter)[m_Columns_prod.sku]));
                    (*iter)[m_Columns_prod.subcategoria] = new_text;
                    break;
                }
                }
            }
            catch (std::exception& e)
            {
                std::cout << e.what() << std::endl;
                dialog_error.reset(new Gtk::MessageDialog(*this, "Error al editar un Registro", false, Gtk::MessageType::ERROR, Gtk::ButtonsType::OK, true));
                dialog_error->set_secondary_text(e.what());
                dialog_error->signal_response().connect([this](int response)
                    { dialog_error->close(); });
                dialog_error->set_hide_on_close(true);
                dialog_error->show();
            }
        }
        dialog->close();
    }
    break;
    case Gtk::ResponseType::CANCEL:
        dialog->close();
        break;
    default:
        dialog->close();
        break;
    }
}

void Pos::cierra_dialogo(int response_id)
{
    dialog->close();
}

void Pos::init_popover_articulo()
{
    Gtk::Box b(Gtk::Orientation::VERTICAL);
    b.append(ety_articulo_popover);
    b.append(lbl_articulo_popover);
    b.append(spin_cantidad_articulo_popover);
    b.append(btn_add_articulo_popover);
    b.set_spacing(5);
    popover_ingreso_articulos.set_child(b);
    popover_ingreso_articulos.set_position(Gtk::PositionType::TOP);
    popover_ingreso_articulos.set_parent(*btn_add_piezas);
    btn_add_articulo_popover.set_label("Agregar");
    ety_articulo_popover.set_placeholder_text("Inserte el SKU del articulo");
}

void Pos::add_articulo_venta_popover()
{
    try
    {
        for (auto row : m_refTreeModel_prod->children())
        {
            if (row[m_Columns_prod.sku] == std::stoll(ety_articulo_popover.get_text()))
            {
                lbl_articulo_popover.set_text(row[m_Columns_prod.nombre]);
                break;
            }
        }
        ety_articulo_popover.set_text("");
        lbl_articulo_popover.set_text("");
        spin_cantidad_articulo_popover.set_value(0);
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void Pos::add_btn_articulo_venta_popover()
{
    if (lbl_articulo_popover.get_text().empty() || spin_cantidad_articulo_popover.get_value() == 0 || ety_articulo_popover.get_text().empty())
    {
        dialog.reset(new Gtk::MessageDialog(*this, "Error al agregar articulo", false, Gtk::MessageType::ERROR, Gtk::ButtonsType::OK, true));
        dialog->set_secondary_text("No se puede agregar un articulo sin nombre, sin cantidad o sin SKU");
        dialog->signal_response().connect([this](int response)
            { dialog->close(); });
        dialog->set_hide_on_close(true);
        dialog->show();
        return;
    }
    else
    {
        popover_ingreso_articulos.popdown();
        dialog.reset(new Gtk::MessageDialog(*this, "Agregar articulo", false, Gtk::MessageType::QUESTION, Gtk::ButtonsType::YES_NO, true));
        dialog->set_secondary_text("¿Desea agregar " + std::to_string(spin_cantidad_articulo_popover.get_value_as_int()) + ", " + lbl_articulo_popover.get_text() + " a la venta?");
        dialog->signal_response().connect([this](int response)
            { if (response == Gtk::ResponseType::YES)
        {
            db->command("update producto set piezas = piezas + " + std::to_string(spin_cantidad_articulo_popover.get_value_as_int()) + " where sku = " + ety_articulo_popover.get_text());
            for (auto row : m_refTreeModel_prod->children())
            {
                if (row[m_Columns_prod.sku] == std::stoll(ety_articulo_popover.get_text()))
                {
                    row[m_Columns_prod.piezas] = (row[m_Columns_prod.piezas]) + spin_cantidad_articulo_popover.get_value_as_int();
                    break;
                }
            }
        }
            else if (response == Gtk::ResponseType::NO)
        {
            dialog->close();
        }
        dialog->close();
        dialog->set_default_response(Gtk::ResponseType::NO);
            });
        dialog->show();
    }
}

void Pos::llena_subca()
{

    const char* aba[] = {
        "Aceite comestibles",
        "Aderezos",
        "Consome",
        "Crema de cacahuate",
        "Crema para café",
        "Pure de tomate",
        "Alimento para bebe",
        "Alimento para mascotas",
        "Atole",
        "Avena",
        "Azúcar",
        "Café",
        "Cereales",
        "Chile piquín",
        "Especias",
        "Flan en polvo",
        "Formulas infantiles",
        "Gelatinas en polvo/Grenetina",
        "Harina",
        "Harina preparada",
        "Mole",
        "Sal",
        "Salsas envasadas",
        "Sazonadores",
        "Sopas en sobre",
        "Cajeta",
        "Catsup",
        "Mayonesa",
        "Mermelada",
        "Miel",
        "Te",
        "Vinagre",
        "Huevo",
        "Pastas" };
    const char* enlatados[] = {

        "Aceitunas",
        "Chícharo con zanahoria",
        "Chícharos enlatados",
        "Frijoles enlatados",
        "Frutas en almíbar",
        "Sardinas",
        "Atún en agua/aceite",
        "Chiles enlatados",
        "Chiles envasados",
        "Ensaladas enlatadas",
        "Granos de elote enlatados",
        "Sopa en lata",
        "Vegetales en conserva",
    };
    const char* lacteos[] = {

        "Leche condensada",
        "Leche deslactosada",
        "Leche en polvo",
        "Leche evaporada",
        "Leche Light",
        "Leche pasteurizada",
        "Leche saborizada",
        "Leche semidescremada",
        "Crema",
        "Yoghurt",
        "Mantequilla",
        "Margarina",
        "Media crema",
        "Queso" };
    const char* dulces[] = {

        "Caramelos",
        "Dulces enchilados",
        "Chocolate de mesa",
        "Chocolate en polvo",
        "Chocolates",
        "Gomas de mascar",
        "Mazapán",
        "Malvaviscos",
        "Pulpa de tamarindo",
        "Pastillas de dulce",
        "Paletas de dulce" };
    const char* harinas[] = {
        "Tortillas de harina/maíz",
        "Galletas dulces",
        "Galletas saladas",
        "Pastelillos",
        "Pan de caja",
        "Pan dulce",
        "Pan molido",
        "Pan tostado" };
    const char* verduras[] = {
        "Aguacates",
        "Ajos",
        "Cebollas",
        "Chiles",
        "Cilantro/Perejil",
        "Jitomate",
        "Papas",
        "Limones",
        "Manzanas",
        "Naranjas",
        "Plátanos" };
    const char* alcohol[] = {
        "Bebidas preparadas",
        "Cerveza",
        "Anís",
        "Brandy",
        "Ginebra",
        "Cordiales",
        "Mezcal",
        "Jerez",
        "Ron",
        "Tequila",
        "Sidra",
        "Whiskey",
        "Vodka" };
    const char* bebidas[] = {
        "Agua mineral",
        "Agua natural",
        "Agua saborizada",
        "Jarabes",
        "Jugos/Néctares",
        "Naranjadas",
        "Bebidas de soya",
        "Bebidas en polvo",
        "Bebidas infantiles",
        "Bebidas isotónicas",
        "Energetizantes",
        "Isotónicos",
        "Refrescos" };
    const char* preparado[] = {

        "Pastas listas para comer",
        "Sopas en vaso",
        "Carnes y Embutidos",
        "Salchicha",
        "Mortadela",
        "Tocino",
        "Jamón",
        "Manteca",
        "Chorizo",
        "Carne de puerco/res/pollo" };
    const char* automedicacion[] = {
        "Suero",
        "Agua oxigenada",
        "Preservativos",
        "Alcohol",
        "Gasas",
        "Analgésicos",
        "Antigripales",
        "Antiácidos" };
    const char* personal[] = {
        "Toallas húmedas",
        "Aceite para bebe",
        "Toallas femeninas",
        "Algodón",
        "Tinte para el cabello",
        "Biberones",
        "Talco",
        "Cepillo de dientes",
        "Shampoo/ Acondicionador",
        "Cotonetes",
        "Rastrillos",
        "Crema corporal/facial",
        "Papel higiénico",
        "Crema para afeitar",
        "Pañuelos faciales",
        "Dentífricos",
        "Pañuelos desechables",
        "Desodorantes en barra/aerosol",
        "Maquillaje",
        "Enjuague bucal",
        "Lubricantes para labios",
        "Gel/spray",
        "Loción hidratante",
        "Jabones corporales/tocador" };
    const char* domestico[] = {
        "Suavizante de telas",
        "Ácido muriático",
        "Sosa caustica",
        "Aluminio",
        "Pilas",
        "Shampoo para ropa",
        "Servilletas",
        "Servitoallas",
        "Aromatizantes",
        "Cera para automóvil",
        "Cera para calzados",
        "Pastillas sanitarias",
        "Limpiadores líquidos",
        "Limpiadores para pisos",
        "Jabón de barra",
        "Cerillos",
        "Cloro/Blanqueador",
        "Cloro para ropa",
        "Insecticidas",
        "Fibras limpiadoras",
        "Desinfectantes",
        "Detergentes para trastes",
        "Detergente para ropa" };
    const char* limpieza[] = {
        "Veladoras/Velas",
        "Cepillo de plástico",
        "Vasos desechables",
        "Cinta adhesiva",
        "Cucharas de plástico",
        "Escobas/Trapeadores/Mechudos",
        "Trampas para ratas",
        "Tenedores de plástico",
        "Extensiones/Multicontacto",
        "Recogedor de metal/plástico",
        "Popotes",
        "Platos desechables",
        "Focos",
        "Fusibles",
        "Jergas/Franelas",
        "Matamoscas",
        "Pegamento",
        "Mecate/cuerda" };
    const char* botanas[] = {

        "Papas",
        "Palomitas",
        "Frituras de maíz",
        "Cacahuates",
        "Botanas saladas",
        "Barras alimenticias",
        "Nueces y semillas" };
    const char* otros[] = {
        "Tarjetas telefónicas",
        "Recargas móviles",
        "Hielo",
        "Cigarros" };

    std::vector<std::string> abarrote;
    std::vector<std::string> enlatado;
    std::vector<std::string> lacteo;
    std::vector<std::string> dulce;
    std::vector<std::string> harina;
    std::vector<std::string> verdura;
    std::vector<std::string> alcoho;
    std::vector<std::string> bebida;
    std::vector<std::string> preparad;
    std::vector<std::string> automedicacio;
    std::vector<std::string> persona;
    std::vector<std::string> domestic;
    std::vector<std::string> limpiez;
    std::vector<std::string> botan;
    std::vector<std::string> otro;

    for (size_t i = 0; i < G_N_ELEMENTS(aba); i++)
    {
        abarrote.emplace_back(aba[i]);
    }
    for (size_t i = 0; i < G_N_ELEMENTS(enlatados); i++)
    {
        enlatado.emplace_back(enlatados[i]);
    }
    for (size_t i = 0; i < G_N_ELEMENTS(lacteos); i++)
    {
        lacteo.emplace_back(lacteos[i]);
    }
    for (size_t i = 0; i < G_N_ELEMENTS(dulces); i++)
    {
        dulce.emplace_back(dulces[i]);
    }
    for (size_t i = 0; i < G_N_ELEMENTS(harinas); i++)
    {
        harina.emplace_back(harinas[i]);
    }
    for (size_t i = 0; i < G_N_ELEMENTS(verduras); i++)
    {
        verdura.emplace_back(verduras[i]);
    }
    for (size_t i = 0; i < G_N_ELEMENTS(alcohol); i++)
    {
        alcoho.emplace_back(alcohol[i]);
    }
    for (size_t i = 0; i < G_N_ELEMENTS(bebidas); i++)
    {
        bebida.emplace_back(bebidas[i]);
    }
    for (size_t i = 0; i < G_N_ELEMENTS(preparado); i++)
    {
        preparad.emplace_back(preparado[i]);
    }
    for (size_t i = 0; i < G_N_ELEMENTS(automedicacion); i++)
    {
        automedicacio.emplace_back(automedicacion[i]);
    }
    for (size_t i = 0; i < G_N_ELEMENTS(personal); i++)
    {
        persona.emplace_back(personal[i]);
    }
    for (size_t i = 0; i < G_N_ELEMENTS(domestico); i++)
    {
        domestic.emplace_back(domestico[i]);
    }
    for (size_t i = 0; i < G_N_ELEMENTS(limpieza); i++)
    {
        limpiez.emplace_back(limpieza[i]);
    }
    for (size_t i = 0; i < G_N_ELEMENTS(botanas); i++)
    {
        botan.emplace_back(botanas[i]);
    }
    for (size_t i = 0; i < G_N_ELEMENTS(otros); i++)
    {
        otro.emplace_back(otros[i]);
    }

    subcategoria_map["Abarrotes"] = abarrote;
    subcategoria_map["Enlatados"] = enlatado;
    subcategoria_map["Lácteos"] = lacteo;
    subcategoria_map["Dulces"] = dulce;
    subcategoria_map["Harinas"] = harina;
    subcategoria_map["Verduras"] = verdura;
    subcategoria_map["Alcohol"] = alcoho;
    subcategoria_map["Bebidas"] = bebida;
    subcategoria_map["Preparados"] = preparad;
    subcategoria_map["Automedicación"] = automedicacio;
    subcategoria_map["Personal"] = persona;
    subcategoria_map["Doméstico"] = domestic;
    subcategoria_map["Limpieza"] = limpiez;
    subcategoria_map["Botanas"] = botan;
    subcategoria_map["Otros"] = otro;

    auto iter_C = Gtk::TreeModel::iterator();

    for (const auto& list : subcategoria_map)
    {
        iter_C = m_refTreeModelCategoria->append();
        (*iter_C)[m_ColumnsCategoria.m_col_name] = list.first;
    }
}

bool Pos::add_match_producto(const Gtk::TreeModel::iterator& iter)
{
    ety_articulo_popover.set_text(std::to_string((*iter)[m_Columns_prod.sku]));
    lbl_articulo_popover.set_text((*iter)[m_Columns_prod.nombre]);
    spin_cantidad_articulo_popover.set_value(0);
    return true;
}