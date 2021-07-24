#ifndef VGM_FORM_H
#define VGM_FORM_H

#include <QWidget>
#include "base/base_technics.h"
#include "../classes/vgm.h"
#include "../classes/test.h"
#include "../functions/validation.h"

namespace Ui {
class VGM_Form;
}

class VGM_Form : public QWidget, base_technics
{
    Q_OBJECT

public:
    explicit VGM_Form(VGM_DB db, User u, QWidget *parent = nullptr);
    ~VGM_Form();

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

    void on_lineEdit_5_editingFinished();

    void on_listWidget_currentTextChanged(const QString &currentText);

    void on_listWidget_2_currentTextChanged(const QString &currentText);

    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_editingFinished();

    void on_lineEdit_4_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_4_editingFinished();

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::VGM_Form *ui;
    VGM *object_VGM;
    User object_user;
    QString name;
    unsigned int count1, count2;

    /* Filling а structure from form`s items
     * Input: structure
     * Output: - */
    void FillingFormVGM(form_VGM &object_form);

    /* Cheking logical structure
     * Input: structure
     * Output: - */
    bool CheckAnswer(form_answer_VGM form);

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
    void bar_cursor(QPen);
    void stretch_marks_cursor(QPen);

    /* Clear lineEdits
     * Input: -
     * Output: - */
    void clear_staples_nails();
    void clear_staples_sideBars();
};

#endif // VGM_FORM_H
