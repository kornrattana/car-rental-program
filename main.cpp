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
    rc = sqlite3_open("data.db", &db);
    if( rc ){

        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        exit(0);
    }else{

        fprintf(stderr, "Opened database successfully\n");
    }

    printf("Test basic queries");


    sqlite3_close(db);
    return 0;
}
