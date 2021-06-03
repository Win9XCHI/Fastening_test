#ifndef MOTORGRADER_FORM_H
#define MOTORGRADER_FORM_H

#include <QWidget>
#include <QGraphicsScene>

namespace Ui {
class MotorGrader_Form;
}

class MotorGrader_Form : public QWidget
{
    Q_OBJECT

public:
    explicit MotorGrader_Form(QWidget *parent = nullptr);
    ~MotorGrader_Form();

private:
    Ui::MotorGrader_Form *ui;
    QGraphicsScene *scene;
    void image();
    void show_grapgic();
    void stretchMarks_cursor();
    void bars_cursor();
    void lining_cursor();
};

#endif // MOTORGRADER_FORM_H
