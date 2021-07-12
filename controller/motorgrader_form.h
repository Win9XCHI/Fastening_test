#ifndef MOTORGRADER_FORM_H
#define MOTORGRADER_FORM_H

#include <QWidget>
#include "base/base_technics.h"
#include "../classes/motorgrader.h"
#include "../classes/test.h"
#include "../functions/validation.h"

namespace Ui {
class MotorGrader_Form;
}

class MotorGrader_Form : public QWidget, base_technics
{
    Q_OBJECT

public:
    explicit MotorGrader_Form(MotorGraderDB db, User u, QWidget *parent = nullptr);
    ~MotorGrader_Form();

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

    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_editingFinished();

    void on_lineEdit_4_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_4_editingFinished();

    void on_comboBox_highlighted(int index);

    void on_comboBox_activated(int index);

    void on_comboBox_2_highlighted(int index);

    void on_comboBox_2_activated(int index);

private:
    Ui::MotorGrader_Form *ui;
    MotorGrader *object_motorgrader;
    User object_user;
    QString name;
    unsigned int count1, count2;

    /* Filling а structure from form`s items
     * Input: structure
     * Output: - */
    void FillingFormMotorGrader(form_motorgrader &object_form);

    /* Cheking logical structure
     * Input: structure
     * Output: - */
    bool CheckAnswer(form_answer_motorgrader form);

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
    void stretch_marks_cursor(QPen);
    void bar_cursor(QPen);
    void lining_blade_cursor(QPen);
    void lining_grubber_cursor(QPen);
};

#endif // MOTORGRADER_FORM_H
