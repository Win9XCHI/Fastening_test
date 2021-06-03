#ifndef ABOUT_FORM_H
#define ABOUT_FORM_H

#include <QWidget>

namespace Ui {
class About_Form;
}

class About_Form : public QWidget
{
    Q_OBJECT

public:
    explicit About_Form(QWidget *parent = nullptr);
    ~About_Form();

private:
    Ui::About_Form *ui;
};

#endif // ABOUT_FORM_H
