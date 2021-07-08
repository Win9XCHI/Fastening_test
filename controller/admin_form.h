#ifndef ADMIN_FORM_H
#define ADMIN_FORM_H

#include <QWidget>
#include "../model/admin_db.h"
#include "../functions/validation.h"
#include "../constants.h"

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

    void on_comboBox_2_activated(const QString &arg1);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::Admin_Form *ui;
    AdminDB DB;
    QString equipment;

    QString SetWhere(QString name, QString platoon, QString equipment);
    void FillingCont(QString equipment, std::multimap<QString, QString> &cont, std::multimap<QString, QString> &contYN, std::multimap<QString, Dimensions> &contD, std::multimap<QString, FromTo> &contFT);
    void SetTableWidget_2(std::multimap<QString, QString> cont);
    void SetTableWidget_4(std::multimap<QString, QString> cont);
    void SetTableWidget_3(std::multimap<QString, Dimensions> contD);
    void SetTableWidget_5(std::multimap<QString, FromTo> contFT);

    void TableDefault();
};

#endif // ADMIN_FORM_H
