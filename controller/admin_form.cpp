#include "admin_form.h"
#include "ui_admin_form.h"

Admin_Form::Admin_Form(AdminDB db, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Admin_Form)
{
    ui->setupUi(this);
    ui->comboBox->addItem("");
    ui->comboBox->addItem("Студенти/курсанти");
    ui->comboBox->addItem("Техніка");
    ui->groupBox_5->hide();
    ui->groupBox_3->hide();
    ui->groupBox_6->hide();
    ui->groupBox_2->hide();
    DB = db;
}

Admin_Form::~Admin_Form()
{
    delete ui;
}

void Admin_Form::on_comboBox_activated(int index)
{
    if (index == 1) {
        ui->groupBox_5->show();
        ui->groupBox_2->show();
        ui->groupBox_3->hide();
        ui->groupBox_6->hide();
    }
    if (index == 2) {
        ui->groupBox_3->show();
        ui->groupBox_6->show();
        ui->groupBox_5->hide();
        ui->groupBox_2->hide();
    }
}

void Admin_Form::on_pushButton_5_clicked()
{
    emit firstWindow();
    this->close();
}

QString Admin_Form::SetWhere(QString name, QString platoon, QString equipment) {
    QString where = "";

    if (name != "") {
        where = "S.Name = '" + name + "'";
    }

    if (name != "" && platoon != "") {
        where += " AND ";
    }

    if (platoon != "") {
        where += "S.Platoon = '" + platoon + "'";
    }

    if (where != "" && equipment != "") {
        where += " AND ";
    }

    if (equipment != "") {
        where += "E.Name = '" + equipment + "'";
    }

    return where;
}

void Admin_Form::on_pushButton_2_clicked() {
    DB.SELECT("*", "Student AS S", SetWhere(ui->lineEdit_6->text(), ui->lineEdit_7->text(), ""), "", "Name ASC");
    std::list<User> cont;
    DB.GetUsers(cont);

    ui->tableWidget->setRowCount(cont.size());
    ui->tableWidget->setColumnCount(2);
    QStringList name_table;
    name_table << "ПІБ" << "Взвод";
    ui->tableWidget->setHorizontalHeaderLabels(name_table);

    for (int i = 0; i < ui->tableWidget->rowCount(); i++) {
        for (int n = 0; n < ui->tableWidget->columnCount(); n++) {
           QTableWidgetItem *item = new QTableWidgetItem(); //single for one cell tables
           item->setText(cont.front()[n]); //User has overload operator [] for 0 - Name, 1 - Platoon, 2 - id
           ui->tableWidget->setItem(i,n,item);
         }
         cont.pop_front();
     }
}

void Admin_Form::on_pushButton_clicked() {
    DB.SELECT("S.Name AS st_name, S.Platoon, T.Date, T.Grade, E.Name AS eq_name",
              "Student AS S JOIN Test AS T ON T.Student_id = S.id JOIN Equipment AS E ON E.id = T.Equipment_id",
              SetWhere(ui->lineEdit_6->text(), ui->lineEdit_7->text(), ui->lineEdit_7->text()), "",
              "E.Name ASC, T.Date ASC");
    std::list<Test> cont;
    DB.GetAttempts(cont);

    ui->tableWidget->setRowCount(cont.size());
    ui->tableWidget->setColumnCount(5);
    QStringList name_table;
    name_table << "ПІБ" << "Взвод" << "Оцінка" << "Час" << "Техніка";
    ui->tableWidget->setHorizontalHeaderLabels(name_table);

    for (int i = 0; i < ui->tableWidget->rowCount(); i++) {
        for (int n = 0; n < ui->tableWidget->columnCount(); n++) {
           QTableWidgetItem *item = new QTableWidgetItem(); //single for one cell tables
           item->setText(cont.front()[n]); //Test has overload operator []
           ui->tableWidget->setItem(i,n,item);
         }
         cont.pop_front();
     }
}
