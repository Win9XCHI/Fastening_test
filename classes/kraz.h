#ifndef KRAZ_H
#define KRAZ_H
#include "equipment.h"
#include "../model/kraz_db.h"

class KRAZ : Equipment {
    KRAZ_DB DB;

    void Quiry(std::map<QString, QString> &cont, std::map<QString, FromTo> &contFT, std::map<QString, Dimensions> &contD);
    void Filling(std::map<QString, QString> cont, std::map<QString, FromTo> contFT, std::map<QString, Dimensions> contD);

public:
    KRAZ(KRAZ_DB db);
    virtual ~KRAZ();

    form_answer_KRAZ CheckAnswer(form_KRAZ);
};

#endif // KRAZ_H
