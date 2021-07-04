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

    void GetUsers(std::vector<User> &cont);
    void GetAttempts(std::vector<Test> &cont);
    void GetEquipments(std::vector<QString> &cont);
    void GetValue(std::map<QString, QString> &cont);
    void GetYesNoValue(std::map<QString, QString> &cont);
    void GetDimensionsValue(std::map<QString, Dimensions> &cont);
    void GetFromToValue(std::map<QString, FromTo> &cont);
};

#endif // PROJECTBD_H
