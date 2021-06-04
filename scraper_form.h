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
};

#endif // SCRAPER_FORM_H
