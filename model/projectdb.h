#ifndef PROJECTDB_H
#define PROJECTDB_H

#include <QtSql>
#include <QDebug>
#include <map>
#include <string>
#include "driver/db.h"

class ProjectDB : public DB {

public:
    ProjectDB(QString);
    ProjectDB();
    virtual ~ProjectDB() {}

};

#endif // PROJECTBD_H
