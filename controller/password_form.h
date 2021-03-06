#ifndef PASSWORD_FORM_H
#define PASSWORD_FORM_H

#include <QWidget>
#include "admin_form.h"

namespace Ui {
class Password_Form;
}

class Password_Form : public QWidget
{
    Q_OBJECT

public:
    explicit Password_Form(AdminDB db, QWidget *parent = nullptr);
    ~Password_Form();

signals:
    void succes();
    void return_main();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Password_Form *ui;
    AdminDB DB;
};

#endif // PASSWORD_FORM_H
