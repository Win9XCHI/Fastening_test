#ifndef MOTORGRADER_H
#define MOTORGRADER_H
#include "equipment.h"
#include "../model/motorgrader_db.h"

class MotorGrader : Equipment {
    MotorGraderDB DB;

    /* Execute queries to database
     * Input: containers for answer
     * Output: - */
    void Quiry(std::map<QString, QString> &cont, std::map<QString, Dimensions> &contD);

    /* Filling class`s variables
     * Input: containers with data from database
     * Output: - */
    void Filling(std::map<QString, QString> cont, std::map<QString, Dimensions> contD);

public:
    MotorGrader(MotorGraderDB db);
    virtual ~MotorGrader();

    /* Check answer from form and data from database
     * Input: structure with data from form
     * Output: logical structure with data about true each variables */
    form_answer_motorgrader CheckAnswer(form_motorgrader);
    MotorGraderDB* GetDB();
};

#endif // MOTORGRADER_H
