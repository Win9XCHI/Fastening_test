#include "excavator_db.h"

ExcavatorDB::ExcavatorDB(QString str) : UserDB(str) {
}

ExcavatorDB::ExcavatorDB() : UserDB() {
}

/* Get icon from equipment table
 * Input: -
 * Output: icon */
QString ExcavatorDB::GetIcon() {
    QSqlRecord rec = query.record();
    query.next();
    return query.value(rec.indexOf("Icon")).toString();
}

/* Get data from conditions table
 * Input: container for info hold
 * Output: - */
void ExcavatorDB::GetGeneralValue(std::map<QString, QString> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.insert({query.value(rec.indexOf("Name")).toString(), query.value(rec.indexOf("Value")).toString()});
    }
}

/* Get data from FromTo table
 * Input: container for info hold
 * Output: - */
void ExcavatorDB::GetFromToValue(std::map<QString, FromTo> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.insert({query.value(rec.indexOf("Name")).toString(), {query.value(rec.indexOf("From")).toDouble(), query.value(rec.indexOf("To")).toDouble()}});
    }
}

/* Get data from YesNo table
 * Input: container for info hold
 * Output: - */
void ExcavatorDB::GetYesNoValue(std::map<QString, QString> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.insert({query.value(rec.indexOf("Name")).toString(), query.value(rec.indexOf("Answer")).toString()});
    }
}
