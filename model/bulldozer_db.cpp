#include "bulldozer_db.h"

BulldozerDB::BulldozerDB(QString str) : UserDB(str) {
}

BulldozerDB::BulldozerDB() : UserDB() {
}

/* Get icon from equipment table
 * Input: -
 * Output: icon */
QString BulldozerDB::GetIcon() {
    QSqlRecord rec = query.record();
    query.next();
    return query.value(rec.indexOf("Icon")).toString();
}

/* Get data from conditions table
 * Input: container for info hold
 * Output: - */
void BulldozerDB::GetValue(std::map<QString, QString> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.insert({query.value(rec.indexOf("Name")).toString(), query.value(rec.indexOf("Value")).toString()});
    }
}

/* Get data from YesNo table
 * Input: container for info hold
 * Output: - */
void BulldozerDB::GetYesNoValue(std::map<QString, QString> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.insert({query.value(rec.indexOf("Name")).toString(), query.value(rec.indexOf("Answer")).toString()});
    }
}

/* Get data from dimensions table
 * Input: container for info hold
 * Output: - */
void BulldozerDB::GetDimensionsValue(std::map<QString, Dimensions> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.insert({query.value(rec.indexOf("Name")).toString(), {query.value(rec.indexOf("Thickness")).toDouble(), query.value(rec.indexOf("Width")).toDouble(), query.value(rec.indexOf("Length")).toDouble()}});
    }
}

/* Get weight from conditions table
 * Input: container for info hold
 * Output: - */
void BulldozerDB::GetWeightValue(std::vector<QString> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.push_back(query.value(rec.indexOf("Value")).toString());
    }
}

/* Get data from FromTo table
 * Input: container for info hold
 * Output: - */
void BulldozerDB::GetFromToValue(std::map<QString, FromTo> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.insert({query.value(rec.indexOf("Name")).toString(), {query.value(rec.indexOf("From")).toDouble(), query.value(rec.indexOf("To")).toDouble()}});
    }
}
