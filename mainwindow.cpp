#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //MotorGrader_Form *ob;
    //ob = new MotorGrader_Form(this);
    //Excavator_Form *ob;
    //ob = new Excavator_Form(this);
    //Bulldozer_Form *ob;
    //ob = new Bulldozer_Form(this);
    Scraper_Form *ob;
    ob = new Scraper_Form(this);
    ob->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

