#ifndef EXCAVATOR_DB_H
#define EXCAVATOR_DB_H

#include <QtSql>
#include <QDebug>
#include <map>
#include "driver/db.h"
#include "../structure.h"
#include "../classes/dimensions.h"
#include "../exceptions/database_exception.h"

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
