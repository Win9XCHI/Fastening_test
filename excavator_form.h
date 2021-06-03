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
};

#endif // EXCAVATOR_FORM_H
