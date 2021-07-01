#ifndef VGM_DB_H
#define VGM_DB_H
#include "driver/db.h"

class VGM_DB : public DB {

public:
    VGM_DB(QString);
    VGM_DB();
    virtual ~VGM_DB() {}

    QString GetIcon();
    void GetValue(std::map<QString, QString> &cont);
    void GetWeightValue(std::vector<QString> &cont);
};

#endif // PROJECTBD_H
