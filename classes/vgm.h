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

    /* Execute queries to database
     * Input: containers for answer
     * Output: - */
    void Quiry(std::map<QString, QString> &cont);

    /* Filling class`s variables
     * Input: containers with data from database
     * Output: - */
    void Filling(std::map<QString, QString> cont);

    /* Clear variables dependent from nail boards
     * Input: -
     * Output: - */
    void ClearNailBoards();

    /* Clear variables dependent from side bar
     * Input: -
     * Output: - */
    void ClearSideBar();

public:
    VGM(VGM_DB db);
    virtual ~VGM();

    /* Check answer from form and data from database
     * Input: structure with data from form
     * Output: logical structure with data about true each variables */
    form_answer_VGM CheckAnswer(form_VGM);
    void SetWeight(double number);
    void SetNailBoards(QString string);
    void SetSideBar(QString string);
    void SetWidthTrack(QString string);

    VGM_DB* GetDB();
};

#endif // VGM_H
