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
