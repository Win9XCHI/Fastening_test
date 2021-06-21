#ifndef MOTORGRADER_FORM_H
#define MOTORGRADER_FORM_H

#include <QWidget>
#include "base_technics.h"

namespace Ui {
class MotorGrader_Form;
}

class MotorGrader_Form : public QWidget, base_technics
{
    Q_OBJECT

public:
    explicit MotorGrader_Form(QWidget *parent = nullptr);
    ~MotorGrader_Form();

private:
    Ui::MotorGrader_Form *ui;
    void show_graphics();
    void stretch_marks_cursor(QPen);
    void bar_side_cursor(QPen);
    void lining_blade_cursor(QPen);
    void lining_grubber_cursor(QPen);
};

#endif // MOTORGRADER_FORM_H
