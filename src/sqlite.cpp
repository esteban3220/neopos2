#include "sqlite.hpp"

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
        // printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL")
        row.push_back(argv[i] ? argv[i] : "NULL");
    }
    result.emplace_back(row);
    return 0;
}

void SQLite::command(std::string sql)
{
    rc = sqlite3_exec(db, sql.c_str(), callback, 0, &zErrMsg);
    if (rc != SQLITE_OK)
    {
        std::cout << "SQL error: " << zErrMsg << std::endl
                  << "SQL: " << sql << std::endl;
        sqlite3_free(zErrMsg);
    }
    else
    {
        std::cout << "Operacion realizada correctamente" << std::endl;
    }
}

std::vector<std::vector<std::string>> SQLite::get_result() const
{
    return result;
}