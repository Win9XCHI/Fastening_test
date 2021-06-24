#ifndef SCRAPER_FORM_H
#define SCRAPER_FORM_H

#include <QWidget>
#include "base/base_technics.h"

namespace Ui {
class Scraper_Form;
}

class Scraper_Form : public QWidget, base_technics
{
    Q_OBJECT

public:
    explicit Scraper_Form(QWidget *parent = nullptr);
    ~Scraper_Form();

signals:
    void firstWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Scraper_Form *ui;
    void show_graphics();
    void stretch_marks_cursor(QPen);
    void bar_thrust_cursor(QPen);
    void bar_side_cursor(QPen);
    void lining_cursor(QPen);
};

#endif // SCRAPER_FORM_H
