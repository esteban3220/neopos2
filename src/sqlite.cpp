#include "sqlite.hpp"
#include <fstream>

std::vector<std::vector<std::string>> result;

SQLite::SQLite()
{
    db = nullptr;
}

SQLite::~SQLite()
{
    sqlite3_close(db);
}

bool SQLite::open()
{
    std::ifstream file("dbase.db");

    if(!file)
    {
        rc = sqlite3_open("dbase.db", &db);
        command("CREATE TABLE proveedor (id integer primary key AUTOINCREMENT,nombre text DEFAULT \"\", numero integer,empresa text DEFAULT \"\",correo text DEFAULT \"\")");
        command("CREATE TABLE producto (sku integer primary key,nombre text,caducidad text DEFAULT \"\",marca text DEFAULT \"\",nota text DEFAULT \"\",piezas integer DEFAULT 0, precio_u real,categoria text DEFAULT \"\",subcategoria text DEFAULT \"\", granel INTEGER DEFAULT 0)");
        command("CREATE TABLE venta(id integer PRIMARY KEY AUTOINCREMENT, tipo text, total real ,ingreso real, cambio real,folio text, fecha text, datos text)");
        command("CREATE TABLE data_conf(razon text,direccion text,rfc text,contacto text,regreat text)");
        command("CREATE TABLE conf(v1 integer,v2 integer,v3 integer,v4 integer,v5 integer,v6 integer,v7 integer)");

        command("INSERT INTO conf VALUES(0,0,0,0,0,0,0)");
        command("INSERT INTO data_conf VALUES(\"\",\"\",\"\",\"\",\"\")");

        return true;
    }


    rc = sqlite3_open("dbase.db", &db);
    if (rc)
    {
        std::cout << "Error al abrir la base de datos: " << sqlite3_errmsg(db) << std::endl;
        return false;
    }
    else
    {
        std::cout << "Base de datos abierta correctamente" << std::endl;
        return true;
    }
}

int SQLite::callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    std::vector<std::string> row;
    for (size_t i = 0; i < argc; i++)
    {
        row.emplace_back(argv[i] ? argv[i] : "NULL");
    }
    ::result.emplace_back(row);
    return 0;
}

void SQLite::command(std::string sql)
{
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
    if (rc != SQLITE_OK)
    {
        std::string error = "SQL error: " + std::string(zErrMsg) + "\nSQL: " + sql + "\n";
        sqlite3_free(zErrMsg);
        throw std::runtime_error(error);
    }
    else
    {
        std::cout << "Operacion realizada correctamente" << std::endl;
        std::cout << "SQL: " << sql << std::endl;
    }
} 

std::vector<std::vector<std::string>> SQLite::get_result() const
{
    return ::result;
}

int SQLite::get_rc() const
{
    return rc;
}

void SQLite::clear_result()
{
    ::result.clear();
}