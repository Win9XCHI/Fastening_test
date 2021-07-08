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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_5_editingFinished();

    void on_listWidget_currentTextChanged(const QString &currentText);

    void on_listWidget_2_currentTextChanged(const QString &currentText);

    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_editingFinished();

    void on_lineEdit_4_cursorPositionChanged(int arg1, int arg2);

    void on_lineEdit_4_editingFinished();

private:
    Ui::VGM_Form *ui;
    VGM_DB DB;
    VGM *object_VGM;
    User object_user;
    QString name;
    unsigned int count1, count2;

    void FillingFormVGM(form_VGM &object_form);
    bool CheckAnswer(form_answer_VGM form);
    void Default();
    void set_image() override;

    void show_graphics();
    void bar_cursor(QPen);
    void stretch_marks_cursor(QPen);
};

#endif // VGM_FORM_H
