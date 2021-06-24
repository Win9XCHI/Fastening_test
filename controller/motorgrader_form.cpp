#include "motorgrader_form.h"
#include "ui_motorgrader_form.h"

MotorGrader_Form::MotorGrader_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MotorGrader_Form)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    image("D:/DIIT KIT/Military/Programs/Fastening_test/Source/MotorGrade.bmp");
    stretch_marks_cursor(green_pen());
    bar_cursor(green_pen());
    lining_blade_cursor(green_pen());
    lining_grubber_cursor(green_pen());
    show_graphics();
}

MotorGrader_Form::~MotorGrader_Form() {
    delete ui;
}

void MotorGrader_Form::show_graphics() {
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}

void MotorGrader_Form::stretch_marks_cursor(QPen pen) {
    scene->addLine(120, 150, 30, 210, pen);
    scene->addLine(595, 205, 540, 160, pen);
}

void MotorGrader_Form::bar_cursor(QPen pen) {
    scene->addLine(150, 205, 160, 205, pen);
    scene->addLine(280, 205, 290, 205, pen);
    scene->addLine(510, 205, 520, 205, pen);
    scene->addLine(550, 205, 560, 205, pen);
}

void MotorGrader_Form::lining_blade_cursor(QPen pen) {
    scene->addLine(370, 205, 465, 205, pen);
}

void MotorGrader_Form::lining_grubber_cursor(QPen pen) {
    scene->addLine(615, 205, 635, 205, pen);
}
