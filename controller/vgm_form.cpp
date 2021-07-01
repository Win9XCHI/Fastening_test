#include "vgm_form.h"
#include "ui_vgm_form.h"

VGM_Form::VGM_Form(VGM_DB db, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VGM_Form)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    DB = db;
    object_VGM = new VGM(DB);
    VGM_Form::set_image();
    count1 = count2 = 0;
}

VGM_Form::~VGM_Form()
{
    DB.close();
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
    DB.close();
    this->close();
    emit firstWindow();
}

void VGM_Form::on_pushButton_2_clicked()
{
    Default();
    form_VGM object_form;
    FillingFormVGM(object_form);
    form_answer_VGM object_answer = object_VGM->CheckAnswer(object_form);

    frame message;

    if (CheckAnswer(object_answer)) {
        message.result = MESSAGE::SUCCESS;
        message.string = MESSAGE::PREPARATION;
        message.preparation = MESSAGE::VGM;
    } else {
        message.result = MESSAGE::FAIL;
        message.string = MESSAGE::PREPARATION;
        message.preparation = MESSAGE::VGM;
        scene->clear();
        set_image();
    }
    Message_Form *object = new Message_Form(message);
    object->show();
}

void VGM_Form::set_image() {
    DB.SELECT("Icon", "Equipment", "Name = 'Танк'");
    image("D:/DIIT KIT/Military/Programs/Fastening_test/Source/" + DB.GetIcon());
    show_graphics();
}

void VGM_Form::FillingFormVGM(form_VGM &object_form) {
    object_form.s = ui->spinBox->text().toUInt();
    object_form.t = ui->spinBox_2->text().toUInt();
    object_form.b = ui->spinBox_3->text().toUInt();
    object_form.st1 = ui->spinBox_4->text().toUInt();
    object_form.n = ui->spinBox_5->text().toUInt();
    object_form.st2 = ui->spinBox_6->text().toUInt();
}

void VGM_Form::Default() {
    QList<QSpinBox *> allEdits = this->findChildren<QSpinBox *>();
    for (auto &element : allEdits) {
        element->setStyleSheet("color: rgb(0, 0, 0)");
    }
    QList<QLabel *> allLabels = this->findChildren<QLabel *>();
    for (auto &element : allLabels) {
        element->setStyleSheet("color: rgb(0, 0, 0)");
    }
}

bool VGM_Form::CheckAnswer(form_answer_VGM form) {
    bool flag(true);

    if (!form.s) {
        ui->spinBox->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_3->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.b) {
        ui->spinBox_3->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_5->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.st2) {
        ui->spinBox_6->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_9->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }

    if (!form.weight) {
        ui->lineEdit->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_2->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    } else {

        if (!form.t) {
            ui->spinBox_2->setStyleSheet("color: rgb(200, 0, 0)");
            ui->label_4->setStyleSheet("color: rgb(200, 0, 0)");
            flag = false;
        }
        if (!form.st1) {
            ui->spinBox_4->setStyleSheet("color: rgb(200, 0, 0)");
            ui->label_6->setStyleSheet("color: rgb(200, 0, 0)");
            flag = false;
        }
        if (!form.n) {
            ui->spinBox_5->setStyleSheet("color: rgb(200, 0, 0)");
            ui->label_7->setStyleSheet("color: rgb(200, 0, 0)");
            flag = false;
        }
    }

    return flag;
}

void VGM_Form::on_lineEdit_editingFinished()
{
    object_VGM->SetWeight(ui->lineEdit->text().toDouble());
}

void VGM_Form::on_spinBox_valueChanged(int arg1)
{
    stretch_marks_cursor(green_pen());
    show_graphics();
    count1++;
}

void VGM_Form::on_spinBox_editingFinished()
{
    for (unsigned int i = 0; i < count1; i++) {
        remove_last_item();
        remove_last_item();
    }
    stretch_marks_cursor(red_pen());
    show_graphics();
}

void VGM_Form::on_spinBox_3_valueChanged(int arg1)
{
    bar_cursor(green_pen());
    show_graphics();
    count2++;
}

void VGM_Form::on_spinBox_3_editingFinished()
{
    for (unsigned int i = 0; i < count2; i++) {
        remove_last_item();
        remove_last_item();
    }
    bar_cursor(red_pen());
    show_graphics();
}
