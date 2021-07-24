#ifndef KRAZ_PL_H
#define KRAZ_PL_H
#include "equipment.h"
#include "../model/kraz_pl_db.h"

class KRAZ_pl : Equipment {
    KRAZ_pl_DB DB;

    /* Execute queries to database
     * Input: containers for answer
     * Output: - */
    void Quiry(std::map<QString, QString> &cont, std::map<QString, FromTo> &contFT, std::map<QString, Dimensions> &contD);

    /* Filling class`s variables
     * Input: containers with data from database
     * Output: - */
    void Filling(std::map<QString, QString> cont, std::map<QString, FromTo> contFT, std::map<QString, Dimensions> contD);

public:
    KRAZ_pl(KRAZ_pl_DB db);
    virtual ~KRAZ_pl();

    /* Check answer from form and data from database
     * Input: structure with data from form
     * Output: logical structure with data about true each variables */
    form_answer_KRAZ_pl CheckAnswer(form_KRAZ_pl);
    KRAZ_pl_DB* GetDB();
};

#endif // KRAZ_PL_H
