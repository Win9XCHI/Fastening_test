#include "kraz_form.h"
#include "ui_kraz_form.h"

KRAZ_Form::KRAZ_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KRAZ_Form)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    image("D:/DIIT KIT/Military/Programs/Fastening_test/Source/kraz.bmp");
    bar_cursor(green_pen());
    bars_thrust(green_pen(10));
    bars_side(green_pen(10));
    stretch_marks_cursor(green_pen());
    show_graphics();
}

KRAZ_Form::~KRAZ_Form()
{
    delete ui;
}

void KRAZ_Form::show_graphics() {
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}

void KRAZ_Form::bar_cursor(QPen pen) {
    triangle(pen, 120, 260);
    triangle(pen, 160, 260);
    triangle(pen, 470, 260);
    triangle(pen, 630, 260);
}

void KRAZ_Form::bars_thrust(QPen pen) {
    scene->addLine(450, 255, 470, 255, pen);
    scene->addLine(620, 255, 640, 255, pen);
}

void KRAZ_Form::bars_side(QPen pen) {
    scene->addLine(110, 255, 160, 255, pen);
}

void KRAZ_Form::stretch_marks_cursor(QPen pen) {
    scene->addLine(370, 260, 440, 220, pen);
    scene->addLine(740, 270, 670, 200, pen);
}

void KRAZ_Form::on_pushButton_2_clicked()
{
    this->close();
    emit firstWindow();
}
