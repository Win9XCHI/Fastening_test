#ifndef VGM_DB_H
#define VGM_DB_H
#include "user_db.h"
#include "../classes/dimensions.h"
#include "../classes/fromto.h"

class VGM_DB : public UserDB {

public:
    VGM_DB(QString);
    VGM_DB();
    virtual ~VGM_DB() {}

    /* Get icon from equipment table
     * Input: -
     * Output: icon */
    QString GetIcon();

    /* Get data from conditions table
     * Input: container for info hold
     * Output: - */
    void GetValue(std::map<QString, QString> &cont);

    /* Get weight from conditions table
     * Input: container for info hold
     * Output: - */
    void GetWeightValue(std::vector<QString> &cont);

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
