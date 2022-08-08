#include <iostream>
#include <Windows.h>
#include <sqlite3.h>
using namespace std;

static int createDB(const char *dir);
static int createTable(const char *dir);

int main()
{

    const char *dir = "D:\\PROJECTS\\C++\\First Project\\sqlite.db";
    sqlite3 *DB;

    createDB(dir);
    createTable(dir);

    return 0;
}

static int createDB(const char *dir)
{
    sqlite3 *DB;
    int exit = 0;

    exit = sqlite3_open(dir, &DB);
    sqlite3_close(DB);

    return 0;
}

static int createTable(const char *dir)
{

    sqlite3 *DB;

    string sql = "CREATE TABLE IF NOT EXISTS USERS("
                 "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
                 "NAME TEXT NOT NULL, "
                 "AGE INT NOT NULL);";

    int exit = 0;
    exit = sqlite3_open(dir, &DB);

    char *messaggeError{};
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError);

    if (exit != SQLITE_OK)
    {
        cerr << "Error creating table: " << messaggeError << endl;
        sqlite3_free(messaggeError);
    }
    else
    {
        cout << "Table created" << endl;
    }
    sqlite3_close(DB);

    return 0;
}