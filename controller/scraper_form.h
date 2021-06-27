#ifndef SCRAPER_FORM_H
#define SCRAPER_FORM_H

#include <QWidget>
#include "base/base_technics.h"
#include "../classes/scraper.h"

namespace Ui {
class Scraper_Form;
}

class Scraper_Form : public QWidget, base_technics
{
    Q_OBJECT

public:
    explicit Scraper_Form(ScraperDB db, QWidget *parent = nullptr);
    ~Scraper_Form();

signals:
    void firstWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_editingFinished();

    void on_lineEdit_4_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_4_editingFinished();

    void on_comboBox_highlighted(int index);

    void on_comboBox_activated(int index);

    void on_lineEdit_10_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_10_editingFinished();

private:
    Ui::Scraper_Form *ui;
    ScraperDB DB;
    Scraper *object_scraper;
    unsigned int count;

    void FillingFormMotorScraper(form_scraper &object_form);
    bool CheckAnswer(form_answer_scraper form);
    void Default();
    void set_image() override;

    void show_graphics();
    void stretch_marks_cursor(QPen);
    void bar_thrust_cursor(QPen);
    void bar_side_cursor(QPen);
    void lining_cursor(QPen);
};

#endif // SCRAPER_FORM_H
