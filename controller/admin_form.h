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
    /* Selecting option in comboBox
     * Input: option`s index
     * Output: - */
    void on_comboBox_activated(int index);

    /* Pressing "To main window" button
     * Input: -
     * Output: - */
    void on_pushButton_5_clicked();

    /* Pressing "Output students" button
     * Input: -
     * Output: - */
    void on_pushButton_2_clicked();

    /* Pressing "Output grades" button
     * Input: -
     * Output: - */
    void on_pushButton_clicked();

    /* Selecting option in comboBox_2
     * Input: option`s string
     * Output: - */
    void on_comboBox_2_activated(const QString &arg1);

    /* Pressing "Check characteristic" button
     * Input: -
     * Output: - */
    void on_pushButton_3_clicked();

    /* Pressing "New characteristic`s value" button
     * Input: -
     * Output: - */
    void on_pushButton_4_clicked();

    /* Pressing "Clear form" button
     * Input: -
     * Output: - */
    void on_pushButton_6_clicked();

private:
    Ui::Admin_Form *ui;
    AdminDB DB;
    QString equipment;

    /* Construct where statement for select query to database
     * Input: user`s name and platoon, equipment`s name
     * Output: 'where' string for quiry */
    QString SetWhere(QString name, QString platoon, QString equipment);

    /* Filling class`s variables
     * Input: containers with data from database
     * Output: - */
    void FillingCont(QString equipment, std::multimap<QString, QString> &cont, std::multimap<QString, QString> &contYN, std::multimap<QString, Dimensions> &contD, std::multimap<QString, FromTo> &contFT);

    /* Output simple characteristics
     * Input: characteristic`s data
     * Output: - */
    void SetTableWidget_2(std::multimap<QString, QString> cont);

    /* Output "Yes or no" characteristics
     * Input: characteristic`s data
     * Output: - */
    void SetTableWidget_4(std::multimap<QString, QString> cont);

    /* Output dimensions characteristics
     * Input: characteristic`s data
     * Output: - */
    void SetTableWidget_3(std::multimap<QString, Dimensions> contD);

    /* Output "From and to" characteristics
     * Input: characteristic`s data
     * Output: - */
    void SetTableWidget_5(std::multimap<QString, FromTo> contFT);

    /* Clear TableWidgets
     * Input: -
     * Output: - */
    void TableDefault();
};

#endif // ADMIN_FORM_H
