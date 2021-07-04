#ifndef ADMIN_DB_H
#define ADMIN_DB_H
#include "driver/db.h"
#include "../classes/test.h"
#include "../classes/dimensions.h"
#include "../classes/fromto.h"

class AdminDB : public DB {

public:
    AdminDB(QString);
    AdminDB();
    virtual ~AdminDB() {}

    void GetUsers(std::list<User> &cont);
    void GetAttempts(std::list<Test> &cont);
    void GetEquipments(std::list<QString> &cont);
    void GetValue(std::multimap<QString, QString> &cont);
    void GetYesNoValue(std::multimap<QString, QString> &cont);
    void GetDimensionsValue(std::multimap<QString, Dimensions> &cont);
    void GetFromToValue(std::multimap<QString, FromTo> &cont);
    QString GetTypeValue();
    void GetId(std::vector<unsigned int> &cont);
};

#endif // PROJECTBD_H
