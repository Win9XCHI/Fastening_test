#include "user_db.h"

UserDB::UserDB(QString str) : DB(str) {
}

UserDB::UserDB() : DB() {
}

void UserDB::GetUsers(std::vector<User> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.push_back({query.value(rec.indexOf("Name")).toString(), query.value(rec.indexOf("Platoon")).toString(), query.value(rec.indexOf("id")).toUInt()});
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

void UserDB::SetUser(User object_user) {
    SELECT("*", "Student", "Name = '" + object_user.GetName() + "' AND Platoon = '" + object_user.GetPlatoon() + "'");
    std::vector<User> cont;
    GetUsers(cont);

    if (cont.size() == 0) {
        std::vector<QString> listColumns, listValue;
        listColumns.push_back("Name");
        listColumns.push_back("Platoon");
        listValue.push_back(object_user.GetName());
        listValue.push_back(object_user.GetPlatoon());
        Insert("Student", listColumns, listValue);
    }
}

void UserDB::SetAttempt(User object_user, QString name_equipment, QString grade) {
    SELECT("*", "Student", "Name = '" + object_user.GetName() + "' AND Platoon = '" + object_user.GetPlatoon() + "'");
    std::vector<User> cont;
    GetUsers(cont);
    SELECT("id", "Equipment", "Name = '" + name_equipment + "'");

    std::vector<QString> listColumns, listValue;
    listColumns.push_back("Date");
    listColumns.push_back("Grade");
    listColumns.push_back("Student_id");
    listColumns.push_back("Equipment_id");
    listValue.push_back(QDateTime::currentDateTime().toString("dd.MM.yyyy HH:mm:ss"));
    listValue.push_back(grade);
    listValue.push_back(QString::number(cont.at(0).GetId()));
    listValue.push_back(QString::number(GetEquipmentId()));
    Insert("Test", listColumns, listValue);
}
