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

    /* Get data from user table
     * Input: container for info hold
     * Output: - */
    void GetUsers(std::list<User> &cont);

    /* Get data from test table
     * Input: container for info hold
     * Output: - */
    void GetAttempts(std::list<Test> &cont);

    /* Get data from equipment table
     * Input: container for info hold
     * Output: - */
    void GetEquipments(std::list<QString> &cont);

    /* Get data from conditions table
     * Input: container for info hold
     * Output: - */
    void GetValue(std::multimap<QString, QString> &cont);

    /* Get data from YesNo table
     * Input: container for info hold
     * Output: - */
    void GetYesNoValue(std::multimap<QString, QString> &cont);

    /* Get data from dimensions table
     * Input: container for info hold
     * Output: - */
    void GetDimensionsValue(std::multimap<QString, Dimensions> &cont);

    /* Get data from FromTo table
     * Input: container for info hold
     * Output: - */
    void GetFromToValue(std::multimap<QString, FromTo> &cont);

    /* Get type from characteristic table
     * Input: -
     * Output: type */
    QString GetTypeValue();

    /* Get id
     * Input: container for info hold
     * Output: - */
    void GetId(std::vector<unsigned int> &cont);
};

#endif // PROJECTBD_H
