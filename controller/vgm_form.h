#ifndef VGM_FORM_H
#define VGM_FORM_H

#include <QWidget>
#include "base/base_technics.h"
#include "../classes/vgm.h"

namespace Ui {
class VGM_Form;
}

class VGM_Form : public QWidget, base_technics
{
    Q_OBJECT

public:
    explicit VGM_Form(VGM_DB db, QWidget *parent = nullptr);
    ~VGM_Form();

signals:
    void firstWindow();
    void win();
    void fail();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_editingFinished();

    void on_spinBox_valueChanged(int arg1);

    void on_spinBox_editingFinished();

    void on_spinBox_3_valueChanged(int arg1);

    void on_spinBox_3_editingFinished();

private:
    Ui::VGM_Form *ui;
    VGM_DB DB;
    VGM *object_VGM;
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
