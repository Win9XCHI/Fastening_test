#include "scraper_form.h"
#include "ui_scraper_form.h"

Scraper_Form::Scraper_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Scraper_Form)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    image("D:/DIIT KIT/Military/Programs/Fastening_test/Source/scraper.bmp");
    show_graphics();
}

Scraper_Form::~Scraper_Form()
{
    delete ui;
}

void Scraper_Form::show_graphics() {
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}
