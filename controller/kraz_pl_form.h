#ifndef KRAZ_PL_FORM_H
#define KRAZ_PL_FORM_H

#include <QWidget>
#include "base/base_technics.h"
#include "../classes/kraz_pl.h"
#include "../classes/test.h"

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
    void win();
    void fail();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_editingFinished();

    void on_lineEdit_7_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_7_editingFinished();

private:
    Ui::KRAZ_pl_form *ui;
    KRAZ_pl_DB DB;
    KRAZ_pl *object_KRAZ_pl;
    User object_user;

    void FillingFormKRAZ_pl(form_KRAZ_pl &object_form);
    bool CheckAnswer(form_answer_KRAZ_pl form);
    void Default();
    void set_image() override;

    void show_graphics();
    void bar_cursor(QPen);
    void bars(QPen);
    void stretch_marks_cursor(QPen);
};

#endif // KRAZ_PL_FORM_H
