#ifndef USER_DB_H
#define USER_DB_H
#include "driver/db.h"
#include "../classes/test.h"

class UserDB : public DB {

public:
    UserDB(QString);
    UserDB();
    virtual ~UserDB() {}

    /* Insert data to user table
     * Input: user object
     * Output: - */
    void SetUser(User object_user);

    /* Get data from user table
     * Input: container for info hold
     * Output: - */
    void GetUsers(std::vector<User> &cont);

    /* Insert data to test table
     * Input: user object, equipment name, grade
     * Output: - */
    void SetAttempt(User object_user, QString name_equipment, QString grade);

    /* Get data from test table
     * Input: container for info hold
     * Output: - */
    void GetAttempts(std::vector<Test> &cont);

    /* Get id
     * Input: -
     * Output: id */
    unsigned int GetId();

    /* Get equipment name from equipment table
     * Input: -
     * Output: equipment name */
    QString GetEquipment();
};

#endif // PROJECTBD_H
