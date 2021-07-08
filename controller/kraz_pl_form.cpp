#include "kraz_pl_form.h"
#include "ui_kraz_pl_form.h"

KRAZ_pl_form::KRAZ_pl_form(KRAZ_pl_DB db, User u, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KRAZ_pl_form)
{
    ui->setupUi(this);
    DB = db;
    name = "КрАЗ-256 порожній на платформі";
    scene = new QGraphicsScene;
    object_KRAZ_pl = new KRAZ_pl(DB);
    KRAZ_pl_form::set_image();

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

    QList<QLineEdit *> allEdits = this->findChildren<QLineEdit *>();
    Validation::LineEdit::SetDoubleValidator(allEdits);
}

KRAZ_pl_form::~KRAZ_pl_form()
{
    DB.close();
    delete ui;
}

void KRAZ_pl_form::show_graphics() {
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}

void KRAZ_pl_form::bar_cursor(QPen pen) {
    triangle(pen, 190, 280);
    triangle(pen, 240, 280);
    triangle(pen, 490, 280);
    triangle(pen, 640, 280);
}

void KRAZ_pl_form::bars(QPen pen) {
    scene->addLine(180, 280, 190, 280, pen);
    scene->addLine(240, 280, 250, 280, pen);
    scene->addLine(480, 280, 490, 280, pen);
    scene->addLine(640, 280, 650, 280, pen);
}

void KRAZ_pl_form::stretch_marks_cursor(QPen pen) {
    scene->addLine(80, 280, 180, 250, pen);
    scene->addLine(710, 300, 660, 250, pen);
}

void KRAZ_pl_form::on_pushButton_2_clicked()
{
    DB.close();
    this->close();
    emit firstWindow();
}

void KRAZ_pl_form::on_pushButton_clicked()
{
    Default();
    form_KRAZ_pl object_form;
    FillingFormKRAZ_pl(object_form);
    form_answer_KRAZ_pl object_answer = object_KRAZ_pl->CheckAnswer(object_form);

    frame message;
    QString grade = "";

    if (CheckAnswer(object_answer)) {
        message.result = MESSAGE::SUCCESS;
        message.string = MESSAGE::PREPARATION;
        message.preparation = MESSAGE::KRAZ_PL;
        grade = "Склав";
    } else {
        message.result = MESSAGE::FAIL;
        message.string = MESSAGE::PREPARATION;
        message.preparation = MESSAGE::KRAZ_PL;
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

void KRAZ_pl_form::set_image() {
    DB.SELECT("Icon", "Equipment", "Name = '" + name + "'");
    image(PATHS::RESOURCES + DB.GetIcon());
    show_graphics();
}

void KRAZ_pl_form::FillingFormKRAZ_pl(form_KRAZ_pl &object_form) {
    object_form.b = ui->lineEdit->text().toUInt();
    object_form.t1 = ui->lineEdit_3->text().toUInt();
    object_form.w1 = ui->lineEdit_4->text().toUInt();
    object_form.l1 = ui->lineEdit_5->text().toUInt();
    object_form.t2 = ui->lineEdit_12->text().toUInt();
    object_form.w2 = ui->lineEdit_13->text().toUInt();
    object_form.l2 = ui->lineEdit_14->text().toUInt();
    object_form.n = ui->lineEdit_6->text().toUInt();
    object_form.s = ui->lineEdit_7->text().toUInt();
    object_form.t = ui->lineEdit_8->text().toUInt();
    object_form.wd = ui->lineEdit_9->text().toUInt();
    object_form.kg = ui->lineEdit_10->text().toDouble();
    object_form.pog = ui->lineEdit_11->text().toDouble();
}

void KRAZ_pl_form::Default() {
    QList<QLineEdit *> allEdits = this->findChildren<QLineEdit *>();
    for (auto &element : allEdits) {
        element->setStyleSheet("color: rgb(0, 0, 0)");
    }
    QList<QLabel *> allLabels = this->findChildren<QLabel *>();
    for (auto &element : allLabels) {
        element->setStyleSheet("color: rgb(0, 0, 0)");
    }
}

bool KRAZ_pl_form::CheckAnswer(form_answer_KRAZ_pl form) {
    bool flag(true);

    if (!form.b) {
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
    if (!form.t2) {
        ui->lineEdit_12->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_8->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.w2) {
        ui->lineEdit_13->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_14->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.l2) {
        ui->lineEdit_14->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_7->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.n) {
        ui->lineEdit_6->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_6->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.s) {
        ui->lineEdit_7->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_9->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.t) {
        ui->lineEdit_8->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_10->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.wd) {
        ui->lineEdit_9->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_11->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.kg) {
        ui->lineEdit_10->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_12->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.pog) {
        ui->lineEdit_11->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_12->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }

    return flag;
}

void KRAZ_pl_form::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{
    if ((arg1 == -1 || arg1 == 1) && arg2 == 0) {
        bar_cursor(green_pen());
        show_graphics();
    }
}

void KRAZ_pl_form::on_lineEdit_editingFinished()
{
    for (unsigned int i = 0; i < 4; i++) {
        remove_last_item();
    }
    bars(red_pen());
    show_graphics();
}

void KRAZ_pl_form::on_lineEdit_7_cursorPositionChanged(int arg1, int arg2)
{
    if ((arg1 == -1 || arg1 == 1) && arg2 == 0) {
        stretch_marks_cursor(green_pen());
        show_graphics();
    }
}

void KRAZ_pl_form::on_lineEdit_7_editingFinished()
{
    for (unsigned int i = 0; i < 2; i++) {
        remove_last_item();
    }
    stretch_marks_cursor(red_pen());
    show_graphics();
}
