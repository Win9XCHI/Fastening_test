#include "excavator_db.h"

ExcavatorDB::ExcavatorDB(QString str) : UserDB(str) {
}

ExcavatorDB::ExcavatorDB() : UserDB() {
}

/*SELECT Icon FROM Equipment WHERE Name = 'Екскаватор ЕО-4125 на платформі';*/
QString ExcavatorDB::GetIcon() {
    QSqlRecord rec = query.record();
    query.next();
    return query.value(rec.indexOf("Icon")).toString();
}

/*SELECT Con.Value, Cha.Name FROM Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment
 * AS Equ ON Equ.id = Cha.Equipment_id WHERE Equ.Name = 'Екскаватор ЕО-4125 на платформі' AND Con.Value NOT NULL;*/
void ExcavatorDB::GetGeneralValue(std::map<QString, QString> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.insert({query.value(rec.indexOf("Name")).toString(), query.value(rec.indexOf("Value")).toString()});
    }
}

/*SELECT Ft."From", Ft."To", Cha.Name FROM FromTo AS Ft JOIN Conditions AS Con ON Con.id = Ft.Conditions_id JOIN Characteristic AS Cha ON Cha.id =
 * Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Equ.Name = 'Екскаватор ЕО-4125 на платформі';*/
void ExcavatorDB::GetFromToValue(std::map<QString, FromTo> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.insert({query.value(rec.indexOf("Name")).toString(), {query.value(rec.indexOf("From")).toDouble(), query.value(rec.indexOf("To")).toDouble()}});
    }
}

/*SELECT Yn.Answer, Cha.Name FROM YesNo AS Yn JOIN Conditions AS Con ON Con.id = Yn.Conditions_id JOIN Characteristic AS Cha ON Cha.id =
 * Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Equ.Name = 'Екскаватор ЕО-4125 на платформі';*/
void ExcavatorDB::GetYesNoValue(std::map<QString, QString> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.insert({query.value(rec.indexOf("Name")).toString(), query.value(rec.indexOf("Answer")).toString()});
    }
}
