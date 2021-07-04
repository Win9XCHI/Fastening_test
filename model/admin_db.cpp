#include "admin_db.h"

AdminDB::AdminDB(QString str) : DB(str) {
}

AdminDB::AdminDB() : DB() {
}

void AdminDB::GetUsers(std::list<User> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.push_back({query.value(rec.indexOf("Name")).toString(), query.value(rec.indexOf("Platoon")).toString(), query.value(rec.indexOf("id")).toUInt()});
    }
}

void AdminDB::GetAttempts(std::list<Test> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.push_back({{query.value(rec.indexOf("st_name")).toString(), query.value(rec.indexOf("Platoon")).toString()}, query.value(rec.indexOf("Grade")).toString(), query.value(rec.indexOf("Date")).toString(), query.value(rec.indexOf("eq_name")).toString()});
    }
}

void AdminDB::GetEquipments(std::list<QString> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.push_back(query.value(rec.indexOf("Name")).toString());
    }
}

void AdminDB::GetValue(std::multimap<QString, QString> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.insert({query.value(rec.indexOf("Name")).toString(), query.value(rec.indexOf("Value")).toString()});
    }
}

void AdminDB::GetYesNoValue(std::multimap<QString, QString> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.insert({query.value(rec.indexOf("Name")).toString(), query.value(rec.indexOf("Answer")).toString()});
    }
}

void AdminDB::GetDimensionsValue(std::multimap<QString, Dimensions> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.insert({query.value(rec.indexOf("Name")).toString(), {query.value(rec.indexOf("Thickness")).toDouble(), query.value(rec.indexOf("Width")).toDouble(), query.value(rec.indexOf("Length")).toDouble()}});
    }
}

void AdminDB::GetFromToValue(std::multimap<QString, FromTo> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.insert({query.value(rec.indexOf("Name")).toString(), {query.value(rec.indexOf("From")).toDouble(), query.value(rec.indexOf("To")).toDouble()}});
    }
}

QString AdminDB::GetTypeValue() {
    QSqlRecord rec = query.record();
    query.next();
    return query.value(rec.indexOf("Type")).toString();
}

void AdminDB::GetId(std::vector<unsigned int> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.push_back(query.value(rec.indexOf("id")).toUInt());
    }
}
