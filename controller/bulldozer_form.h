#ifndef BULLDOZER_FORM_H
#define BULLDOZER_FORM_H

#include <QWidget>
#include "base/base_technics.h"
#include "../classes/bulldozer.h"

namespace Ui {
class Bulldozer_Form;
}

class Bulldozer_Form : public QWidget, base_technics
{
    Q_OBJECT

public:
    explicit Bulldozer_Form(BulldozerDB db, QWidget *parent = nullptr);
    ~Bulldozer_Form();

signals:
    void firstWindow();
    void win();
    void fail();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_listWidget_currentTextChanged(const QString &currentText);

    void on_listWidget_2_currentTextChanged(const QString &currentText);

    void on_comboBox_2_activated(const QString &arg1);

    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_editingFinished();

    void on_lineEdit_4_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_4_editingFinished();

    void on_comboBox_3_activated(const QString &arg1);

    void on_comboBox_highlighted(int index);

    void on_comboBox_activated(int index);

private:
    Ui::Bulldozer_Form *ui;
    BulldozerDB DB;
    Bulldozer *object_bulldozer;
    unsigned int count;

    void FillingFormBulldozer(form_bulldozer &object_form);
    bool CheckAnswer(form_answer_bulldozer form);
    void Default();
    void set_image() override;

    void show_graphics();
    void stretch_marks_cursor(QPen);
    void bar_thrust_cursor(QPen);
    void bar_side_cursor(QPen);
    void lining_cursor(QPen);
};

#endif // BULLDOZER_FORM_H
