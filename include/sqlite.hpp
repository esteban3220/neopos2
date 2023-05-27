#pragma once
#include <sqlite3.h>
#include <iostream>

class SQLite
{
private:
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    std::string sql;

public:
    SQLite();
    ~SQLite();
    bool open();
};

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
    rc = sqlite3_open("database.db", &db);
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
