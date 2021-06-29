#ifndef SCRAPER_H
#define SCRAPER_H
#include "equipment.h"
#include "../model/scraper_db.h"

class Scraper : Equipment {
    ScraperDB DB;

    void Quiry(std::map<QString, QString> &cont, std::map<QString, Dimensions> &contD);
    void Filling(std::map<QString, QString> cont, std::map<QString, Dimensions> contD);

public:
    Scraper(ScraperDB db);
    virtual ~Scraper();

    form_answer_scraper CheckAnswer(form_scraper);
};

#endif // SCRAPER_H
