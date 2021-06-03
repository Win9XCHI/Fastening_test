#include "motorgrader_form.h"
#include "ui_motorgrader_form.h"

MotorGrader_Form::MotorGrader_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MotorGrader_Form)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    image("D:/DIIT KIT/Military/Programs/Fastening_test/Source/MotorGrade.bmp");
    stretchMarks_cursor();
    show_graphics();
}

MotorGrader_Form::~MotorGrader_Form() {
    delete ui;
}

void MotorGrader_Form::show_graphics() {
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}

void MotorGrader_Form::stretchMarks_cursor() {
    QPen pen(Qt::green);
    pen.setWidth(5);
    scene->addLine(120, 150, 30, 210, pen);
    scene->addLine(595, 205, 540, 160, pen);
}

void MotorGrader_Form::bars_cursor() {

}

void MotorGrader_Form::lining_cursor() {

}
