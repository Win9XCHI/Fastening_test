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

private slots:
    void on_comboBox_activated(int index);

private:
    Ui::Admin_Form *ui;
};

#endif // ADMIN_FORM_H
