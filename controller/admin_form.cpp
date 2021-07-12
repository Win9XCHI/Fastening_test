#include "admin_form.h"
#include "ui_admin_form.h"

Admin_Form::Admin_Form(AdminDB db, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Admin_Form)
{
    ui->setupUi(this);
    ui->comboBox->addItem(YES_NO::EMPTY);
    ui->comboBox->addItem("Студенти/курсанти");
    ui->comboBox->addItem("Техніка");
    ui->groupBox_5->hide();
    ui->groupBox_3->hide();
    ui->groupBox_6->hide();
    ui->groupBox_2->hide();
    DB = db;

    QList<QLineEdit *> allEdits;
    allEdits.push_back(ui->lineEdit_9);
    allEdits.push_back(ui->lineEdit_8);
    Validation::LineEdit::SetDoubleValidator(allEdits);
    allEdits.clear();
    allEdits.push_back(ui->lineEdit_10);
    allEdits.push_back(ui->lineEdit_11);
    allEdits.push_back(ui->lineEdit_12);
    Validation::LineEdit::SetIntValidator(allEdits);
}

Admin_Form::~Admin_Form()
{
    delete ui;
}

/* Selecting option in comboBox
 * Input: option`s index
 * Output: - */
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

        ui->comboBox_2->clear();
        ui->comboBox_2->addItem(YES_NO::EMPTY);

        DB.SELECT("Name", "Equipment AS E");
        std::list<QString> cont;
        DB.GetEquipments(cont);

        ui->tableWidget_2->setRowCount(cont.size());
        ui->tableWidget_2->setColumnCount(1);
        QStringList name_table;
        name_table << "Назва техніки";
        ui->tableWidget_2->setHorizontalHeaderLabels(name_table);

        for (int i = 0; i < ui->tableWidget_2->rowCount(); i++) {
             QTableWidgetItem *item = new QTableWidgetItem();
             item->setText(cont.front());
             ui->comboBox_2->addItem(cont.front());
             ui->tableWidget_2->setItem(i,0,item);
             cont.pop_front();
         }
    }
}

/* Pressing "To main window" button
 * Input: -
 * Output: - */
void Admin_Form::on_pushButton_5_clicked()
{
    emit firstWindow();
    this->~Admin_Form();
}

/* Construct where statement for select query to database
 * Input: user`s name and platoon, equipment`s name
 * Output: 'where' string for quiry */
QString Admin_Form::SetWhere(QString name, QString platoon, QString equipment) {
    QString where = YES_NO::EMPTY;

    if (name != YES_NO::EMPTY) {
        where = "S.Name LIKE '" + name + " %'";
    }

    if (name != YES_NO::EMPTY && platoon != YES_NO::EMPTY) {
        where += " AND ";
    }

    if (platoon != YES_NO::EMPTY) {
        where += "S.Platoon = '" + platoon + "'";
    }

    if (where != YES_NO::EMPTY && equipment != YES_NO::EMPTY) {
        where += " AND ";
    }

    if (equipment != YES_NO::EMPTY) {
        where += "E.Name = '" + equipment + "'";
    }

    return where;
}

/* Pressing "Output students" button
 * Input: -
 * Output: - */
