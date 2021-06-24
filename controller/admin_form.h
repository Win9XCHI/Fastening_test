#ifndef ADMIN_FORM_H
#define ADMIN_FORM_H

#include <QWidget>

namespace Ui {
class Admin_Form;
}

class Admin_Form : public QWidget
{
    Q_OBJECT

public:
    explicit Admin_Form(QWidget *parent = nullptr);
    ~Admin_Form();

signals:
    void firstWindow();

private:
    Ui::Admin_Form *ui;
};

#endif // ADMIN_FORM_H
