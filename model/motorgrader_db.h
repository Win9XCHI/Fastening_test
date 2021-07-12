#ifndef MOTORGRADER_DB_H
#define MOTORGRADER_DB_H
#include "user_db.h"
#include "../classes/dimensions.h"

class MotorGraderDB : public UserDB {

public:
    MotorGraderDB(QString);
    MotorGraderDB();
    virtual ~MotorGraderDB() {}

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

    /* Get data from YesNo table
     * Input: container for info hold
     * Output: - */
    void GetYesNoValue(std::map<QString, QString> &cont);
};

#endif // PROJECTBD_H
