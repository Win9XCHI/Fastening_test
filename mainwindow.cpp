#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem("Екскаватор ЕО-4125 на платформі");
    ui->comboBox->addItem("Бульдозер на платформі");
    ui->comboBox->addItem("Автогрейдер ДЗ-98 на платформі");
    ui->comboBox->addItem("Скрепер Д-357П на платформі");
    ui->comboBox->addItem("КрАЗ-256 порожній на платформі");
    ui->comboBox->addItem("КрАЗ-256 порожній над зчепом");
    ui->comboBox->addItem("Танк");
    equipment = "";
    object_user = new UserDB("DB_for_test.db");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_3_clicked() {

    if (!object_user->CheckConnection()) {
        object_user->createConnection();
    }
    if (!object_user->CheckConnection()) {
        throw DatabaseException(object_user->LastError().toStdString());
    }

    QString name = ui->lineEdit->text();
    QString platoon = ui->lineEdit->text();
    object_user->SELECT("*", "Student", "Name = '" + name + "' AND Platoon = '" + platoon + "'");
    std::vector<User> cont;
    object_user->GetUsers(cont);

    if (cont.size() == 0) {
        std::vector<QString> listColumns, listValue;
        listColumns.push_back("Name");
        listColumns.push_back("Platoon");
        listValue.push_back(name);
        listValue.push_back(platoon);
        object_user->Insert("Student", listColumns, listValue);
    }

    try {
        switch(ui->comboBox->currentIndex()) {
            case EQUIPMENT::EXCAVATOR: {
                equipment = "Екскаватор ЕО-4125 на платформі";
                Excavator();
                break;
            }
            case EQUIPMENT::BULLDOZER: {
                equipment = "Бульдозер Д-686 на платформі";
                Bulldozer();
                break;
            }
            case EQUIPMENT::MOTORGRADER: {
                equipment = "Автогрейдер ДЗ-98 на платформі";
                MotorGrader();
                break;
            }
            case EQUIPMENT::SCRAPER: {
                equipment = "Скрепер Д-357П на платформі";
                Scraper();
                break;
            }
            case EQUIPMENT::KRAZ_PL: {
                equipment = "КрАЗ-256 порожній на платформі";
                KRAZ_PL();
                break;
            }
            case EQUIPMENT::KRAZ: {
                equipment = "КрАЗ-256 порожній над зчепом";
                KRAZ();
                break;
            }
            case EQUIPMENT::VGM: {
                equipment = "Танк";
                VGM();
                break;
            }
        }
    } catch (DatabaseException ob) {
        frame message;
        message.result = "Помилка програми, будь-ласка перевірте наявність бази даних";
        message.preparation = ob.what();
        Message_Form *object = new Message_Form(message);
        object->show();
    }
    this->close();
}

void MainWindow::on_pushButton_2_clicked()
{
    About_Form *object = new About_Form();
    object->show();
}

void MainWindow::on_pushButton_clicked()
{
    Password_Form *object = new Password_Form();
    object->show();
}

void MainWindow::CheckFileDB() {
    std::ifstream file("DB_for_test.db");
    if(!file.is_open()) {
        throw DatabaseException("Файлу DB_for_test.db не знайдено");
    }
}

void MainWindow::Excavator() {
    ExcavatorDB DB("DB_for_test.db");

    CheckFileDB();

    if (!DB.CheckConnection()) {
        DB.createConnection();
    }
    if (!DB.CheckConnection()) {
        throw DatabaseException(DB.LastError().toStdString());
    }

    Excavator_Form *object;
    object = new Excavator_Form(DB);
    connect(object, &Excavator_Form::firstWindow, this, &MainWindow::show);
    connect(object, &Excavator_Form::win, this, &MainWindow::win);
    connect(object, &Excavator_Form::fail, this, &MainWindow::fail);
    object->show();
}

void MainWindow::MotorGrader() {
    MotorGraderDB DB("DB_for_test.db");

    CheckFileDB();

    if (!DB.CheckConnection()) {
        DB.createConnection();
    }
    if (!DB.CheckConnection()) {
        throw DatabaseException(DB.LastError().toStdString());
    }

    MotorGrader_Form *object;
    object = new MotorGrader_Form(DB);
    connect(object, &MotorGrader_Form::firstWindow, this, &MainWindow::show);
    connect(object, &MotorGrader_Form::win, this, &MainWindow::win);
    connect(object, &MotorGrader_Form::fail, this, &MainWindow::fail);
    object->show();
}

