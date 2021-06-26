#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*DB = new ProjectDB("DB.db");

    if (!DB->CheckConnection()) {
        DB->createConnection();
    }*/

    ui->comboBox->addItem("Екскаватор ЕО-4125 на платформі");
    ui->comboBox->addItem("Бульдозер на платформі");
    ui->comboBox->addItem("Автогрейдер ДЗ-98 на платформі");
    ui->comboBox->addItem("Скрепер Д-357П на платформі");
    ui->comboBox->addItem("КрАЗ-256 порожній на платформі");
    ui->comboBox->addItem("КрАЗ-256 порожній над зчепом");
    ui->comboBox->addItem("Танк");

    //MotorGrader_Form *object;
    //object = new MotorGrader_Form(this);
    //Excavator_Form *object;
    //object = new Excavator_Form(this);
    //Bulldozer_Form *object;
    //object = new Bulldozer_Form(this);
    //Scraper_Form *object;
    //object = new Scraper_Form(this);
    //KRAZ_pl_form *object;
    //object = new KRAZ_pl_form(this);
    //KRAZ_Form *object;
    //object = new KRAZ_Form(this);
    //VGM_Form *object;
    //object = new VGM_Form(this);
    //object->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_3_clicked() {

    switch(ui->comboBox->currentIndex()) {
        case EQUIPMENT::EXCAVATOR: {
            ExcavatorDB DB("DB_for_test.db");

            if (!DB.CheckConnection()) {
                DB.createConnection();
            }
            if (!DB.CheckConnection()) {
                //throw;
            }

            Excavator_Form *object;
            object = new Excavator_Form(DB);
            connect(object, &Excavator_Form::firstWindow, this, &MainWindow::show);
            object->show();
            break;
        }
        case EQUIPMENT::BULLDOZER: {
            Bulldozer_Form *object;
            object = new Bulldozer_Form();
            connect(object, &Bulldozer_Form::firstWindow, this, &MainWindow::show);
            object->show();
            break;
        }
        case EQUIPMENT::MOTORGRADER: {
            MotorGrader_Form *object;
            object = new MotorGrader_Form();
            connect(object, &MotorGrader_Form::firstWindow, this, &MainWindow::show);
            object->show();
            break;
        }
        case EQUIPMENT::SCRAPER: {
            Scraper_Form *object;
            object = new Scraper_Form();
            connect(object, &Scraper_Form::firstWindow, this, &MainWindow::show);
            object->show();
            break;
        }
        case EQUIPMENT::KRAZ_PL: {
            KRAZ_pl_form *object;
            object = new KRAZ_pl_form();
            connect(object, &KRAZ_pl_form::firstWindow, this, &MainWindow::show);
            object->show();
            break;
        }
        case EQUIPMENT::KRAZ: {
            KRAZ_Form *object;
            object = new KRAZ_Form();
            connect(object, &KRAZ_Form::firstWindow, this, &MainWindow::show);
            object->show();
            break;
        }
        case EQUIPMENT::VGM: {
            VGM_Form *object;
            object = new VGM_Form();
            connect(object, &VGM_Form::firstWindow, this, &MainWindow::show);
            object->show();
            break;
        }
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
