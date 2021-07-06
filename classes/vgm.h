#ifndef VGM_H
#define VGM_H
#include "equipment.h"
#include "../model/vgm_db.h"

class VGM : Equipment {
    VGM_DB DB;
    QString weight;
    QString nail_boards;
    QString side_bar;
    QString width_track;
    bool width_trackYesNo;

    void Quiry(std::map<QString, QString> &cont);
    void Filling(std::map<QString, QString> cont);

public:
    VGM(VGM_DB db);
    virtual ~VGM();

    form_answer_VGM CheckAnswer(form_VGM);
    void SetWeight(double number);
    void SetNailBoards(QString string);
    void SetSideBar(QString string);
    void ClearNailBoards();
    void ClearSideBar();
    void SetWidthTrack(QString string);
};

#endif // VGM_H
