#ifndef BULLDOZER_FORM_H
#define BULLDOZER_FORM_H

#include <QWidget>
#include "base_technics.h"

namespace Ui {
class Bulldozer_Form;
}

class Bulldozer_Form : public QWidget, base_technics
{
    Q_OBJECT

public:
    explicit Bulldozer_Form(QWidget *parent = nullptr);
    ~Bulldozer_Form();

private:
    Ui::Bulldozer_Form *ui;
    void show_graphics();
    void StretchMarks_cursor(QPen);
    void BarT_cursor(QPen);
    void BarS_cursor(QPen);
};

#endif // BULLDOZER_FORM_H
