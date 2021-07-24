#ifndef KRAZ_DB_H
#define KRAZ_DB_H
#include "user_db.h"
#include "../classes/dimensions.h"
#include "../classes/fromto.h"

class KRAZ_DB : public UserDB {

public:
    KRAZ_DB(QString);
    KRAZ_DB();
    virtual ~KRAZ_DB() {}

    /* Get icon from equipment table
     * Input: -
     * Output: icon */
    QString GetIcon();

    /* Get data from conditions table
     * Input: container for info hold
     * Output: - */
    void GetGeneralValue(std::map<QString, QString> &cont);

    /* Get data from dimensions table
     * Input: container for info hold
     * Output: - */
    void GetDimensionsValue(std::map<QString, Dimensions> &cont);

    /* Get data from FromTo table
     * Input: container for info hold
     * Output: - */
    void GetFromToValue(std::map<QString, FromTo> &cont);
};

#endif // PROJECTBD_H
