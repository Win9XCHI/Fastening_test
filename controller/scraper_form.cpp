#include "scraper_form.h"
#include "ui_scraper_form.h"

Scraper_Form::Scraper_Form(ScraperDB db, User u, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Scraper_Form)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    DB = db;
    count = 0;
    name = "Скрепер Д-357П на платформі";
    scene = new QGraphicsScene;
    ui->comboBox->addItem("");
    ui->comboBox->addItem("Ні");
    ui->comboBox->addItem("Так");
    object_scraper = new Scraper(DB);
    Scraper_Form::set_image();

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

Scraper_Form::~Scraper_Form()
{
    DB.close();
    delete ui;
}

void Scraper_Form::show_graphics() {
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}

void Scraper_Form::stretch_marks_cursor(QPen pen) {
    scene->addLine(10, 190, 105, 135, pen);
    scene->addLine(160, 190, 235, 145, pen);
    scene->addLine(680, 190, 570, 145, pen);
    scene->addLine(750, 190, 660, 120, pen);
}

void Scraper_Form::bar_thrust_cursor(QPen pen) {
    scene->addLine(210, 185, 220, 185, pen);
    scene->addLine(250, 185, 260, 185, pen);
    scene->addLine(540, 185, 550, 185, pen);
    scene->addLine(590, 185, 600, 185, pen);
}

void Scraper_Form::bar_side_cursor(QPen pen) {
    scene->addLine(220, 185, 250, 185, pen);
    scene->addLine(550, 185, 590, 185, pen);
}

void Scraper_Form::lining_cursor(QPen pen) {
    scene->addLine(380, 180, 400, 180, pen);
}


void Scraper_Form::on_pushButton_clicked()
{
    DB.close();
    this->close();
    emit firstWindow();
}

void Scraper_Form::on_pushButton_2_clicked()
{
    Default();
    form_scraper object_form;
    FillingFormMotorScraper(object_form);
    form_answer_scraper object_answer = object_scraper->CheckAnswer(object_form);

    frame message;
    QString grade = "";

    if (CheckAnswer(object_answer)) {
        message.result = MESSAGE::SUCCESS;
        message.string = MESSAGE::PREPARATION;
        message.preparation = MESSAGE::SCRAPER;
        grade = "Склав";
    } else {
        message.result = MESSAGE::FAIL;
        message.string = MESSAGE::PREPARATION;
        message.preparation = MESSAGE::SCRAPER;
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

void Scraper_Form::set_image() {
    DB.SELECT("Icon", "Equipment", "Name = '" + name + "'");
    image(PATHS::RESOURCES + DB.GetIcon());
    show_graphics();
}

void Scraper_Form::FillingFormMotorScraper(form_scraper &object_form) {
    object_form.s = ui->lineEdit->text().toUInt();
    object_form.t = ui->lineEdit_2->text().toUInt();
    object_form.wd = ui->lineEdit_3->text().toUInt();
    object_form.b1 = ui->lineEdit_4->text().toUInt();
    object_form.n1 = ui->lineEdit_5->text().toUInt();
    object_form.b2 = ui->lineEdit_10->text().toUInt();
    object_form.n2 = ui->lineEdit_11->text().toUInt();
    object_form.t2 = ui->lineEdit_12->text().toUInt();
    object_form.w2 = ui->lineEdit_13->text().toUInt();
    object_form.l2 = ui->lineEdit_14->text().toUInt();
    object_form.nli = ui->lineEdit_9->text().toUInt();
    object_form.t1 = ui->lineEdit_6->text().toUInt();
    object_form.w1 = ui->lineEdit_7->text().toUInt();
    object_form.l1 = ui->lineEdit_8->text().toUInt();

    ui->comboBox->currentText() == "Так" ? object_form.li = true : object_form.li = false;
}

void Scraper_Form::Default() {
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

bool Scraper_Form::CheckAnswer(form_answer_scraper form) {
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
    if (!form.b1) {
        ui->lineEdit_4->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_4->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.n1) {
        ui->lineEdit_5->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_5->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.b2) {
        ui->lineEdit_10->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_12->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.n2) {
        ui->lineEdit_11->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_14->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.t2) {
        ui->lineEdit_12->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_16->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.w2) {
        ui->lineEdit_13->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_15->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.l2) {
        ui->lineEdit_14->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_17->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.li) {
        ui->label_6->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.nli) {
        ui->lineEdit_9->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_11->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.t1) {
        ui->lineEdit_6->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_8->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.w1) {
        ui->lineEdit_7->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_9->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }
    if (!form.l1) {
        ui->lineEdit_8->setStyleSheet("color: rgb(200, 0, 0)");
        ui->label_10->setStyleSheet("color: rgb(200, 0, 0)");
        flag = false;
    }

    return flag;
}

void Scraper_Form::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{
    if ((arg1 == -1 || arg1 == 1) && arg2 == 0) {
        stretch_marks_cursor(green_pen());
        show_graphics();
    }
}

void Scraper_Form::on_lineEdit_editingFinished()
{
    for (unsigned int i = 0; i < 4; i++) {
        remove_last_item();
    }
    stretch_marks_cursor(red_pen());
    show_graphics();
}

void Scraper_Form::on_lineEdit_4_cursorPositionChanged(int arg1, int arg2)
{
    if ((arg1 == -1 || arg1 == 1) && arg2 == 0) {
        bar_thrust_cursor(green_pen());
        show_graphics();
    }
}

void Scraper_Form::on_lineEdit_4_editingFinished()
{
    for (unsigned int i = 0; i < 4; i++) {
        remove_last_item();
    }
    bar_thrust_cursor(red_pen());
    show_graphics();
}

void Scraper_Form::on_comboBox_highlighted(int index)
{
    lining_cursor(green_pen());
    count++;
    show_graphics();
}

void Scraper_Form::on_comboBox_activated(int index)
{
    for (unsigned int i = 0; i < count; i++) {
        remove_last_item();
    }
    count = 0;
    lining_cursor(red_pen());
    show_graphics();
}

void Scraper_Form::on_lineEdit_10_cursorPositionChanged(int arg1, int arg2)
{
    if ((arg1 == -1 || arg1 == 1) && arg2 == 0) {
        bar_side_cursor(green_pen());
        show_graphics();
    }
}

void Scraper_Form::on_lineEdit_10_editingFinished()
{
    for (unsigned int i = 0; i < 2; i++) {
        remove_last_item();
    }
    bar_side_cursor(red_pen());
    show_graphics();
}
