#include "motorgrader_form.h"
#include "ui_motorgrader_form.h"

MotorGrader_Form::MotorGrader_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MotorGrader_Form)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    image();
    stretchMarks_cursor();
    show_grapgic();
}

MotorGrader_Form::~MotorGrader_Form() {
    delete ui;
}

void MotorGrader_Form::image() {
    scene->addPixmap(QPixmap("D:/DIIT KIT/Military/Programs/Fastening_test/Source/MotorGrade.bmp"));
}

void MotorGrader_Form::show_grapgic() {
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
