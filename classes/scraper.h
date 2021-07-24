#ifndef SCRAPER_H
#define SCRAPER_H
#include "equipment.h"
#include "../model/scraper_db.h"

class Scraper : Equipment {
    ScraperDB DB;

    /* Execute queries to database
     * Input: containers for answer
     * Output: - */
    void Quiry(std::map<QString, QString> &cont, std::map<QString, Dimensions> &contD);

    /* Filling class`s variables
     * Input: containers with data from database
     * Output: - */
    void Filling(std::map<QString, QString> cont, std::map<QString, Dimensions> contD);

public:
    Scraper(ScraperDB db);
    virtual ~Scraper();

    /* Check answer from form and data from database
     * Input: structure with data from form
     * Output: logical structure with data about true each variables */
    form_answer_scraper CheckAnswer(form_scraper);
    ScraperDB* GetDB();
};

#endif // SCRAPER_H
