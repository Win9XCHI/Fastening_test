#ifndef EXCAVATOR_H
#define EXCAVATOR_H
#include "equipment.h"
#include "../model/excavator_db.h"

class Excavator : Equipment {
    ExcavatorDB DB;

    unsigned int boom_height;
    double axis_turnover;
    double axis_longitudinal;

    /* Execute queries to database
     * Input: containers for answer
     * Output: - */
    void Quiry(std::map<QString, QString> &cont, std::map<QString, FromTo> &contFT);

    /* Filling class`s variables
     * Input: containers with data from database
     * Output: - */
    void Filling(std::map<QString, QString> cont, std::map<QString, FromTo> contFT);

public:
    Excavator(ExcavatorDB db);
    virtual ~Excavator();

    /* Check answer from form and data from database
     * Input: structure with data from form
     * Output: logical structure with data about true each variables */
    form_answer_excavator CheckAnswer(form_excavator);

    ExcavatorDB* GetDB();
};

#endif // EXCAVATOR_H