void Admin_Form::on_pushButton_2_clicked() {
    DB.SELECT("*", "Student AS S", SetWhere(ui->lineEdit_6->text(), ui->lineEdit_7->text(), YES_NO::EMPTY), YES_NO::EMPTY, "Name ASC");
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

/* Pressing "Output grades" button
 * Input: -
 * Output: - */
void Admin_Form::on_pushButton_clicked() {
    DB.SELECT("S.Name AS st_name, S.Platoon, T.Date, T.Grade, E.Name AS eq_name",
              "Student AS S JOIN Test AS T ON T.Student_id = S.id JOIN Equipment AS E ON E.id = T.Equipment_id",
              SetWhere(ui->lineEdit_6->text(), ui->lineEdit_7->text(), ui->lineEdit_13->text()), YES_NO::EMPTY,
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

/* Filling class`s variables
 * Input: containers with data from database
 * Output: - */
void Admin_Form::FillingCont(QString equipment, std::multimap<QString, QString> &cont, std::multimap<QString, QString> &contYN, std::multimap<QString, Dimensions> &contD, std::multimap<QString, FromTo> &contFT) {
    DB.SELECT("Con.Value, Cha.Name",
              "Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id",
              "Equ.Name = '" + equipment + "' AND Con.Value NOT NULL",
              YES_NO::EMPTY, "Cha.Name ASC");
    DB.GetValue(cont);

    DB.SELECT("Yn.Answer, Cha.Name",
              "YesNo AS Yn JOIN Conditions AS Con ON Con.id = Yn.Conditions_id JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id",
              "Equ.Name = '" + equipment + "'",
              YES_NO::EMPTY, "Cha.Name ASC");
    DB.GetYesNoValue(contYN);

    DB.SELECT("D.Thickness, D.Width, D.Length, Cha.Name",
              "Dimensions AS D JOIN Conditions AS Con ON Con.id = D.Conditions_id JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id",
              "Equ.Name = '" + equipment + "'",
              YES_NO::EMPTY, "Cha.Name ASC");
    DB.GetDimensionsValue(contD);

    DB.SELECT("Ft.\"From\", Ft.\"To\", Cha.Name",
              "FromTo AS Ft JOIN Conditions AS Con ON Con.id = Ft.Conditions_id JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id",
              "Equ.Name = '" + equipment + "'",
              YES_NO::EMPTY, "Cha.Name ASC");
    DB.GetFromToValue(contFT);
}

/* Selecting option in comboBox_2
 * Input: option`s string
 * Output: - */
void Admin_Form::on_comboBox_2_activated(const QString &arg1) {
    std::multimap<QString, QString> cont;
    std::multimap<QString, QString> contYN;
    std::multimap<QString, Dimensions> contD;
    std::multimap<QString, FromTo> contFT;
    equipment = arg1;

    FillingCont(arg1, cont, contYN, contD, contFT);

    SetTableWidget_2(cont);
    SetTableWidget_4(contYN);
    SetTableWidget_3(contD);
    SetTableWidget_5(contFT);
}

/* Output simple characteristics
 * Input: characteristic`s data
 * Output: - */
void Admin_Form::SetTableWidget_2(std::multimap<QString, QString> cont) {
    unsigned int column_count = 2;
    ui->tableWidget_2->setRowCount(cont.size());
    ui->tableWidget_2->setColumnCount(column_count);
    QStringList name_table;
    name_table << "Назва" << "Значення";
    ui->tableWidget_2->setHorizontalHeaderLabels(name_table);
    unsigned int i = 0;

    for(auto& item : cont) {
        QTableWidgetItem *itemWI[column_count];
        for (unsigned int n = 0; n < column_count; n++) {
            itemWI[n] = new QTableWidgetItem();
        }
        itemWI[0]->setText(item.first);
        itemWI[1]->setText(item.second);
        for (unsigned int n = 0; n < column_count; n++) {
            ui->tableWidget_2->setItem(i,n,itemWI[n]);
        }
        i++;
    }
}

/* Output "Yes or no" characteristics
 * Input: characteristic`s data
 * Output: - */
void Admin_Form::SetTableWidget_4(std::multimap<QString, QString> contYN) {
    unsigned int column_count = 2;
    ui->tableWidget_4->setRowCount(contYN.size());
    ui->tableWidget_4->setColumnCount(column_count);
    QStringList name_table;
    ui->tableWidget_4->setHorizontalHeaderLabels(name_table);
    unsigned int i = 0;

    for(auto& item : contYN) {
        QTableWidgetItem *itemWI[column_count];
        for (unsigned int n = 0; n < column_count; n++) {
            itemWI[n] = new QTableWidgetItem();
        }
        itemWI[0]->setText(item.first);
        itemWI[1]->setText(item.second);
        for (unsigned int n = 0; n < column_count; n++) {
            ui->tableWidget_4->setItem(i,n,itemWI[n]);
        }
        i++;
    }
}

/* Output dimensions characteristics
 * Input: characteristic`s data
 * Output: - */
void Admin_Form::SetTableWidget_3(std::multimap<QString, Dimensions> contD) {
    unsigned int column_count = 4;
    ui->tableWidget_3->setRowCount(contD.size());
    ui->tableWidget_3->setColumnCount(column_count);
    QStringList name_table;
    name_table << "Назва" << "Товщина" << "Ширина" << "Довжина";
    ui->tableWidget_3->setHorizontalHeaderLabels(name_table);
    unsigned int i = 0;

    for(auto& item : contD) {
        QTableWidgetItem *itemWI[column_count];
        for (unsigned int n = 0; n < column_count; n++) {
            itemWI[n] = new QTableWidgetItem();
        }

        itemWI[0]->setText(item.first);
        itemWI[1]->setText(QString::number(item.second.GetThickness()));
        itemWI[2]->setText(QString::number(item.second.GetWidth()));
        itemWI[3]->setText(QString::number(item.second.GetLength()));

        for (unsigned int n = 0; n < column_count; n++) {
            ui->tableWidget_3->setItem(i,n,itemWI[n]);
        }
        i++;
    }
}

/* Output "From and to" characteristics
 * Input: characteristic`s data
 * Output: - */
void Admin_Form::SetTableWidget_5(std::multimap<QString, FromTo> contFT) {
    unsigned int column_count = 3;
    ui->tableWidget_5->setRowCount(contFT.size());
    ui->tableWidget_5->setColumnCount(column_count);
    QStringList name_table;
    name_table << "Назва" << "Від" << "До";
    ui->tableWidget_5->setHorizontalHeaderLabels(name_table);
    unsigned int i = 0;

    for(auto& item : contFT) {
        QTableWidgetItem *itemWI[column_count];
        for (unsigned int n = 0; n < column_count; n++) {
            itemWI[n] = new QTableWidgetItem();
        }

        itemWI[0]->setText(item.first);
        itemWI[1]->setText(QString::number(item.second.GetFrom()));
        itemWI[2]->setText(QString::number(item.second.GetTo()));

        for (unsigned int n = 0; n < column_count; n++) {
            ui->tableWidget_5->setItem(i,n,itemWI[n]);
        }
        i++;
    }
}

/* Clear TableWidgets
 * Input: -
 * Output: - */
void Admin_Form::TableDefault() {
    QList<QTableWidget *> allEdits = this->findChildren<QTableWidget *>();
    for (auto &element : allEdits) {

        for (int i = 0; i < element->rowCount(); i++) {
            element->removeRow(i);
        }

        for (int i = 0; i < element->columnCount(); i++) {
            element->removeColumn(i);
        }
        element->clear();
    }
}

/* Pressing "Check characteristic" button
 * Input: -
 * Output: - */
void Admin_Form::on_pushButton_3_clicked() {
    TableDefault();
    QString where;

    if (ui->lineEdit_5->text() == YES_NO::EMPTY) {
        where = "Equ.Name = '" + equipment + "' AND Cha.Name = '" + ui->lineEdit->text() + "'";

    } else {

        if (ui->lineEdit_14->text() == YES_NO::EMPTY) {
            where = "Con.Conditions_id = (SELECT Con.id FROM Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Equ.Name = '" + equipment + "' AND Con.Value = '" + ui->lineEdit_5->text() + "' AND Cha.Name = '" + ui->lineEdit->text() + "')";
        } else {
            if (ui->lineEdit_15->text() == YES_NO::EMPTY) {
                where = "Con.Conditions_id = (SELECT Con.id FROM Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Con.Value = '" + ui->lineEdit_14->text() + "' AND Cha.Name = '" + ui->lineEdit_3->text() + "' AND Con.Conditions_id = (SELECT Con.id FROM Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Equ.Name = '" + equipment + "' AND Con.Value = '" + ui->lineEdit_5->text() + "'))";
            } else {
                where = "Con.Conditions_id = (SELECT Con.id FROM Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Con.Value = '" + ui->lineEdit_15->text() + "' AND Cha.Name = '" + ui->lineEdit_4->text() + "' AND Con.Conditions_id = (SELECT Con.id FROM Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Con.Value = '" + ui->lineEdit_14->text() + "' AND Cha.Name = '" + ui->lineEdit_3->text() + "' AND Con.Conditions_id = (SELECT Con.id FROM Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Equ.Name = '" + equipment + "' AND Con.Value = '" + ui->lineEdit_5->text() + "')))";
            }
        }
    }

    std::multimap<QString, QString> cont;
    std::multimap<QString, QString> contYN;
    std::multimap<QString, Dimensions> contD;
    std::multimap<QString, FromTo> contFT;
    DB.SELECT("Con.Value, Cha.Name",
              "Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id",
              where,
              YES_NO::EMPTY, "Cha.Name ASC");
    DB.GetValue(cont);

    DB.SELECT("Yn.Answer, Cha.Name",
              "YesNo AS Yn JOIN Conditions AS Con ON Con.id = Yn.Conditions_id JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id",
              where,
              YES_NO::EMPTY, "Cha.Name ASC");
    DB.GetYesNoValue(contYN);

    DB.SELECT("D.Thickness, D.Width, D.Length, Cha.Name",
              "Dimensions AS D JOIN Conditions AS Con ON Con.id = D.Conditions_id JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id",
              where,
              YES_NO::EMPTY, "Cha.Name ASC");
    DB.GetDimensionsValue(contD);

    DB.SELECT("Ft.\"From\", Ft.\"To\", Cha.Name",
              "FromTo AS Ft JOIN Conditions AS Con ON Con.id = Ft.Conditions_id JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id",
              where,
              YES_NO::EMPTY, "Cha.Name ASC");
    DB.GetFromToValue(contFT);

    if (cont.size() != 0) {
        SetTableWidget_2(cont);
    }
    if (contYN.size() != 0) {
        SetTableWidget_4(contYN);
    }
    if (contD.size() != 0) {
        SetTableWidget_3(contD);
    }
    if (contFT.size() != 0) {
        SetTableWidget_5(contFT);
    }
}

/* Pressing "New characteristic`s value" button
 * Input: -
 * Output: - */
void Admin_Form::on_pushButton_4_clicked() {
    QString where;
    DB.SELECT("Cha.Type", "Characteristic AS Cha JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id", "Equ.Name = '" + equipment + "' AND Cha.Name = '" + ui->lineEdit->text() + "'");
    QString type = DB.GetTypeValue();

    if (ui->lineEdit_5->text() == YES_NO::EMPTY) {
        where = "Equ.Name = '" + equipment + "' AND Cha.Name = '" + ui->lineEdit->text() + "'";
    } else {
        if (ui->lineEdit_14->text() == YES_NO::EMPTY) {
            where = "Cha.Name = '" + ui->lineEdit_16->text() + "' AND Con.Conditions_id = (SELECT Con.id FROM Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Equ.Name = '" + equipment + "' AND Con.Value = '" + ui->lineEdit_5->text() + "' AND Cha.Name = '" + ui->lineEdit->text() + "')";
        } else {
            if (ui->lineEdit_15->text() == YES_NO::EMPTY) {
                where = "Cha.Name = '" + ui->lineEdit_16->text() + "' AND Con.Conditions_id = (SELECT Con.id FROM Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Con.Value = '" + ui->lineEdit_14->text() + "' AND Cha.Name = '" + ui->lineEdit_3->text() + "' AND Con.Conditions_id = (SELECT Con.id FROM Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Equ.Name = '" + equipment + "' AND Con.Value = '" + ui->lineEdit_5->text() + "'))";
            } else {
                where = "Cha.Name = '" + ui->lineEdit_16->text() + "' AND Con.Conditions_id = (SELECT Con.id FROM Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Con.Value = '" + ui->lineEdit_15->text() + "' AND Cha.Name = '" + ui->lineEdit_4->text() + "' AND Con.Conditions_id = (SELECT Con.id FROM Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Con.Value = '" + ui->lineEdit_14->text() + "' AND Cha.Name = '" + ui->lineEdit_3->text() + "' AND Con.Conditions_id = (SELECT Con.id FROM Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id WHERE Equ.Name = '" + equipment + "' AND Con.Value = '" + ui->lineEdit_5->text() + "')))";
            }
            DB.SELECT("Cha.Type", "Characteristic AS Cha JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id", "Equ.Name = '" + equipment + "' AND Cha.Name = '" + ui->lineEdit_16->text() + "'");
            type = DB.GetTypeValue();
        }
    }

    std::vector<unsigned int> cont;

    if (type == YES_NO::EMPTY || type == "Conditions") {
        DB.SELECT("Con.id",
                  "Conditions AS Con JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id",
                  where,
                  YES_NO::EMPTY, "Cha.Name ASC");
        DB.GetId(cont);

        if (cont.size() == 1) {
            DB.UPDATE("Conditions", "Value = '" + ui->lineEdit_2->text() + "'", "id = " + QString::number(cont[0]));
        }
    }

    if (type == "YesNo") {
        DB.SELECT("Yn.id",
                  "YesNo AS Yn JOIN Conditions AS Con ON Con.id = Yn.Conditions_id JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id",
                  where,
                  YES_NO::EMPTY, "Cha.Name ASC");
        DB.GetId(cont);

        if (cont.size() == 1) {
            DB.UPDATE("YesNo", "Answer = '" + ui->lineEdit_2->text() + "'", "id = " + QString::number(cont[0]));
        }
    }

    if (type == "Dimensions") {
        DB.SELECT("D.id",
                  "Dimensions AS D JOIN Conditions AS Con ON Con.id = D.Conditions_id JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id",
                  where,
                  YES_NO::EMPTY, "Cha.Name ASC");
        DB.GetId(cont);

        if (cont.size() == 1) {
            DB.UPDATE("Dimensions", "Thickness = " + ui->lineEdit_12->text() + ", Width = " + ui->lineEdit_11->text() + ", Length = " + ui->lineEdit_10->text(), "id = " + QString::number(cont[0]));
        }
    }

    if (type == "FromTo") {
        DB.SELECT("Ft.id",
                  "FromTo AS Ft JOIN Conditions AS Con ON Con.id = Ft.Conditions_id JOIN Characteristic AS Cha ON Cha.id = Con.Characteristic_id JOIN Equipment AS Equ ON Equ.id = Cha.Equipment_id",
                  where,
                  YES_NO::EMPTY, "Cha.Name ASC");
        DB.GetId(cont);

        if (cont.size() == 1) {
            DB.UPDATE("FromTo", "\"From\" = " + ui->lineEdit_9->text() + ", \"To\" = " + ui->lineEdit_8->text(), "id = " + QString::number(cont[0]));
        }
    }

    on_pushButton_3_clicked();
}

/* Pressing "Clear form" button
 * Input: -
 * Output: - */
void Admin_Form::on_pushButton_6_clicked()
{
    TableDefault();
    QList<QLineEdit *> allEdits = this->findChildren<QLineEdit *>();
    for (auto &element : allEdits) {
        element->setText(YES_NO::EMPTY);
    }
}
