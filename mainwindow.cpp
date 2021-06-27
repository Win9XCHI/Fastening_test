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
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_3_clicked() {

    try {
        switch(ui->comboBox->currentIndex()) {
            case EQUIPMENT::EXCAVATOR: {
                Excavator();
                break;
            }
            case EQUIPMENT::BULLDOZER: {
                Bulldozer();
                break;
            }
            case EQUIPMENT::MOTORGRADER: {
                MotorGrader();
                break;
            }
            case EQUIPMENT::SCRAPER: {
                Scraper();
                break;
            }
            case EQUIPMENT::KRAZ_PL: {
                KRAZ_PL();
                break;
            }
            case EQUIPMENT::KRAZ: {
                KRAZ();
                break;
            }
            case EQUIPMENT::VGM: {
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
    object->show();
}

void MainWindow::Bulldozer() {
    Bulldozer_Form *object;
    object = new Bulldozer_Form();
    connect(object, &Bulldozer_Form::firstWindow, this, &MainWindow::show);
    object->show();
}

void MainWindow::KRAZ() {
    KRAZ_Form *object;
    object = new KRAZ_Form();
    connect(object, &KRAZ_Form::firstWindow, this, &MainWindow::show);
    object->show();
}

void MainWindow::KRAZ_PL() {
    KRAZ_pl_form *object;
    object = new KRAZ_pl_form();
    connect(object, &KRAZ_pl_form::firstWindow, this, &MainWindow::show);
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
    object->show();
}

void MainWindow::VGM() {
    VGM_Form *object;
    object = new VGM_Form();
    connect(object, &VGM_Form::firstWindow, this, &MainWindow::show);
    object->show();
}

