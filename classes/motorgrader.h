#ifndef MOTORGRADER_H
#define MOTORGRADER_H
#include "equipment.h"
#include "../model/motorgrader_db.h"

class MotorGrader : Equipment {
    MotorGraderDB DB;
    unsigned int wire_diameter;

    void Quiry(std::map<QString, QString> &cont, std::map<QString, Dimensions> &contD);
    void Filling(std::map<QString, QString> cont, std::map<QString, Dimensions> contD);

public:
    MotorGrader(MotorGraderDB db);
    virtual ~MotorGrader();

    form_answer_motorgrader CheckAnswer(form_motorgrader);
};

#endif // MOTORGRADER_H
