#ifndef SCRAPER_DB_H
#define SCRAPER_DB_H
#include "user_db.h"
#include "../classes/dimensions.h"

class ScraperDB : public UserDB {

public:
    ScraperDB(QString);
    ScraperDB();
    virtual ~ScraperDB() {}

    QString GetIcon();
    void GetGeneralValue(std::map<QString, QString> &cont);
    void GetDimensionsValue(std::map<QString, Dimensions> &cont);
    void GetYesNoValue(std::map<QString, QString> &cont);
};

#endif // PROJECTBD_H
