#ifndef USER_DB_H
#define USER_DB_H
#include "driver/db.h"
#include "../classes/test.h"

class UserDB : public DB {

public:
    UserDB(QString);
    UserDB();
    virtual ~UserDB() {}

    void SetUser(QString name, QString platoon);
    void GetUsers(std::vector<User> &cont);
    void SetAttempt(unsigned int user_id, QString result, QString time);
    void GetAttempts(std::vector<Test> &cont);
    unsigned int GetEquipmentId();
    QString GetEquipment();
};

#endif // PROJECTBD_H
