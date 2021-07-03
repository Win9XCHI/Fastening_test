#include "scraper_db.h"

ScraperDB::ScraperDB(QString str) : UserDB(str) {
}

ScraperDB::ScraperDB() : UserDB() {
}

/*SELECT Icon FROM Equipment WHERE Name = 'Скрепер Д-357П на платформі';*/
QString ScraperDB::GetIcon() {
    QSqlRecord rec = query.record();
    query.next();
    return query.value(rec.indexOf("Icon")).toString();
}

/*SELECT Con.Value, Cha.Name FROM Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment
 * AS Equ ON Equ.id = Cha.Equipment_id WHERE Equ.Name = 'Скрепер Д-357П на платформі' AND Con.Value NOT NULL;*/
void ScraperDB::GetGeneralValue(std::map<QString, QString> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.insert({query.value(rec.indexOf("Name")).toString(), query.value(rec.indexOf("Value")).toString()});
    }
}

/*SELECT Yn.Answer, Cha.Name FROM YesNo AS Yn JOIN Conditions AS Con ON Con.id = Yn.Conditions_id JOIN Characteristic AS Cha ON Cha.id =
 * Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Equ.Name = 'Скрепер Д-357П на платформі';*/
void ScraperDB::GetYesNoValue(std::map<QString, QString> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.insert({query.value(rec.indexOf("Name")).toString(), query.value(rec.indexOf("Answer")).toString()});
    }
}

/*SELECT D.Thickness, D.Width, D.Length, Cha.Name FROM Dimensions AS D JOIN Conditions AS Con ON Con.id = D.Conditions_id JOIN Characteristic AS Cha ON Cha.id =
 * Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Equ.Name = 'Скрепер Д-357П на платформі'*/
void ScraperDB::GetDimensionsValue(std::map<QString, Dimensions> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.insert({query.value(rec.indexOf("Name")).toString(), {query.value(rec.indexOf("Thickness")).toDouble(), query.value(rec.indexOf("Width")).toDouble(), query.value(rec.indexOf("Length")).toDouble()}});
    }
}
