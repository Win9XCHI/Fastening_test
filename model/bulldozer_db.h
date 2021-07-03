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

    QString GetIcon();
    void GetValue(std::map<QString, QString> &cont);
    void GetYesNoValue(std::map<QString, QString> &cont);
    void GetDimensionsValue(std::map<QString, Dimensions> &cont);
    void GetFromToValue(std::map<QString, FromTo> &cont);
    void GetWeightValue(std::vector<QString> &cont);
    bool Is_Value();
};

#endif // PROJECTBD_H
