#ifndef BULLDOZER_FORM_H
#define BULLDOZER_FORM_H

#include <QWidget>
#include "base/base_technics.h"
#include "../classes/bulldozer.h"
#include "../classes/test.h"
#include "../functions/validation.h"

namespace Ui {
class Bulldozer_Form;
}

class Bulldozer_Form : public QWidget, base_technics
{
    Q_OBJECT

public:
    explicit Bulldozer_Form(BulldozerDB db, User u, QWidget *parent = nullptr);
    ~Bulldozer_Form();

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

    void on_listWidget_currentTextChanged(const QString &currentText);

    void on_listWidget_2_currentTextChanged(const QString &currentText);

    void on_comboBox_2_activated(const QString &arg1);

    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_editingFinished();

    void on_lineEdit_4_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_4_editingFinished();

    void on_comboBox_3_activated(const QString &arg1);

    void on_comboBox_highlighted(int index);

    void on_comboBox_activated(int index);

private:
    Ui::Bulldozer_Form *ui;
    Bulldozer *object_bulldozer;
    User object_user;
    QString name;
    unsigned int count;

    /* Filling а structure from form`s items
     * Input: structure
     * Output: - */
    void FillingFormBulldozer(form_bulldozer &object_form);

    /* Cheking logical structure
     * Input: structure
     * Output: - */
    bool CheckAnswer(form_answer_bulldozer form);

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

    /* Clear lineEdits
     * Input: -
     * Output: - */
    void clear_staples_nails();
    void clear_staples_sideBars();
};

#endif // BULLDOZER_FORM_H
