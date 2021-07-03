#include "motorgrader_form.h"
#include "ui_motorgrader_form.h"

MotorGrader_Form::MotorGrader_Form(MotorGraderDB db, User u, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MotorGrader_Form)
{
    ui->setupUi(this);
    DB = db;
    count1 = count2 = 0;
    name = "Автогрейдер ДЗ-98 на платформі";
    scene = new QGraphicsScene;
    ui->comboBox->addItem("");
    ui->comboBox->addItem("Ні");
    ui->comboBox->addItem("Так");
    ui->comboBox_2->addItem("");
    ui->comboBox_2->addItem("Ні");
    ui->comboBox_2->addItem("Так");
    object_motorgrader = new MotorGrader(DB);
    MotorGrader_Form::set_image();

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

MotorGrader_Form::~MotorGrader_Form() {
    DB.close();
    delete ui;
}

void MotorGrader_Form::set_image() {
    DB.SELECT("Icon", "Equipment", "Name = '" + name + "'");
    image(PATHS::RESOURCES + DB.GetIcon());
    show_graphics();
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

void MotorGrader_Form::on_pushButton_2_clicked()
{
    DB.close();
    this->close();
    emit firstWindow();
}

void MotorGrader_Form::on_pushButton_clicked()
{
    Default();
    form_motorgrader object_form;
    FillingFormMotorGrader(object_form);
    form_answer_motorgrader object_answer = object_motorgrader->CheckAnswer(object_form);

    frame message;
    QString grade = "";

    if (CheckAnswer(object_answer)) {
        message.result = MESSAGE::SUCCESS;
        message.string = MESSAGE::PREPARATION;
        message.preparation = MESSAGE::MOTORGRADER;
        grade = "Склав";
    } else {
        message.result = MESSAGE::FAIL;
        message.string = MESSAGE::PREPARATION;
        message.preparation = MESSAGE::MOTORGRADER;
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

void MotorGrader_Form::FillingFormMotorGrader(form_motorgrader &object_form) {
    object_form.s = ui->lineEdit->text().toUInt();
    object_form.t = ui->lineEdit_2->text().toUInt();
    object_form.wd = ui->lineEdit_3->text().toUInt();
    object_form.b = ui->lineEdit_4->text().toUInt();
    object_form.n = ui->lineEdit_5->text().toUInt();
    object_form.nli1 = ui->lineEdit_9->text().toUInt();
    object_form.nli2 = ui->lineEdit_10->text().toUInt();
    object_form.t1 = ui->lineEdit_6->text().toUInt();
    object_form.t2 = ui->lineEdit_11->text().toUInt();
    object_form.w1 = ui->lineEdit_7->text().toUInt();
    object_form.w2 = ui->lineEdit_12->text().toUInt();
    object_form.l1 = ui->lineEdit_8->text().toUInt();
    object_form.l2 = ui->lineEdit_13->text().toUInt();

    ui->comboBox->currentText() == "Так" ? object_form.li1 = true : object_form.li1 = false;
    ui->comboBox_2->currentText() == "Так" ? object_form.li2 = true : object_form.li2 = false;
}

void MotorGrader_Form::Default() {
    QList<QLineEdit *> allEdits = this->findChildren<QLineEdit *>();
    for (auto &element : allEdits) {
        element->setStyleSheet("color: rgb(0, 0, 0)");
    }
    QList<QLabel *> allLabels = this->findChildren<QLabel *>();
    for (auto &element : allLabels) {
        element->setStyleSheet("color: rgb(0, 0, 0)");
    }
    ui->comboBox->setStyleSheet("color: rgb(0, 0, 0)");
}

bool MotorGrader_Form::CheckAnswer(form_answer_motorgrader form) {
    bool flag(true);

    if (!form.s) {
        ui->lineEdit->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.t) {
        ui->lineEdit_2->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_2->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.wd) {
        ui->lineEdit_3->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_3->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.b) {
        ui->lineEdit_4->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_4->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.n) {
        ui->lineEdit_5->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_5->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.li1) {
        ui->label_9->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.li2) {
        ui->label_15->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.nli1) {
        ui->lineEdit_9->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_14->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.nli2) {
        ui->lineEdit_10->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_20->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.t1) {
        ui->lineEdit_6->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_11->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.t2) {
        ui->lineEdit_11->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_21->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.w1) {
        ui->lineEdit_7->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_12->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.w2) {
        ui->lineEdit_12->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_22->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.l1) {
        ui->lineEdit_8->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_13->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.l2) {
        ui->lineEdit_13->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_23->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }

    return flag;
}

void MotorGrader_Form::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{
    if ((arg1 == -1 || arg1 == 1) && arg2 == 0) {
        stretch_marks_cursor(green_pen());
        show_graphics();
    }
}

void MotorGrader_Form::on_lineEdit_editingFinished()
{
    remove_last_item();
    remove_last_item();
    stretch_marks_cursor(red_pen());
    show_graphics();
}

void MotorGrader_Form::on_lineEdit_4_cursorPositionChanged(int arg1, int arg2)
{
    if ((arg1 == -1 || arg1 == 1) && arg2 == 0) {
        bar_cursor(green_pen());
        show_graphics();
    }
}

void MotorGrader_Form::on_lineEdit_4_editingFinished()
{
    for (unsigned int i = 0; i < 4; i++) {
        remove_last_item();
    }
    bar_cursor(red_pen());
    show_graphics();
}

void MotorGrader_Form::on_comboBox_highlighted(int index)
{
    lining_blade_cursor(green_pen());
    count1++;
    show_graphics();
}

void MotorGrader_Form::on_comboBox_activated(int index)
{
    for (unsigned int i = 0; i < count1; i++) {
        remove_last_item();
    }
    count1 = 0;
    lining_blade_cursor(red_pen());
    show_graphics();
}

void MotorGrader_Form::on_comboBox_2_highlighted(int index)
{
    lining_grubber_cursor(green_pen());
    count2++;
    show_graphics();
}

void MotorGrader_Form::on_comboBox_2_activated(int index)
{
    for (unsigned int i = 0; i < count2; i++) {
        remove_last_item();
    }
    count2 = 0;
    lining_grubber_cursor(red_pen());
    show_graphics();
}
