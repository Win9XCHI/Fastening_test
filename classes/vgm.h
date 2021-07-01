#ifndef VGM_H
#define VGM_H
#include "equipment.h"
#include "../model/vgm_db.h"

class VGM : Equipment {
    VGM_DB DB;
    QString weight;
    unsigned int staple;

    void Quiry(std::map<QString, QString> &cont);
    void Filling(std::map<QString, QString> cont);

public:
    VGM(VGM_DB db);
    virtual ~VGM();

    form_answer_VGM CheckAnswer(form_VGM);
    void SetWeight(double number);
};

#endif // VGM_H
