#include "admin_db.h"

AdminDB::AdminDB(QString str) : DB(str) {
}

AdminDB::AdminDB() : DB() {
}

/* Get data from user table
 * Input: container for info hold
 * Output: - */
void AdminDB::GetUsers(std::list<User> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.push_back({query.value(rec.indexOf("Name")).toString(), query.value(rec.indexOf("Platoon")).toString(), query.value(rec.indexOf("id")).toUInt()});
    }
}

/* Get data from test table
 * Input: container for info hold
 * Output: - */
void AdminDB::GetAttempts(std::list<Test> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.push_back({{query.value(rec.indexOf("st_name")).toString(), query.value(rec.indexOf("Platoon")).toString()}, query.value(rec.indexOf("Grade")).toString(), query.value(rec.indexOf("Date")).toString(), query.value(rec.indexOf("eq_name")).toString()});
    }
}

/* Get data from equipment table
 * Input: container for info hold
 * Output: - */
void AdminDB::GetEquipments(std::list<QString> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.push_back(query.value(rec.indexOf("Name")).toString());
    }
}

/* Get data from conditions table
 * Input: container for info hold
 * Output: - */
void AdminDB::GetValue(std::multimap<QString, QString> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.insert({query.value(rec.indexOf("Name")).toString(), query.value(rec.indexOf("Value")).toString()});
    }
}

/* Get data from YesNo table
 * Input: container for info hold
 * Output: - */
void AdminDB::GetYesNoValue(std::multimap<QString, QString> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.insert({query.value(rec.indexOf("Name")).toString(), query.value(rec.indexOf("Answer")).toString()});
    }
}

/* Get data from dimensions table
 * Input: container for info hold
 * Output: - */
void AdminDB::GetDimensionsValue(std::multimap<QString, Dimensions> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.insert({query.value(rec.indexOf("Name")).toString(), {query.value(rec.indexOf("Thickness")).toDouble(), query.value(rec.indexOf("Width")).toDouble(), query.value(rec.indexOf("Length")).toDouble()}});
    }
}

/* Get data from FromTo table
 * Input: container for info hold
 * Output: - */
void AdminDB::GetFromToValue(std::multimap<QString, FromTo> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.insert({query.value(rec.indexOf("Name")).toString(), {query.value(rec.indexOf("From")).toDouble(), query.value(rec.indexOf("To")).toDouble()}});
    }
}

/* Get type from characteristic table
 * Input: -
 * Output: type */
QString AdminDB::GetTypeValue() {
    QSqlRecord rec = query.record();
    query.next();
    return query.value(rec.indexOf("Type")).toString();
}

/* Get id
 * Input: container for info hold
 * Output: - */
void AdminDB::GetId(std::vector<unsigned int> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.push_back(query.value(rec.indexOf("id")).toUInt());
    }
}
