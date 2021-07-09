#include "kraz_form.h"
#include "ui_kraz_form.h"

KRAZ_Form::KRAZ_Form(KRAZ_DB db, User u, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KRAZ_Form)
{
    ui->setupUi(this);
    DB = db;
    name = EQUIPMENT_NAME::KRAZ;
    scene = new QGraphicsScene;
    object_KRAZ = new KRAZ(DB);
    KRAZ_Form::set_image();

    object_user = u;
    DB.SetUser(object_user);

    QList<QLineEdit *> allEdits = this->findChildren<QLineEdit *>();
    Validation::LineEdit::SetDoubleValidator(allEdits);
}

KRAZ_Form::~KRAZ_Form()
{
    DB.close();
    delete ui;
}

void KRAZ_Form::show_graphics() {
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}

void KRAZ_Form::bar_side_cursor(QPen pen) {
    triangle(pen, 120, 260);
    triangle(pen, 160, 260);
}

void KRAZ_Form::bar_thrust_cursor(QPen pen) {
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
    DB.close();
    this->close();
    emit firstWindow();
}

void KRAZ_Form::on_pushButton_clicked()
{
    Default();
    form_KRAZ object_form;
    FillingFormKRAZ(object_form);
    form_answer_KRAZ object_answer = object_KRAZ->CheckAnswer(object_form);

    frame message;
    QString grade = YES_NO::EMPTY;

    if (CheckAnswer(object_answer)) {
        message.result = MESSAGE::SUCCESS;
        message.string = MESSAGE::PREPARATION;
        message.preparation = MESSAGE::KRAZ;
        grade = "Склав";
    } else {
        message.result = MESSAGE::FAIL;
        message.string = MESSAGE::PREPARATION;
        message.preparation = MESSAGE::KRAZ;
        scene->clear();
        set_image();
        grade = "Не склав";
    }
    DB.SetAttempt(object_user, name, grade);

    Message_Form *object = new Message_Form(message);
    object->show();
}

void KRAZ_Form::set_image() {
    DB.SELECT("Icon", "Equipment", "Name = '" + name + "'");
    image(PATHS::RESOURCES + DB.GetIcon());
    show_graphics();
}

void KRAZ_Form::FillingFormKRAZ(form_KRAZ &object_form) {
    object_form.b1 = ui->lineEdit->text().toUInt();
    object_form.t1 = ui->lineEdit_3->text().toUInt();
    object_form.w1 = ui->lineEdit_4->text().toUInt();
    object_form.l1 = ui->lineEdit_5->text().toUInt();
    object_form.n1 = ui->lineEdit_15->text().toUInt();
    object_form.s = ui->lineEdit_9->text().toUInt();
    object_form.t = ui->lineEdit_10->text().toUInt();
    object_form.wd = ui->lineEdit_11->text().toUInt();
    object_form.b2 = ui->lineEdit_2->text().toUInt();
    object_form.t2 = ui->lineEdit_6->text().toUInt();
    object_form.w2 = ui->lineEdit_7->text().toUInt();
    object_form.l2 = ui->lineEdit_8->text().toUInt();
    object_form.n2 = ui->lineEdit_15->text().toUInt();
    object_form.kg = ui->lineEdit_12->text().toDouble();
    object_form.pog = ui->lineEdit_13->text().toDouble();
    object_form.distance1 = ui->lineEdit_16->text().toUInt();
    object_form.distance2 = ui->lineEdit_17->text().toUInt();
}

void KRAZ_Form::Default() {
    QList<QLineEdit *> allEdits = this->findChildren<QLineEdit *>();
    for (auto &element : allEdits) {
        element->setStyleSheet(COLOR_EDIT::BLACK);
    }
    QList<QLabel *> allLabels = this->findChildren<QLabel *>();
    for (auto &element : allLabels) {
        element->setStyleSheet(COLOR_EDIT::BLACK);
    }
}

bool KRAZ_Form::CheckAnswer(form_answer_KRAZ form) {
    bool flag(true);

    if (!form.b1) {
        ui->lineEdit->setStyleSheet(COLOR_EDIT::RED);
        ui->label->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.t1) {
        ui->lineEdit_3->setStyleSheet(COLOR_EDIT::RED);
        ui->label_3->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.w1) {
        ui->lineEdit_4->setStyleSheet(COLOR_EDIT::RED);
        ui->label_4->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.l1) {
        ui->lineEdit_5->setStyleSheet(COLOR_EDIT::RED);
        ui->label_5->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.n1) {
        ui->lineEdit_14->setStyleSheet(COLOR_EDIT::RED);
        ui->label_15->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.s) {
        ui->lineEdit_9->setStyleSheet(COLOR_EDIT::RED);
        ui->label_10->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.t) {
        ui->lineEdit_10->setStyleSheet(COLOR_EDIT::RED);
        ui->label_11->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.wd) {
        ui->lineEdit_11->setStyleSheet(COLOR_EDIT::RED);
        ui->label_12->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.b2) {
        ui->lineEdit_2->setStyleSheet(COLOR_EDIT::RED);
        ui->label_6->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.t2) {
        ui->lineEdit_6->setStyleSheet(COLOR_EDIT::RED);
        ui->label_21->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.w2) {
        ui->lineEdit_7->setStyleSheet(COLOR_EDIT::RED);
        ui->label_23->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.l2) {
        ui->lineEdit_8->setStyleSheet(COLOR_EDIT::RED);
        ui->label_22->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.n2) {
        ui->lineEdit_15->setStyleSheet(COLOR_EDIT::RED);
        ui->label_16->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.kg) {
        ui->lineEdit_12->setStyleSheet(COLOR_EDIT::RED);
        ui->label_13->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.pog) {
        ui->lineEdit_13->setStyleSheet(COLOR_EDIT::RED);
        ui->label_13->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.distance1) {
        ui->lineEdit_16->setStyleSheet(COLOR_EDIT::RED);
        ui->label_17->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.distance2) {
        ui->lineEdit_17->setStyleSheet(COLOR_EDIT::RED);
        ui->label_17->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }

    return flag;
}

void KRAZ_Form::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{
    if ((arg1 == -1 || arg1 == 1) && arg2 == 0) {
        bar_thrust_cursor(green_pen());
        show_graphics();
    }
}

void KRAZ_Form::on_lineEdit_editingFinished()
{
    for (unsigned int i = 0; i < 2; i++) {
        remove_last_item();
    }
    bars_thrust(red_pen(10));
    show_graphics();
}

void KRAZ_Form::on_lineEdit_2_cursorPositionChanged(int arg1, int arg2)
{
    if ((arg1 == -1 || arg1 == 1) && arg2 == 0) {
        bar_side_cursor(green_pen());
        show_graphics();
    }
}

void KRAZ_Form::on_lineEdit_2_editingFinished()
{
    for (unsigned int i = 0; i < 2; i++) {
        remove_last_item();
    }
    bars_side(red_pen(10));
    show_graphics();
}

void KRAZ_Form::on_lineEdit_9_cursorPositionChanged(int arg1, int arg2)
{
    if ((arg1 == -1 || arg1 == 1) && arg2 == 0) {
        stretch_marks_cursor(green_pen());
        show_graphics();
    }
}

void KRAZ_Form::on_lineEdit_9_editingFinished()
{
    for (unsigned int i = 0; i < 2; i++) {
        remove_last_item();
    }
    stretch_marks_cursor(red_pen());
    show_graphics();
}
