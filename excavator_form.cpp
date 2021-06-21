#include "excavator_form.h"
#include "ui_excavator_form.h"

Excavator_Form::Excavator_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Excavator_Form)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    image("D:/DIIT KIT/Military/Programs/Fastening_test/Source/excavator.bmp");
    SM_swilev_cursor(green_pen());
    SM_undercarriage_cursor(green_pen());
    SM_root_cursor(green_pen());
    SM_handle_cursor(green_pen());
    SM_trolley_cursor(green_pen());

    lining_cursor(green_pen());
    arrow_cursor(green_pen());
    axisT_cursor(green_pen());
    axisL_cursor(green_pen());
    show_graphics();
}

Excavator_Form::~Excavator_Form()
{
    delete ui;
}

void Excavator_Form::show_graphics() {
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}

void Excavator_Form::SM_swilev_cursor(QPen pen) {
    triangle(pen, 180, 130);
}

void Excavator_Form::SM_undercarriage_cursor(QPen pen) {
    triangle(pen, 245, 170);
    triangle(pen, 375, 170);
}

void Excavator_Form::SM_root_cursor(QPen pen) {
    triangle(pen, 330, 110);
}

void Excavator_Form::SM_handle_cursor(QPen pen) {
    triangle(pen, 590, 100);
}

void Excavator_Form::SM_trolley_cursor(QPen pen) {
    triangle(pen, 310, 190);
}

void Excavator_Form::lining_cursor(QPen pen) {
    triangle(pen, 520, 190);
}

void Excavator_Form::arrow_cursor(QPen pen) {
    scene->addLine(450, 35, 700, 35, pen);
    scene->addLine(700, 35, 700, 190, pen);
    scene->addLine(700, 190, 520, 190, pen);
}

void Excavator_Form::axisT_cursor(QPen pen) {
    scene->addLine(310, 0, 310, 220, pen);
}

void Excavator_Form::axisL_cursor(QPen pen) {
    scene->addLine(100, 140, 400, 140, pen);
}
