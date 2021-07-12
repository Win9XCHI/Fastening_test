#include "kraz_pl_db.h"

KRAZ_pl_DB::KRAZ_pl_DB(QString str) : UserDB(str) {
}

KRAZ_pl_DB::KRAZ_pl_DB() : UserDB() {
}

/* Get icon from equipment table
 * Input: -
 * Output: icon */
QString KRAZ_pl_DB::GetIcon() {
    QSqlRecord rec = query.record();
    query.next();
    return query.value(rec.indexOf("Icon")).toString();
}

/* Get data from conditions table
 * Input: container for info hold
 * Output: - */
void KRAZ_pl_DB::GetGeneralValue(std::map<QString, QString> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.insert({query.value(rec.indexOf("Name")).toString(), query.value(rec.indexOf("Value")).toString()});
    }
}

/* Get data from FromTo table
 * Input: container for info hold
 * Output: - */
void KRAZ_pl_DB::GetFromToValue(std::map<QString, FromTo> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.insert({query.value(rec.indexOf("Name")).toString(), {query.value(rec.indexOf("From")).toDouble(), query.value(rec.indexOf("To")).toDouble()}});
    }
}

/* Get data from dimensions table
 * Input: container for info hold
 * Output: - */
void KRAZ_pl_DB::GetDimensionsValue(std::map<QString, Dimensions> &cont) {
    QSqlRecord rec = query.record();

    while(query.next()) {
        cont.insert({query.value(rec.indexOf("Name")).toString(), {query.value(rec.indexOf("Thickness")).toDouble(), query.value(rec.indexOf("Width")).toDouble(), query.value(rec.indexOf("Length")).toDouble()}});
    }
}
