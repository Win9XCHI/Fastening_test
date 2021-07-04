#ifndef ADMIN_FORM_H
#define ADMIN_FORM_H

#include <QWidget>
#include "../model/admin_db.h"

namespace Ui {
class Admin_Form;
}

class Admin_Form : public QWidget
{
    Q_OBJECT

public:
    explicit Admin_Form(AdminDB db, QWidget *parent = nullptr);
    ~Admin_Form();

signals:
    void firstWindow();

private slots:
    void on_comboBox_activated(int index);

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Admin_Form *ui;
    AdminDB DB;
    QString equipment;

    QString SetWhere(QString name, QString platoon, QString equipment);
};

#endif // ADMIN_FORM_H
