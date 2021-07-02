#include "user_db.h"

UserDB::UserDB(QString str) : DB(str) {
}

UserDB::UserDB() : DB() {
}

void UserDB::GetUsers(std::vector<User> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.push_back({query.value(rec.indexOf("id")).toUInt(), query.value(rec.indexOf("Name")).toString(), query.value(rec.indexOf("Platoon")).toString()});
    }
}

void UserDB::GetAttempts(std::vector<Test> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.push_back({query.value(rec.indexOf("id")).toUInt(), query.value(rec.indexOf("Student_id")).toUInt(), query.value(rec.indexOf("Grade")).toString(), query.value(rec.indexOf("Date")).toString(), query.value(rec.indexOf("Equipment_id")).toUInt()});
    }
}

unsigned int UserDB::GetEquipmentId() {
    QSqlRecord rec = query.record();
    query.next();
    return query.value(rec.indexOf("id")).toUInt();
}

QString UserDB::GetEquipment() {
    QSqlRecord rec = query.record();
    query.next();
    return query.value(rec.indexOf("Name")).toString();
}
