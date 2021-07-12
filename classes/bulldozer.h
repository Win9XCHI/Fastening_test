#ifndef BULLDOZER_H
#define BULLDOZER_H
#include "equipment.h"
#include "../model/bulldozer_db.h"

class Bulldozer : Equipment {
    BulldozerDB DB;
    QString weight;
    QString nail_boards;
    QString side_bar;
    QString width_track;
    bool width_trackYesNo;

    /* Execute queries to database
     * Input: containers for answer
     * Output: - */
    void Quiry(std::map<QString, QString> &cont, std::map<QString, Dimensions> &contD);

    /* Filling class`s variables
     * Input: containers with data from database
     * Output: - */
    void Filling(std::map<QString, QString> cont, std::map<QString, Dimensions> contD);

    /* Clear variables dependent from nail boards
     * Input: -
     * Output: - */
    void ClearNailBoards();

    /* Clear variables dependent from side bar
     * Input: -
     * Output: - */
    void ClearSideBar();

public:
    Bulldozer(BulldozerDB db);
    virtual ~Bulldozer();

    /* Check answer from form and data from database
     * Input: structure with data from form
     * Output: logical structure with data about true each variables */
    form_answer_bulldozer CheckAnswer(form_bulldozer);
    void SetWeight(QString string);
    void SetNailBoards(QString string);
    void SetSideBar(QString string);
    void SetWidthTrack(QString string);

    BulldozerDB* GetDB();
};

#endif // BULLDOZER_H
