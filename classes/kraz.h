#ifndef KRAZ_H
#define KRAZ_H
#include "equipment.h"
#include "../model/kraz_db.h"

class KRAZ : Equipment {
    KRAZ_DB DB;

    /* Execute queries to database
     * Input: containers for answer
     * Output: - */
    void Quiry(std::map<QString, QString> &cont, std::map<QString, FromTo> &contFT, std::map<QString, Dimensions> &contD);

    /* Filling class`s variables
     * Input: containers with data from database
     * Output: - */
    void Filling(std::map<QString, QString> cont, std::map<QString, FromTo> contFT, std::map<QString, Dimensions> contD);

public:
    KRAZ(KRAZ_DB db);
    virtual ~KRAZ();

    /* Check answer from form and data from database
     * Input: structure with data from form
     * Output: logical structure with data about true each variables */
    form_answer_KRAZ CheckAnswer(form_KRAZ);
    KRAZ_DB* GetDB();
};

#endif // KRAZ_H
