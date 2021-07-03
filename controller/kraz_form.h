#ifndef KRAZ_FORM_H
#define KRAZ_FORM_H

#include <QWidget>
#include "base/base_technics.h"
#include "../classes/kraz.h"
#include "../classes/test.h"

namespace Ui {
class KRAZ_Form;
}

class KRAZ_Form : public QWidget, base_technics
{
    Q_OBJECT

public:
    explicit KRAZ_Form(KRAZ_DB db, User u, QWidget *parent = nullptr);
    ~KRAZ_Form();

signals:
    void firstWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_editingFinished();

    void on_lineEdit_2_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_2_editingFinished();

    void on_lineEdit_9_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_9_editingFinished();

private:
    Ui::KRAZ_Form *ui;
    KRAZ_DB DB;
    KRAZ *object_KRAZ;
    User object_user;
    QString name;

    void FillingFormKRAZ(form_KRAZ &object_form);
    bool CheckAnswer(form_answer_KRAZ form);
    void Default();
    void set_image() override;

    void show_graphics();
    void bar_thrust_cursor(QPen);
    void bar_side_cursor(QPen);
    void bars_thrust(QPen);
    void bars_side(QPen);
    void stretch_marks_cursor(QPen);
};

#endif // KRAZ_FORM_H
