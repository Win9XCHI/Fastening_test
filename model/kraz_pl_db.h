#ifndef KRAZ_PL_DB_H
#define KRAZ_PL_DB_H
#include "driver/db.h"
#include "../classes/dimensions.h"
#include "../classes/fromto.h"

class KRAZ_pl_DB : public DB {

public:
    KRAZ_pl_DB(QString);
    KRAZ_pl_DB();
    virtual ~KRAZ_pl_DB() {}

    QString GetIcon();
    void GetGeneralValue(std::map<QString, QString> &cont);
    void GetDimensionsValue(std::map<QString, Dimensions> &cont);
    void GetFromToValue(std::map<QString, FromTo> &cont);
};

#endif // PROJECTBD_H
