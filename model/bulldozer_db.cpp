#include "bulldozer_db.h"

BulldozerDB::BulldozerDB(QString str) : DB(str) {
}

BulldozerDB::BulldozerDB() : DB() {
}

/*SELECT Icon FROM Equipment WHERE Name = 'Бульдозер на платформі';*/
QString BulldozerDB::GetIcon() {
    QSqlRecord rec = query.record();
    query.next();
    return query.value(rec.indexOf("Icon")).toString();
}

/* SELECT Con.Value, Cha.Name FROM Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN
 * Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Equ.Name = 'Бульдозер на платформі' AND Con.Value NOT NULL AND
 * Con.Conditions_id IS NULL AND Cha.Name != 'Вага бульдозера';
*/

/* SELECT Con.Value, Cha.Name FROM Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN
 * Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Equ.Name = 'Бульдозер на платформі' AND Con.Value NOT NULL AND
 * Cha.Name != 'Чим будуть прибивати бруски до платформи' AND Cha.Name !=
 * 'Чим будете кріпити бульдозер від поперечного зміщення при відкритих бортах платформи' AND Con.Conditions_id =
 * (SELECT Con.id FROM Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN
 * Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Equ.Name = 'Бульдозер на платформі' AND Con.Value = '...');
*/

/* SELECT Con.Value, Cha.Name FROM Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN
 * Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Equ.Name = 'Бульдозер на платформі' AND Con.Value NOT NULL AND
 * Con.Conditions_id = (SELECT Con.id FROM Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN
 * Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Equ.Name = 'Бульдозер на платформі' AND Con.Value = '...' AND
 * Cha.Name = '...' AND Con.Conditions_id = (SELECT Con.id FROM Conditions AS Con JOIN Characteristic AS Cha ON
 * Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Equ.Name = 'Бульдозер на платформі'
 * AND Con.Value = '...'));
*/
void BulldozerDB::GetValue(std::map<QString, QString> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.insert({query.value(rec.indexOf("Name")).toString(), query.value(rec.indexOf("Value")).toString()});
    }
}

/* SELECT Yn.Answer, Cha.Name FROM YesNo AS Yn JOIN Conditions AS Con ON Con.id = Yn.Conditions_id JOIN
 * Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE
 * Equ.Name = 'Бульдозер на платформі';
*/
void BulldozerDB::GetYesNoValue(std::map<QString, QString> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.insert({query.value(rec.indexOf("Name")).toString(), query.value(rec.indexOf("Answer")).toString()});
    }
}

/* SELECT D.Thickness, D.Width, D.Length, Cha.Name FROM Dimensions AS D JOIN Conditions AS Con ON
 * Con.id = D.Conditions_id JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN
 * Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Equ.Name = 'Бульдозер на платформі' AND Con.Conditions_id IS NULL;
*/

/* SELECT D.Thickness, D.Width, D.Length, Cha.Name FROM Dimensions AS D JOIN Conditions AS Con ON
 * Con.id = D.Conditions_id JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN
 * Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Equ.Name = 'Бульдозер на платформі' AND Con.Conditions_id =
 * (SELECT Con.id FROM Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN
 * Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Equ.Name = 'Бульдозер на платформі' AND Con.Value = '...' AND
 * Cha.Name = '...' AND Con.Conditions_id = (SELECT Con.id FROM Conditions AS Con JOIN Characteristic AS Cha ON
 * Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE
 * Equ.Name = 'Бульдозер на платформі' AND Con.Value = '...'));
*/
void BulldozerDB::GetDimensionsValue(std::map<QString, Dimensions> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.insert({query.value(rec.indexOf("Name")).toString(), {query.value(rec.indexOf("Thickness")).toDouble(), query.value(rec.indexOf("Width")).toDouble(), query.value(rec.indexOf("Length")).toDouble()}});
    }
}

/* SELECT Con.Value FROM Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN
 * Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Equ.Name = 'Бульдозер на платформі' AND Con.Value NOT NULL AND
 * Con.Conditions_id IS NULL AND Cha.Name = 'Вага бульдозера';
*/
void BulldozerDB::GetWeightValue(std::vector<QString> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.push_back(query.value(rec.indexOf("Value")).toString());
    }
}

/* SELECT COUNT(Con.Value) AS c FROM Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN
 * Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Equ.Name = 'Бульдозер на платформі' AND Con.Value = '...' AND Cha.Name = '...'
 * AND Con.Conditions_id = (SELECT Con.id FROM Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN
 * Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Equ.Name = 'Бульдозер на платформі' AND Con.Value = '...');
*/
bool BulldozerDB::Is_Value() {
    QSqlRecord rec = query.record();
    query.next();
    if (query.value(rec.indexOf("Name")) == 0) {
        return false;
    }
    return true;
}
