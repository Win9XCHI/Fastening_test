#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem(EQUIPMENT_NAME::EXCAVATOR);
    ui->comboBox->addItem(EQUIPMENT_NAME::BULLDOZER);
    ui->comboBox->addItem(EQUIPMENT_NAME::MOTORGRADER);
    ui->comboBox->addItem(EQUIPMENT_NAME::SCRAPER);
    ui->comboBox->addItem(EQUIPMENT_NAME::KRAZ_PL);
    ui->comboBox->addItem(EQUIPMENT_NAME::KRAZ);
    ui->comboBox->addItem(EQUIPMENT_NAME::VGM);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_3_clicked() {

    if (!Validation::CheckPIB(ui->lineEdit->text())) {
        ui->label->setStyleSheet(COLOR_EDIT::RED);
        return;
    }
    if (!Validation::CheckPlatoon(ui->lineEdit_2->text())) {
        ui->label_2->setStyleSheet(COLOR_EDIT::RED);
        return;
    }

    try {
        CheckFileDB();

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
    CheckFileDB();
    AdminDB DB(PATHS::DB);

    if (!DB.CheckConnection()) {
        DB.createConnection();
    }
    if (!DB.CheckConnection()) {
        throw DatabaseException(DB.LastError().toStdString());
    }

    Password_Form *object = new Password_Form(DB);
    connect(object, &Password_Form::succes, this, &MainWindow::close);
    connect(object, &Password_Form::return_main, this, &MainWindow::show);
    object->show();
}

void MainWindow::CheckFileDB() {
    std::ifstream file(PATHS::DB.toStdString());
    if(!file.is_open()) {
        throw DatabaseException("Файлу DB_for_test.db не знайдено");
    }
}

void MainWindow::Excavator() {
    ExcavatorDB DB(PATHS::DB);

    if (!DB.CheckConnection()) {
        DB.createConnection();
    }
    if (!DB.CheckConnection()) {
        throw DatabaseException(DB.LastError().toStdString());
    }

    Excavator_Form *object;
    object = new Excavator_Form(DB, create_user());
    connect(object, &Excavator_Form::firstWindow, this, &MainWindow::show);
    object->show();
}

void MainWindow::MotorGrader() {
    MotorGraderDB DB(PATHS::DB);

    if (!DB.CheckConnection()) {
        DB.createConnection();
    }
    if (!DB.CheckConnection()) {
        throw DatabaseException(DB.LastError().toStdString());
    }

    MotorGrader_Form *object;
    object = new MotorGrader_Form(DB, create_user());
    connect(object, &MotorGrader_Form::firstWindow, this, &MainWindow::show);
    object->show();
}

void MainWindow::Bulldozer() {
    BulldozerDB DB(PATHS::DB);

    if (!DB.CheckConnection()) {
        DB.createConnection();
    }
    if (!DB.CheckConnection()) {
        throw DatabaseException(DB.LastError().toStdString());
    }

    Bulldozer_Form *object;
    object = new Bulldozer_Form(DB, create_user());
    connect(object, &Bulldozer_Form::firstWindow, this, &MainWindow::show);
    object->show();
}

void MainWindow::KRAZ() {
    KRAZ_DB DB(PATHS::DB);

    if (!DB.CheckConnection()) {
        DB.createConnection();
    }
    if (!DB.CheckConnection()) {
        throw DatabaseException(DB.LastError().toStdString());
    }

    KRAZ_Form *object;
    object = new KRAZ_Form(DB, create_user());
    connect(object, &KRAZ_Form::firstWindow, this, &MainWindow::show);
    object->show();
}

void MainWindow::KRAZ_PL() {
    KRAZ_pl_DB DB(PATHS::DB);

    if (!DB.CheckConnection()) {
        DB.createConnection();
    }
    if (!DB.CheckConnection()) {
        throw DatabaseException(DB.LastError().toStdString());
    }

    KRAZ_pl_form *object;
    object = new KRAZ_pl_form(DB, create_user());
    connect(object, &KRAZ_pl_form::firstWindow, this, &MainWindow::show);
    object->show();
}

void MainWindow::Scraper() {
    ScraperDB DB(PATHS::DB);

    if (!DB.CheckConnection()) {
        DB.createConnection();
    }
    if (!DB.CheckConnection()) {
        throw DatabaseException(DB.LastError().toStdString());
    }

    Scraper_Form *object;
    object = new Scraper_Form(DB, create_user());
    connect(object, &Scraper_Form::firstWindow, this, &MainWindow::show);
    object->show();
}

void MainWindow::VGM() {
    VGM_DB DB(PATHS::DB);

    if (!DB.CheckConnection()) {
        DB.createConnection();
    }
    if (!DB.CheckConnection()) {
        throw DatabaseException(DB.LastError().toStdString());
    }

    VGM_Form *object;
    object = new VGM_Form(DB, create_user());
    connect(object, &VGM_Form::firstWindow, this, &MainWindow::show);
    object->show();
}

User MainWindow::create_user() {
    return {ui->lineEdit->text(), ui->lineEdit_2->text()};
}


void MainWindow::on_pushButton_4_clicked()
{
    this->close();
}
