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
    axis_turnover_cursor(green_pen());
    axis_longitudinal_cursor(green_pen());

    SM_swilev(green_pen());
    SM_undercarriage(green_pen());
    SM_root(green_pen());
    SM_handle(green_pen());
    SM_trolley(green_pen());

    bar_thrust(green_pen());
    bar_side(green_pen(10));
    lining(green_pen());
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

void Excavator_Form::axis_turnover_cursor(QPen pen) {
    scene->addLine(310, 0, 310, 220, pen);
}

void Excavator_Form::axis_longitudinal_cursor(QPen pen) {
    scene->addLine(100, 140, 400, 140, pen);
}

void Excavator_Form::SM_swilev(QPen pen) {
    scene->addLine(100, 190, 180, 130, pen);
}

void Excavator_Form::SM_undercarriage(QPen pen) {
    scene->addLine(200, 190, 220, 170, pen);
    scene->addLine(500, 200, 395, 170, pen);
}

void Excavator_Form::SM_root(QPen pen) {
    scene->addLine(330, 110, 395, 200, pen);
    scene->addLine(330, 110, 500, 200, pen);
}

void Excavator_Form::SM_handle(QPen pen) {
    scene->addLine(590, 100, 635, 220, pen);
}

void Excavator_Form::SM_trolley(QPen pen) {
    scene->addLine(245, 170, 310, 190, pen);
    scene->addLine(310, 190, 375, 170, pen);
}

void Excavator_Form::bar_thrust(QPen pen) {
    scene->addLine(225, 190, 235, 190, pen);
    scene->addLine(390, 190, 400, 190, pen);
}

void Excavator_Form::bar_side(QPen pen) {
    scene->addLine(240, 185, 390, 185, pen);
}

void Excavator_Form::lining(QPen pen) {
    scene->addLine(505, 187, 530, 187, pen);
}

void Excavator_Form::on_pushButton_2_clicked()
{
    this->close();
    emit firstWindow();
}

void Excavator_Form::on_pushButton_clicked()
{
    frame message;
    message.result = MESSAGE::FAIL;
    message.string = MESSAGE::PREPARATION;
    message.preparation = MESSAGE::EXCAVATOR;
    Message_Form *object = new Message_Form(message);
    object->show();
}
