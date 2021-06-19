#ifndef KRAZ_FORM_H
#define KRAZ_FORM_H

#include <QWidget>
#include "base_technics.h"

namespace Ui {
class KRAZ_Form;
}

class KRAZ_Form : public QWidget, base_technics
{
    Q_OBJECT

public:
    explicit KRAZ_Form(QWidget *parent = nullptr);
    ~KRAZ_Form();

private:
    Ui::KRAZ_Form *ui;
    void show_graphics();
};

#endif // KRAZ_FORM_H