void MainWindow::Bulldozer() {
    BulldozerDB DB("DB_for_test.db");

    CheckFileDB();

    if (!DB.CheckConnection()) {
        DB.createConnection();
    }
    if (!DB.CheckConnection()) {
        throw DatabaseException(DB.LastError().toStdString());
    }

    Bulldozer_Form *object;
    object = new Bulldozer_Form(DB);
    connect(object, &Bulldozer_Form::firstWindow, this, &MainWindow::show);
    connect(object, &Bulldozer_Form::win, this, &MainWindow::win);
    connect(object, &Bulldozer_Form::fail, this, &MainWindow::fail);
    object->show();
}

void MainWindow::KRAZ() {
    KRAZ_DB DB("DB_for_test.db");

    CheckFileDB();

    if (!DB.CheckConnection()) {
        DB.createConnection();
    }
    if (!DB.CheckConnection()) {
        throw DatabaseException(DB.LastError().toStdString());
    }

    KRAZ_Form *object;
    object = new KRAZ_Form(DB);
    connect(object, &KRAZ_Form::firstWindow, this, &MainWindow::show);
    connect(object, &KRAZ_Form::win, this, &MainWindow::win);
    connect(object, &KRAZ_Form::fail, this, &MainWindow::fail);
    object->show();
}

void MainWindow::KRAZ_PL() {
    KRAZ_pl_DB DB("DB_for_test.db");

    CheckFileDB();

    if (!DB.CheckConnection()) {
        DB.createConnection();
    }
    if (!DB.CheckConnection()) {
        throw DatabaseException(DB.LastError().toStdString());
    }

    KRAZ_pl_form *object;
    object = new KRAZ_pl_form(DB);
    connect(object, &KRAZ_pl_form::firstWindow, this, &MainWindow::show);
    connect(object, &KRAZ_pl_form::win, this, &MainWindow::win);
    connect(object, &KRAZ_pl_form::fail, this, &MainWindow::fail);
    object->show();
}

void MainWindow::Scraper() {
    ScraperDB DB("DB_for_test.db");

    CheckFileDB();

    if (!DB.CheckConnection()) {
        DB.createConnection();
    }
    if (!DB.CheckConnection()) {
        throw DatabaseException(DB.LastError().toStdString());
    }

    Scraper_Form *object;
    object = new Scraper_Form(DB);
    connect(object, &Scraper_Form::firstWindow, this, &MainWindow::show);
    connect(object, &Scraper_Form::win, this, &MainWindow::win);
    connect(object, &Scraper_Form::fail, this, &MainWindow::fail);
    object->show();
}

void MainWindow::VGM() {
    VGM_DB DB("DB_for_test.db");

    CheckFileDB();

    if (!DB.CheckConnection()) {
        DB.createConnection();
    }
    if (!DB.CheckConnection()) {
        throw DatabaseException(DB.LastError().toStdString());
    }

    VGM_Form *object;
    object = new VGM_Form(DB);
    connect(object, &VGM_Form::firstWindow, this, &MainWindow::show);
    connect(object, &VGM_Form::win, this, &MainWindow::win);
    connect(object, &VGM_Form::fail, this, &MainWindow::fail);
    object->show();
}

void MainWindow::win() {
    add_attemt("Склав");
}

void MainWindow::fail() {
    add_attemt("Не склав");
}

void MainWindow::add_attemt(QString result) {
    QString time = QDateTime::currentDateTime().toString("dd.MM.yyyy HH:mm:ss");
    QString name = ui->lineEdit->text();
    QString platoon = ui->lineEdit->text();
    object_user->SELECT("id, Name, Platoon", "Student", "Name = '" + name + "' AND Platoon = '" + platoon + "'");
    //qDebug() << object_user->LastError();
    std::vector<User> cont;
    object_user->GetUsers(cont);
    object_user->SELECT("id", "Equipment", "Name = '" + equipment + "'");

    Test object_test(0, cont.at(0).GetId(), cont.at(0), result, time, object_user->GetEquipmentId());

    std::vector<QString> listColumns, listValue;
    listColumns.push_back("Date");
    listColumns.push_back("Grade");
    listColumns.push_back("Student_id");
    listColumns.push_back("Equipment_id");
    listValue.push_back(object_test.GetDate());
    listValue.push_back(object_test.GetGrade());
    listValue.push_back(QString::number(object_test.GetUser_id()));
    listValue.push_back(QString::number(object_test.GetEquipment()));
    object_user->Insert("Test", listColumns, listValue);
}


void MainWindow::on_pushButton_4_clicked()
{
    this->close();
}
