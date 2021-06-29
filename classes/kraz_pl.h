#ifndef KRAZ_PL_H
#define KRAZ_PL_H
#include "equipment.h"
#include "../model/kraz_pl_db.h"

class KRAZ_pl : Equipment {
    KRAZ_pl_DB DB;
    double kg;
    double pog;

    void Quiry(std::map<QString, QString> &cont, std::map<QString, FromTo> &contFT, std::map<QString, Dimensions> &contD);
    void Filling(std::map<QString, QString> cont, std::map<QString, FromTo> contFT, std::map<QString, Dimensions> contD);

public:
    KRAZ_pl(KRAZ_pl_DB db);
    virtual ~KRAZ_pl();

    form_answer_KRAZ_pl CheckAnswer(form_KRAZ_pl);
};

#endif // KRAZ_PL_H
