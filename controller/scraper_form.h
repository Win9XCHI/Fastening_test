#ifndef SCRAPER_FORM_H
#define SCRAPER_FORM_H

#include <QWidget>
#include "base/base_technics.h"
#include "../classes/scraper.h"
#include "../classes/test.h"
#include "../functions/validation.h"

namespace Ui {
class Scraper_Form;
}

class Scraper_Form : public QWidget, base_technics
{
    Q_OBJECT

public:
    explicit Scraper_Form(ScraperDB db, User u, QWidget *parent = nullptr);
    ~Scraper_Form();

signals:
    void firstWindow();

private slots:
    /* Pressing "To main window" button
     * Input: -
     * Output: - */
    void on_pushButton_clicked();

    /* Pressing "Done" button
     * Input: -
     * Output: - */
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
    Scraper *object_scraper;
    User object_user;
    QString name;
    unsigned int count;

    /* Filling а structure from form`s items
     * Input: structure
     * Output: - */
    void FillingFormMotorScraper(form_scraper &object_form);

    /* Cheking logical structure
     * Input: structure
     * Output: - */
    bool CheckAnswer(form_answer_scraper form);

    /* Doing items` color are black
     * Input: -
     * Output: - */
    void Default();

    /* Set up image in the form
     * Input: -
     * Output: - */
    void set_image() override;

    /* Showing graphics
     * Input: -
     * Output: - */
    void show_graphics();

    /* Functions with graphics
     * Input: pen
     * Output: - */
    void stretch_marks_cursor(QPen);
    void bar_thrust_cursor(QPen);
    void bar_side_cursor(QPen);
    void lining_cursor(QPen);
};

#endif // SCRAPER_FORM_H
