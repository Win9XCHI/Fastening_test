#ifndef BULLDOZER_FORM_H
#define BULLDOZER_FORM_H

#include <QWidget>
#include "base/base_technics.h"

namespace Ui {
class Bulldozer_Form;
}

class Bulldozer_Form : public QWidget, base_technics
{
    Q_OBJECT

public:
    explicit Bulldozer_Form(QWidget *parent = nullptr);
    ~Bulldozer_Form();

signals:
    void firstWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Bulldozer_Form *ui;
    void show_graphics();
    void stretch_marks_cursor(QPen);
    void bar_thrust_cursor(QPen);
    void bar_side_cursor(QPen);
    void lining_cursor(QPen);
};

#endif // BULLDOZER_FORM_H
