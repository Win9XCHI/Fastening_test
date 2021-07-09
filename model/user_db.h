#ifndef USER_DB_H
#define USER_DB_H
#include "driver/db.h"
#include "../classes/test.h"

class UserDB : public DB {

public:
    UserDB(QString);
    UserDB();
    virtual ~UserDB() {}

    void SetUser(User object_user);
    void GetUsers(std::vector<User> &cont);
    void SetAttempt(User object_user, QString name_equipment, QString grade);
    void GetAttempts(std::vector<Test> &cont);
    unsigned int GetEquipmentId();
    QString GetEquipment();
};

#endif // PROJECTBD_H
