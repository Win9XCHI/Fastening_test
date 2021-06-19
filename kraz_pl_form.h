#ifndef KRAZ_PL_FORM_H
#define KRAZ_PL_FORM_H

#include <QWidget>
#include "base_technics.h"

namespace Ui {
class KRAZ_pl_form;
}

class KRAZ_pl_form : public QWidget, base_technics
{
    Q_OBJECT

public:
    explicit KRAZ_pl_form(QWidget *parent = nullptr);
    ~KRAZ_pl_form();

private:
    Ui::KRAZ_pl_form *ui;
    void show_graphics();
};

#endif // KRAZ_PL_FORM_H
