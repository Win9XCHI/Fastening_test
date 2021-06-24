#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    DB = new ProjectDB("DB.db");

    if (!DB->CheckConnection()) {
        DB->createConnection();
    }

    ui->comboBox->addItem("Екскаватор ЕО-4125 на платформі");
    ui->comboBox->addItem("Бульдозер на платформі");
    ui->comboBox->addItem("Автогрейдер ДЗ-98 на платформі");
    ui->comboBox->addItem("Скрепер Д-357П на платформі");
    ui->comboBox->addItem("КрАЗ-256 порожній на платформі");
    ui->comboBox->addItem("КрАЗ-256 порожній над зчепом");
    ui->comboBox->addItem("Танк");

    //MotorGrader_Form *ob;
    //ob = new MotorGrader_Form(this);
    //Excavator_Form *ob;
    //ob = new Excavator_Form(this);
    //Bulldozer_Form *ob;
    //ob = new Bulldozer_Form(this);
    //Scraper_Form *ob;
    //ob = new Scraper_Form(this);
    //KRAZ_pl_form *ob;
    //ob = new KRAZ_pl_form(this);
    //KRAZ_Form *ob;
    //ob = new KRAZ_Form(this);
    //VGM_Form *ob;
    //ob = new VGM_Form(this);
    //ob->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_3_clicked() {

    switch(ui->comboBox->currentIndex()) {
        case EQUIPMENT::EXCAVATOR: {
            Excavator_Form *ob;
            ob = new Excavator_Form();
            connect(ob, &Excavator_Form::firstWindow, this, &MainWindow::show);
            ob->show();
            break;
        }
        case EQUIPMENT::BULLDOZER: {
            Bulldozer_Form *ob;
            ob = new Bulldozer_Form();
            connect(ob, &Bulldozer_Form::firstWindow, this, &MainWindow::show);
            ob->show();
            break;
        }
        case EQUIPMENT::MOTORGRADER: {
            MotorGrader_Form *ob;
            ob = new MotorGrader_Form();
            connect(ob, &MotorGrader_Form::firstWindow, this, &MainWindow::show);
            ob->show();
            break;
        }
        case EQUIPMENT::SCRAPER: {
            Scraper_Form *ob;
            ob = new Scraper_Form();
            connect(ob, &Scraper_Form::firstWindow, this, &MainWindow::show);
            ob->show();
            break;
        }
        case EQUIPMENT::KRAZ_PL: {
            KRAZ_pl_form *ob;
            ob = new KRAZ_pl_form();
            connect(ob, &KRAZ_pl_form::firstWindow, this, &MainWindow::show);
            ob->show();
            break;
        }
        case EQUIPMENT::KRAZ: {
            KRAZ_Form *ob;
            ob = new KRAZ_Form();
            connect(ob, &KRAZ_Form::firstWindow, this, &MainWindow::show);
            ob->show();
            break;
        }
        case EQUIPMENT::VGM: {
            VGM_Form *ob;
            ob = new VGM_Form();
            connect(ob, &VGM_Form::firstWindow, this, &MainWindow::show);
            ob->show();
            break;
        }
    }
    this->close();
}
