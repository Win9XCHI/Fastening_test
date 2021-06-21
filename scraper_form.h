#ifndef SCRAPER_FORM_H
#define SCRAPER_FORM_H

#include <QWidget>
#include "base_technics.h"

namespace Ui {
class Scraper_Form;
}

class Scraper_Form : public QWidget, base_technics
{
    Q_OBJECT

public:
    explicit Scraper_Form(QWidget *parent = nullptr);
    ~Scraper_Form();

private:
    Ui::Scraper_Form *ui;
    void show_graphics();
    void stretch_marks_cursor(QPen);
    //Thrust Bars
    void bar_cursor(QPen);
    //Lining (blade)
    void lining_blade_cursor(QPen);
    //Lining (grubber)
    void Lining_grubber_cursor(QPen);
};

#endif // SCRAPER_FORM_H
