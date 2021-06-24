#ifndef EXCAVATOR_FORM_H
#define EXCAVATOR_FORM_H

#include <QWidget>
#include "base/base_technics.h"

namespace Ui {
class Excavator_Form;
}

class Excavator_Form : public QWidget, base_technics
{
    Q_OBJECT

public:
    explicit Excavator_Form(QWidget *parent = nullptr);
    ~Excavator_Form();

signals:
    void firstWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Excavator_Form *ui;
    void show_graphics();
    void SM_swilev_cursor(QPen);
    void SM_undercarriage_cursor(QPen);
    void SM_root_cursor(QPen);
    void SM_handle_cursor(QPen);
    void SM_trolley_cursor(QPen);
    void lining_cursor(QPen);
    void arrow_cursor(QPen);
    void axis_turnover_cursor(QPen);
    void axis_longitudinal_cursor(QPen);

    void SM_swilev(QPen);
    void SM_undercarriage(QPen);
    void SM_root(QPen);
    void SM_handle(QPen);
    void SM_trolley(QPen);
    void bar_thrust(QPen);
    void bar_side(QPen);
    void lining(QPen);
};

#endif // EXCAVATOR_FORM_H
