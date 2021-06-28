#ifndef BULLDOZER_H
#define BULLDOZER_H
#include "equipment.h"
#include "../model/bulldozer_db.h"

class Bulldozer : Equipment {
    BulldozerDB DB;
    QString weight;
    QString nail_boards;
    QString side_bar;
    unsigned int wire_diameter;
    QString width_track;
    bool width_trackYesNo;

    void Quiry(std::map<QString, QString> &cont, std::map<QString, Dimensions> &contD);
    void Filling(std::map<QString, QString> cont, std::map<QString, Dimensions> contD);

public:
    Bulldozer(BulldozerDB db);
    virtual ~Bulldozer();

    form_answer_bulldozer CheckAnswer(form_bulldozer);
    void SetWeight(QString string);
    void SetNailBoards(QString string);
    void SetSideBar(QString string);
    void ClearNailBoards();
    void ClearSideBar();
    void SetWidthTrack(QString string);
};

#endif // BULLDOZER_H
