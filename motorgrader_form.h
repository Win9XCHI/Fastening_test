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
    void stretchMarks_cursor(QPen);
    void bars_cursor(QPen);
    void lining_cursor(QPen);
};

#endif // MOTORGRADER_FORM_H
