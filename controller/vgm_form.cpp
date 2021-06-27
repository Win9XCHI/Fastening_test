#include "vgm_form.h"
#include "ui_vgm_form.h"

VGM_Form::VGM_Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VGM_Form)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    image("D:/DIIT KIT/Military/Programs/Fastening_test/Source/REZ_NULL.bmp");
    bar_cursor(green_pen());
    stretch_marks_cursor(green_pen());
    show_graphics();
}

VGM_Form::~VGM_Form()
{
    delete ui;
}

void VGM_Form::show_graphics() {
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}

void VGM_Form::bar_cursor(QPen pen) {
    QPolygonF polygon;
    polygon << QPointF(270, 155) << QPointF(280, 145) << QPointF(290, 155);
    scene->addPolygon(polygon, pen);

    QPolygonF polygon2;
    polygon2 << QPointF(560, 155) << QPointF(550, 145) << QPointF(540, 155);
    scene->addPolygon(polygon2, pen);
}

void VGM_Form::stretch_marks_cursor(QPen pen) {
    scene->addLine(100, 155, 245, 110, pen);
    scene->addLine(700, 155, 580, 125, pen);
}

void VGM_Form::on_pushButton_clicked()
{
    this->close();
    emit firstWindow();
}

void VGM_Form::on_pushButton_2_clicked()
{
    frame message;
    message.result = MESSAGE::FAIL;
    message.string = MESSAGE::PREPARATION;
    message.preparation = MESSAGE::VGM;
    Message_Form *object = new Message_Form(message);
    object->show();
}

void VGM_Form::set_image() {

}
