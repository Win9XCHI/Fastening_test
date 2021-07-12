#include "motorgrader_db.h"

MotorGraderDB::MotorGraderDB(QString str) : UserDB(str) {
}

MotorGraderDB::MotorGraderDB() : UserDB() {
}

/* Get icon from equipment table
 * Input: -
 * Output: icon */
QString MotorGraderDB::GetIcon() {
    QSqlRecord rec = query.record();
    query.next();
    return query.value(rec.indexOf("Icon")).toString();
}

/* Get data from conditions table
 * Input: container for info hold
 * Output: - */
void MotorGraderDB::GetGeneralValue(std::map<QString, QString> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.insert({query.value(rec.indexOf("Name")).toString(), query.value(rec.indexOf("Value")).toString()});
    }
}

/* Get data from YesNo table
 * Input: container for info hold
 * Output: - */
void MotorGraderDB::GetYesNoValue(std::map<QString, QString> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.insert({query.value(rec.indexOf("Name")).toString(), query.value(rec.indexOf("Answer")).toString()});
    }
}

/* Get data from dimensions table
 * Input: container for info hold
 * Output: - */
void MotorGraderDB::GetDimensionsValue(std::map<QString, Dimensions> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.insert({query.value(rec.indexOf("Name")).toString(), {query.value(rec.indexOf("Thickness")).toDouble(), query.value(rec.indexOf("Width")).toDouble(), query.value(rec.indexOf("Length")).toDouble()}});
    }
}
