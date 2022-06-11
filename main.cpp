#include <iostream>
#include "sqlite3.h"
#include "string"

static int callback(void *data, int argc, char **argv, char **azColName){

    int i;
    fprintf(stderr, "%s: ", (const char*)data);
    for(i=0; i<argc; i++){

        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}


int main() {

    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;
    const char* data = "Callback function called";

    /* Open database */
    rc = sqlite3_open("data.sqlite", &db);
    if( rc ){

        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        exit(0);
    }else{

        fprintf(stderr, "Opened database successfully\n");
    }

    std::string sql_add_table = "CREATE TABLE PERSON("
                 "ID INT PRIMARY KEY     NOT NULL, "
                 "NAME           TEXT    NOT NULL, "
                 "SURNAME          TEXT     NOT NULL, "
                 "AGE            INT     NOT NULL, "
                 "ADDRESS        CHAR(50), "
                 "SALARY         REAL );";
    rc = sqlite3_exec(db, sql_add_table.c_str(), callback, (void*)data, &zErrMsg);
    if( rc != SQLITE_OK ){

        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }else{

        fprintf(stdout, "Table created successfully\n");
    }

    sqlite3_close(db);
    return 0;
}
