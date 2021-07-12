#ifndef DB_H
#define DB_H

#include <QtSql>
#include <QDebug>
#include <map>
#include "../../exceptions/database_exception.h"
#include "../../structure.h"

class DB {
protected:
    QSqlDatabase db;
    QSqlQuery query;

    int size;

public:
    DB(QString);
    DB();
    virtual ~DB() {}

    //Create database connection
    //Input: -
    //Output: Created or not
    bool createConnection();

    //Check database connection
    //Input: -
    //Output: Created or not
    bool CheckConnection();

    //Close database connection
    //Input: -
    //Output: -
    void close();

    //Return last error in database
    //Input: -
    //Output: string with error
    QString LastError();

    //Return size returned records after query SELECT
    //Input: -
    //Output: size
    int GetSize();

    //Delete records in table
    //Input: table name, definition
    //Output: Query done or not
    bool DeleteRecord(QString table_name, QString definition = "");

    //Execute query SELECT
    //Input: columns, table name, definition, limit, order by
    //Output: Query done or not
    bool SELECT(QString columns, QString table_name, QString definition = "", QString limit = "", QString order_by = "");

    //Execute query UPDATE
    //Input: table name, values, definition
    //Output: Query done or not
    bool UPDATE(QString table_name, QString values, QString definition);

    //Insert record in table
    //Input: table name, columns, values
    //Output: Query done or not
    bool INSERT(QString table_name, std::vector<QString> columns, std::vector<QString> values);

    //Create new table
    //Input: table name, array: name, type and rule for columns
    //Output: -
    void CREATE_TABLE(QString table_name, std::vector<std::vector<QString>> columns);

    //Drop table
    //Input: table name
    //Output: -
    void DROP(QString table_name);

};

#endif // DB_H
