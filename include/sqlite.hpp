#pragma once
#include <sqlite3.h>
#include <iostream>
#include <vector>


class SQLite
{
private:
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    std::string sql;
    static int callback(void *, int , char **, char **);

public:
    SQLite();
    ~SQLite();
    bool open();
    void command(std::string);
    int get_rc() const;
    std::vector<std::vector<std::string>> get_result() const;
    void clear_result();
};