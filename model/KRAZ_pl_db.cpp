#include "kraz_pl_db.h"

KRAZ_pl_DB::KRAZ_pl_DB(QString str) : UserDB(str) {
}

KRAZ_pl_DB::KRAZ_pl_DB() : UserDB() {
}

/*SELECT Icon FROM Equipment WHERE Name = 'КрАЗ-256 порожній на платформі';*/
QString KRAZ_pl_DB::GetIcon() {
    QSqlRecord rec = query.record();
    query.next();
    return query.value(rec.indexOf("Icon")).toString();
}

/*SELECT Con.Value, Cha.Name FROM Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment
 * AS Equ ON Equ.id = Cha.Equipment_id WHERE Equ.Name = 'КрАЗ-256 порожній на платформі' AND Con.Value NOT NULL;*/
void KRAZ_pl_DB::GetGeneralValue(std::map<QString, QString> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.insert({query.value(rec.indexOf("Name")).toString(), query.value(rec.indexOf("Value")).toString()});
    }
}

/*SELECT Ft."From", Ft."To", Cha.Name FROM FromTo AS Ft JOIN Conditions AS Con ON Con.id = Ft.Conditions_id JOIN Characteristic AS Cha ON Cha.id =
 * Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Equ.Name = 'КрАЗ-256 порожній на платформі';*/
void KRAZ_pl_DB::GetFromToValue(std::map<QString, FromTo> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.insert({query.value(rec.indexOf("Name")).toString(), {query.value(rec.indexOf("From")).toDouble(), query.value(rec.indexOf("To")).toDouble()}});
    }
}

/*SELECT D.Thickness, D.Width, D.Length, Cha.Name FROM Dimensions AS D JOIN Conditions AS Con ON Con.id = D.Conditions_id JOIN Characteristic AS Cha ON Cha.id =
 * Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Equ.Name = 'КрАЗ-256 порожній на платформі'*/
void KRAZ_pl_DB::GetDimensionsValue(std::map<QString, Dimensions> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.insert({query.value(rec.indexOf("Name")).toString(), {query.value(rec.indexOf("Thickness")).toDouble(), query.value(rec.indexOf("Width")).toDouble(), query.value(rec.indexOf("Length")).toDouble()}});
    }
}
