#ifndef VGM_FORM_H
#define VGM_FORM_H

#include <QWidget>
#include "base/base_technics.h"

namespace Ui {
class VGM_Form;
}

class VGM_Form : public QWidget, base_technics
{
    Q_OBJECT

public:
    explicit VGM_Form(QWidget *parent = nullptr);
    ~VGM_Form();

signals:
    void firstWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::VGM_Form *ui;
    void show_graphics();
    void bar_cursor(QPen);
    void stretch_marks_cursor(QPen);
};

#endif // VGM_FORM_H
