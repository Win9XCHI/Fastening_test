#include "kraz_form.h"
#include "ui_kraz_form.h"

KRAZ_Form::KRAZ_Form(KRAZ_DB db, User u, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KRAZ_Form)
{
    ui->setupUi(this);
    DB = db;
    name = "КрАЗ-256 порожній над зчепом";
    scene = new QGraphicsScene;
    object_KRAZ = new KRAZ(DB);
    KRAZ_Form::set_image();

    object_user = u;
    DB.SELECT("*", "Student", "Name = '" + object_user.GetName() + "' AND Platoon = '" + object_user.GetPlatoon() + "'");
    std::vector<User> cont;
    DB.GetUsers(cont);

    if (cont.size() == 0) {
        std::vector<QString> listColumns, listValue;
        listColumns.push_back("Name");
        listColumns.push_back("Platoon");
        listValue.push_back(object_user.GetName());
        listValue.push_back(object_user.GetPlatoon());
        DB.Insert("Student", listColumns, listValue);
    }
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
    QString grade = "";

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
    DB.SELECT("*", "Student", "Name = '" + object_user.GetName() + "' AND Platoon = '" + object_user.GetPlatoon() + "'");
    std::vector<User> cont;
    DB.GetUsers(cont);
    DB.SELECT("id", "Equipment", "Name = '" + name + "'");

    std::vector<QString> listColumns, listValue;
    listColumns.push_back("Date");
    listColumns.push_back("Grade");
    listColumns.push_back("Student_id");
    listColumns.push_back("Equipment_id");
    listValue.push_back(QDateTime::currentDateTime().toString("dd.MM.yyyy HH:mm:ss"));
    listValue.push_back(grade);
    listValue.push_back(QString::number(cont.at(0).GetId()));
    listValue.push_back(QString::number(DB.GetEquipmentId()));
    DB.Insert("Test", listColumns, listValue);

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
        element->setStyleSheet("color: rgb(0, 0, 0)");
    }
    QList<QLabel *> allLabels = this->findChildren<QLabel *>();
    for (auto &element : allLabels) {
        element->setStyleSheet("color: rgb(0, 0, 0)");
    }
}

bool KRAZ_Form::CheckAnswer(form_answer_KRAZ form) {
    bool flag(true);

    if (!form.b1) {
        ui->lineEdit->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.t1) {
        ui->lineEdit_3->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_3->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.w1) {
        ui->lineEdit_4->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_4->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.l1) {
        ui->lineEdit_5->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_5->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.n1) {
        ui->lineEdit_14->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_15->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.s) {
        ui->lineEdit_9->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_10->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.t) {
        ui->lineEdit_10->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_11->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.wd) {
        ui->lineEdit_11->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_12->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.b2) {
        ui->lineEdit_2->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_6->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.t2) {
        ui->lineEdit_6->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_21->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.w2) {
        ui->lineEdit_7->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_23->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.l2) {
        ui->lineEdit_8->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_22->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.n2) {
        ui->lineEdit_15->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_16->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.kg) {
        ui->lineEdit_12->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_13->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.pog) {
        ui->lineEdit_13->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_13->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.distance1) {
        ui->lineEdit_16->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_17->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.distance2) {
        ui->lineEdit_17->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_17->setStyleSheet("color: rgb(200, 0, 0)");
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
