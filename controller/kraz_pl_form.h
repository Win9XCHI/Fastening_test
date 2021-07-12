#ifndef KRAZ_PL_FORM_H
#define KRAZ_PL_FORM_H

#include <QWidget>
#include "base/base_technics.h"
#include "../classes/kraz_pl.h"
#include "../classes/test.h"
#include "../functions/validation.h"

namespace Ui {
class KRAZ_pl_form;
}

class KRAZ_pl_form : public QWidget, base_technics
{
    Q_OBJECT

public:
    explicit KRAZ_pl_form(KRAZ_pl_DB db, User u, QWidget *parent = nullptr);
    ~KRAZ_pl_form();

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

    void on_lineEdit_7_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_7_editingFinished();

private:
    Ui::KRAZ_pl_form *ui;
    KRAZ_pl *object_KRAZ_pl;
    User object_user;
    QString name;

    /* Filling а structure from form`s items
     * Input: structure
     * Output: - */
    void FillingFormKRAZ_pl(form_KRAZ_pl &object_form);

    /* Cheking logical structure
     * Input: structure
     * Output: - */
    bool CheckAnswer(form_answer_KRAZ_pl form);

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
    void bar_cursor(QPen);
    void bars(QPen);
    void stretch_marks_cursor(QPen);
};

#endif // KRAZ_PL_FORM_H
