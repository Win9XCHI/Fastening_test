#ifndef EXCAVATOR_DB_H
#define EXCAVATOR_DB_H
#include "user_db.h"
#include "../classes/fromto.h"

class ExcavatorDB : public UserDB {

public:
    ExcavatorDB(QString);
    ExcavatorDB();
    virtual ~ExcavatorDB() {}

    /* Get icon from equipment table
     * Input: -
     * Output: icon */
    QString GetIcon();

    /* Get data from conditions table
     * Input: container for info hold
     * Output: - */
    void GetGeneralValue(std::map<QString, QString> &cont);

    /* Get data from FromTo table
     * Input: container for info hold
     * Output: - */
    void GetFromToValue(std::map<QString, FromTo> &cont);

    /* Get data from YesNo table
     * Input: container for info hold
     * Output: - */
    void GetYesNoValue(std::map<QString, QString> &cont);
};

#endif // PROJECTBD_H
