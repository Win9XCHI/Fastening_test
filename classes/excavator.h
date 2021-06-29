#ifndef EXCAVATOR_H
#define EXCAVATOR_H
#include "equipment.h"
#include "../model/excavator_db.h"

class Excavator : Equipment {
    ExcavatorDB DB;

    unsigned int boom_height;
    double axis_turnover;
    double axis_longitudinal;
    Lining *object_lining;

    void Quiry(std::map<QString, QString> &cont, std::map<QString, FromTo> &contFT);
    void Filling(std::map<QString, QString> cont, std::map<QString, FromTo> contFT);

public:
    Excavator(ExcavatorDB db);
    virtual ~Excavator();

    form_answer_excavator CheckAnswer(form_excavator);
};

#endif // EXCAVATOR_H
