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
    bar_thrust_cursor(green_pen());
    lining_cursor(green_pen());
    bar_side_cursor(green_pen(10));
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
    scene->addLine(10, 190, 105, 135, pen);
    scene->addLine(160, 190, 235, 145, pen);
    scene->addLine(680, 190, 570, 145, pen);
    scene->addLine(750, 190, 660, 120, pen);
}

void Scraper_Form::bar_thrust_cursor(QPen pen) {
    scene->addLine(210, 185, 220, 185, pen);
    scene->addLine(250, 185, 260, 185, pen);
    scene->addLine(540, 185, 550, 185, pen);
    scene->addLine(590, 185, 600, 185, pen);
}

void Scraper_Form::bar_side_cursor(QPen pen) {
    scene->addLine(380, 180, 400, 180, pen);
}

void Scraper_Form::lining_cursor(QPen pen) {
    scene->addLine(220, 185, 250, 185, pen);
    scene->addLine(550, 185, 590, 185, pen);
}


void Scraper_Form::on_pushButton_clicked()
{
    this->close();
    emit firstWindow();
}

void Scraper_Form::on_pushButton_2_clicked()
{
    frame message;
    message.result = MESSAGE::FAIL;
    message.string = MESSAGE::PREPARATION;
    message.preparation = MESSAGE::SCRAPER;
    Message_Form *object = new Message_Form(message);
    object->show();
}

void Scraper_Form::set_image() {

}
