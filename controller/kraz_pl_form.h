#ifndef KRAZ_PL_FORM_H
#define KRAZ_PL_FORM_H

#include <QWidget>
#include "base/base_technics.h"
#include "../classes/kraz_pl.h"

namespace Ui {
class KRAZ_pl_form;
}

class KRAZ_pl_form : public QWidget, base_technics
{
    Q_OBJECT

public:
    explicit KRAZ_pl_form(QWidget *parent = nullptr);
    ~KRAZ_pl_form();

signals:
    void firstWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::KRAZ_pl_form *ui;

    void set_image() override;

    void show_graphics();
    void bar_cursor(QPen);
    void bars(QPen);
    void stretch_marks_cursor(QPen);
};

#endif // KRAZ_PL_FORM_H
