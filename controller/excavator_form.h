#ifndef EXCAVATOR_FORM_H
#define EXCAVATOR_FORM_H

#include <QWidget>
#include "base/base_technics.h"
#include "../classes/excavator.h"
#include "../classes/test.h"
#include "../functions/validation.h"

namespace Ui {
class Excavator_Form;
}

class Excavator_Form : public QWidget, base_technics
{
    Q_OBJECT

public:
    explicit Excavator_Form(ExcavatorDB db, User u, QWidget *parent = nullptr);
    ~Excavator_Form();

signals:
    void firstWindow();

private slots:
    /* Pressing "To main window" button
     * Input: -
     * Output: - */
    void on_pushButton_2_clicked();

    /* Pressing "Done" button
     * Input: -
     * Output: - */
    void on_pushButton_clicked();

    void on_lineEdit_7_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_7_editingFinished();

    void on_lineEdit_9_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_9_editingFinished();

    void on_lineEdit_11_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_11_editingFinished();

    void on_lineEdit_13_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_13_editingFinished();

    void on_lineEdit_15_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_15_editingFinished();

    void on_comboBox_activated(int index);

    void on_lineEdit_5_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_5_editingFinished();

    void on_lineEdit_6_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_6_editingFinished();

    void on_lineEdit_16_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_16_editingFinished();

    void on_lineEdit_editingFinished();

    void on_lineEdit_3_editingFinished();

    void on_comboBox_highlighted(int index);

private:
    Ui::Excavator_Form *ui;
    Excavator *object_excavator;
    User object_user;
    QString name;
    unsigned int count;

    /* Filling а structure from form`s items
     * Input: structure
     * Output: - */
    void FillingFormExcavator(form_excavator &object_form);

    /* Cheking logical structure
     * Input: structure
     * Output: - */
    bool CheckAnswer(form_answer_excavator form);

    /* Doing items` color are black
     * Input: -
     * Output: - */
    void Default();

    /* Set up image in the form
     * Input: -
     * Output: - */
    void set_image() override;

    /* Showing graphics
     * Input: -
     * Output: - */
    void show_graphics();

    /* Functions with graphics
     * Input: pen
     * Output: - */
    void SM_swilev_cursor(QPen);
    void SM_undercarriage_cursor(QPen);
    void SM_root_cursor(QPen);
    void SM_handle_cursor(QPen);
    void SM_trolley_cursor(QPen);
    void lining_cursor(QPen);
    void arrow_cursor(QPen);
    void axis_turnover_cursor(QPen);
    void axis_longitudinal_cursor(QPen);

    void SM_swilev(QPen);
    void SM_undercarriage(QPen);
    void SM_root(QPen);
    void SM_handle(QPen);
    void SM_trolley(QPen);
    void bar_thrust(QPen);
    void bar_side(QPen);
    void lining(QPen);
};

#endif // EXCAVATOR_FORM_H
