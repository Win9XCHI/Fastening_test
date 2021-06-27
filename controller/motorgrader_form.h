#ifndef MOTORGRADER_FORM_H
#define MOTORGRADER_FORM_H

#include <QWidget>
#include "base/base_technics.h"
#include "../classes/motorgrader.h"

namespace Ui {
class MotorGrader_Form;
}

class MotorGrader_Form : public QWidget, base_technics
{
    Q_OBJECT

public:
    explicit MotorGrader_Form(MotorGraderDB db, QWidget *parent = nullptr);
    ~MotorGrader_Form();

signals:
    void firstWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MotorGrader_Form *ui;
    void show_graphics();
    void stretch_marks_cursor(QPen);
    void bar_cursor(QPen);
    void lining_blade_cursor(QPen);
    void lining_grubber_cursor(QPen);
};

#endif // MOTORGRADER_FORM_H
