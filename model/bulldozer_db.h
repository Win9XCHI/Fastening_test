#ifndef BULLDOZER_DB_H
#define BULLDOZER_DB_H
#include "user_db.h"
#include "../classes/dimensions.h"
#include "../classes/fromto.h"

class BulldozerDB : public UserDB {

public:
    BulldozerDB(QString);
    BulldozerDB();
    virtual ~BulldozerDB() {}

    /* Get icon from equipment table
     * Input: -
     * Output: icon */
    QString GetIcon();

    /* Get data from conditions table
     * Input: container for info hold
     * Output: - */
    void GetValue(std::map<QString, QString> &cont);

    /* Get data from YesNo table
     * Input: container for info hold
     * Output: - */
    void GetYesNoValue(std::map<QString, QString> &cont);

    /* Get data from dimensions table
     * Input: container for info hold
     * Output: - */
    void GetDimensionsValue(std::map<QString, Dimensions> &cont);

    /* Get data from FromTo table
     * Input: container for info hold
     * Output: - */
    void GetFromToValue(std::map<QString, FromTo> &cont);

    /* Get weight from conditions table
     * Input: container for info hold
     * Output: - */
    void GetWeightValue(std::vector<QString> &cont);
};

#endif // PROJECTBD_H
