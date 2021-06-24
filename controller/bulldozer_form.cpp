#include "bulldozer_form.h"
#include "ui_bulldozer_form.h"

Bulldozer_Form::Bulldozer_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Bulldozer_Form)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    image("D:/DIIT KIT/Military/Programs/Fastening_test/Source/bulldozer.bmp");
    show_graphics();
    stretch_marks_cursor(green_pen());
    bar_thrust_cursor(green_pen());
    bar_side_cursor(green_pen());
    lining_cursor(green_pen());
    show_graphics();
}

Bulldozer_Form::~Bulldozer_Form()
{
    delete ui;
}

void Bulldozer_Form::show_graphics() {
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}

void Bulldozer_Form::stretch_marks_cursor(QPen pen) {
    scene->addLine(20, 200, 60, 170, pen);
    scene->addLine(370, 210, 300, 150, pen);
}

void Bulldozer_Form::bar_thrust_cursor(QPen pen) {
    scene->addLine(40, 190, 60, 190, pen);
    scene->addLine(270, 195, 290, 195, pen);
}

void Bulldozer_Form::bar_side_cursor(QPen pen) {
    scene->addLine(80, 195, 250, 195, pen);
}

void Bulldozer_Form::lining_cursor(QPen pen) {
    scene->addLine(490, 220, 640, 220, pen);
}

void Bulldozer_Form::on_pushButton_clicked()
{
    this->close();
    emit firstWindow();
}

void Bulldozer_Form::on_pushButton_2_clicked()
{
    frame message;
    message.result = MESSAGE::FAIL;
    message.string = MESSAGE::PREPARATION;
    message.preparation = MESSAGE::BULLDOZER;
    Message_Form *object = new Message_Form(message);
    object->show();
}
