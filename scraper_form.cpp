#include "scraper_form.h"
#include "ui_scraper_form.h"

Scraper_Form::Scraper_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Scraper_Form)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    image("D:/DIIT KIT/Military/Programs/Fastening_test/Source/scraper.bmp");
    stretch_marks_cursor(green_pen());
    bar_cursor(green_pen());
    lining_blade_cursor(green_pen());
    Lining_grubber_cursor(green_pen());
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

void Scraper_Form::stretch_marks_cursor(QPen pen) {
    scene->addLine(20, 200, 60, 170, pen);
}

//Thrust Bars
void Scraper_Form::bar_cursor(QPen pen) {

}

//Lining (blade)
void Scraper_Form::lining_blade_cursor(QPen pen) {

}

//Lining (grubber)
void Scraper_Form::Lining_grubber_cursor(QPen pen) {

}

