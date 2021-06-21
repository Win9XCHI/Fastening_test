#ifndef EXCAVATOR_FORM_H
#define EXCAVATOR_FORM_H

#include <QWidget>
#include "base_technics.h"

namespace Ui {
class Excavator_Form;
}

class Excavator_Form : public QWidget, base_technics
{
    Q_OBJECT

public:
    explicit Excavator_Form(QWidget *parent = nullptr);
    ~Excavator_Form();

private:
    Ui::Excavator_Form *ui;
    void show_graphics();
    void SM_swilev_cursor(QPen);
    void SM_undercarriage_cursor(QPen);
    void SM_root_cursor(QPen);
    void SM_handle_cursor(QPen);
    void SM_trolley_cursor(QPen);
    void lining_cursor(QPen);
    void arrow_cursor(QPen);
    void axisT_cursor(QPen);
    void axisL_cursor(QPen);
};

#endif // EXCAVATOR_FORM_H
