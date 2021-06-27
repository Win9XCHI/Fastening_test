#ifndef MOTORGRADER_DB_H
#define MOTORGRADER_DB_H
#include "driver/db.h"
#include "../classes/dimensions.h"

class MotorGraderDB : public DB {

public:
    MotorGraderDB(QString);
    MotorGraderDB();
    virtual ~MotorGraderDB() {}

    QString GetIcon();
    void GetGeneralValue(std::map<QString, QString> &cont);
    void GetDimensionsValue(std::map<QString, Dimensions> &cont);
    void GetYesNoValue(std::map<QString, QString> &cont);
};

#endif // PROJECTBD_H
