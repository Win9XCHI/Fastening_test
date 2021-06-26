#ifndef EXCAVATOR_H
#define EXCAVATOR_H
#include "equipment.h"
#include "structure.h"

class Excavator : public Equipment {
    unsigned int wire_diameter;
    unsigned int boom_height;
    double axis_turnover;
    double axis_longitudinal;

public:
    Excavator();

    bool CheckAnswer(form_excavator);
};

#endif // EXCAVATOR_H
