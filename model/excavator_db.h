#ifndef EXCAVATOR_DB_H
#define EXCAVATOR_DB_H
#include "user_db.h"
#include "../classes/fromto.h"

class ExcavatorDB : public UserDB {

public:
    ExcavatorDB(QString);
    ExcavatorDB();
    virtual ~ExcavatorDB() {}

    QString GetIcon();
    void GetGeneralValue(std::map<QString, QString> &cont);
    void GetFromToValue(std::map<QString, FromTo> &cont);
    void GetYesNoValue(std::map<QString, QString> &cont);
};

#endif // PROJECTBD_H
