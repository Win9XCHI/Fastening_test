#include "vgm_db.h"

VGM_DB::VGM_DB(QString str) : UserDB(str) {
}

VGM_DB::VGM_DB() : UserDB() {
}

/*SELECT Icon FROM Equipment WHERE Name = 'Танк';*/
QString VGM_DB::GetIcon() {
    QSqlRecord rec = query.record();
    query.next();
    return query.value(rec.indexOf("Icon")).toString();
}

/* SELECT Con.Value, Cha.Name FROM Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN
 * Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Equ.Name = 'Танк' AND Con.Value NOT NULL AND
 * Con.Conditions_id IS NULL AND Cha.Name != 'Вага ВГМ';
*/

/* SELECT Con.Value, Cha.Name FROM Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN
 * Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Con.Conditions_id =
 * (SELECT Con.id FROM Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN
 * Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Equ.Name = 'Танк' AND Con.Value = '...');
*/
void VGM_DB::GetValue(std::map<QString, QString> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.insert({query.value(rec.indexOf("Name")).toString(), query.value(rec.indexOf("Value")).toString()});
    }
}

/* SELECT Con.Value FROM Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN
 * Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Equ.Name = 'Танк' AND Con.Value NOT NULL AND
 * Con.Conditions_id IS NULL AND Cha.Name = 'Вага ВГМ';
*/
void VGM_DB::GetWeightValue(std::vector<QString> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.push_back(query.value(rec.indexOf("Value")).toString());
    }
}

/* SELECT D.Thickness, D.Width, D.Length, Cha.Name FROM Dimensions AS D JOIN Conditions AS Con ON
 * Con.id = D.Conditions_id JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN
 * Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Equ.Name = 'ВГМ на платформі' AND Con.Conditions_id IS NULL;
*/

/* SELECT D.Thickness, D.Width, D.Length, Cha.Name FROM Dimensions AS D JOIN Conditions AS Con ON
 * Con.id = D.Conditions_id JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN
 * Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Con.Conditions_id =
 * (SELECT Con.id FROM Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN
 * Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Con.Value = '...' AND
 * Cha.Name = '...' AND Con.Conditions_id = (SELECT Con.id FROM Conditions AS Con JOIN Characteristic AS Cha ON
 * Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE
 * Equ.Name = 'ВГМ на платформі' AND Con.Value = '...'));
*/
void VGM_DB::GetDimensionsValue(std::map<QString, Dimensions> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.insert({query.value(rec.indexOf("Name")).toString(), {query.value(rec.indexOf("Thickness")).toDouble(), query.value(rec.indexOf("Width")).toDouble(), query.value(rec.indexOf("Length")).toDouble()}});
    }
}

/* SELECT Ft."From", Ft."To", Cha.Name FROM FromTo AS Ft JOIN Conditions AS Con ON Con.id = Ft.Conditions_id JOIN
 * Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Con.Conditions_id =
 * (SELECT Con.id FROM Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id =
 * Cha.Equipment_id WHERE Con.Value = 'Бокові бруски' AND Cha.Name =
 * 'Чим будете кріпити ВГМ від поперечного зміщення при відкритих бортах платформи' AND Con.Conditions_id =
 * (SELECT Con.id FROM Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id =
 * Cha.Equipment_id WHERE Equ.Name = 'ВГМ на платформі' AND Con.Value = '...'));
 */
void VGM_DB::GetFromToValue(std::map<QString, FromTo> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.insert({query.value(rec.indexOf("Name")).toString(), {query.value(rec.indexOf("From")).toDouble(), query.value(rec.indexOf("To")).toDouble()}});
    }
}

