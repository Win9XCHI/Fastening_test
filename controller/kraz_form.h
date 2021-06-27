#ifndef KRAZ_FORM_H
#define KRAZ_FORM_H

#include <QWidget>
#include "base/base_technics.h"

namespace Ui {
class KRAZ_Form;
}

class KRAZ_Form : public QWidget, base_technics
{
    Q_OBJECT

public:
    explicit KRAZ_Form(QWidget *parent = nullptr);
    ~KRAZ_Form();

signals:
    void firstWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::KRAZ_Form *ui;

    void set_image() override;

    void show_graphics();
    void bar_cursor(QPen);
    void bars_thrust(QPen);
    void bars_side(QPen);
    void stretch_marks_cursor(QPen);
};

#endif // KRAZ_FORM_H
