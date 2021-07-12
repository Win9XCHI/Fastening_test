#include "motorgrader_form.h"
#include "ui_motorgrader_form.h"

MotorGrader_Form::MotorGrader_Form(MotorGraderDB db, User u, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MotorGrader_Form)
{
    ui->setupUi(this);
    count1 = count2 = 0;
    name = EQUIPMENT_NAME::MOTORGRADER;
    scene = new QGraphicsScene;
    ui->comboBox->addItem(YES_NO::EMPTY);
    ui->comboBox->addItem(YES_NO::NO);
    ui->comboBox->addItem(YES_NO::YES);
    ui->comboBox_2->addItem(YES_NO::EMPTY);
    ui->comboBox_2->addItem(YES_NO::NO);
    ui->comboBox_2->addItem(YES_NO::YES);
    object_motorgrader = new MotorGrader(db);
    MotorGrader_Form::set_image();

    object_user = u;
    object_motorgrader->GetDB()->SetUser(object_user);

    QList<QLineEdit *> allEdits = this->findChildren<QLineEdit *>();
    Validation::LineEdit::SetDoubleValidator(allEdits);
}

MotorGrader_Form::~MotorGrader_Form() {
    object_motorgrader->GetDB()->close();
    delete ui;
    delete object_motorgrader;
    delete scene;
}

/* Set up image in the form
 * Input: -
 * Output: - */
void MotorGrader_Form::set_image() {
    object_motorgrader->GetDB()->SELECT("Icon", "Equipment", "Name = '" + name + "'");
    image(PATHS::RESOURCES + object_motorgrader->GetDB()->GetIcon());
    show_graphics();
}

/* Showing graphics
 * Input: -
 * Output: - */
void MotorGrader_Form::show_graphics() {
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}

/* Functions with graphics
 * Input: pen
 * Output: - */
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

/* Pressing "To main window" button
 * Input: -
 * Output: - */
void MotorGrader_Form::on_pushButton_2_clicked()
{
    emit firstWindow();
    this->~MotorGrader_Form();
}

/* Pressing "Done" button
 * Input: -
 * Output: - */
void MotorGrader_Form::on_pushButton_clicked()
{
    Default();
    form_motorgrader object_form;
    FillingFormMotorGrader(object_form);
    form_answer_motorgrader object_answer = object_motorgrader->CheckAnswer(object_form);

    frame message;
    QString grade = YES_NO::EMPTY;

    if (CheckAnswer(object_answer)) {
        message.result = MESSAGE::SUCCESS;
        grade = "Склав";
    } else {
        message.result = MESSAGE::FAIL;
        scene->clear();
        set_image();
        grade = "Не склав";
    }
    message.string = MESSAGE::PREPARATION;
    message.preparation = MESSAGE::MOTORGRADER;
    object_motorgrader->GetDB()->SetAttempt(object_user, name, grade);

    Message_Form *object = new Message_Form(message);
    object->show();
}

/* Filling а structure from form`s items
 * Input: structure
 * Output: - */
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

    ui->comboBox->currentText() == YES_NO::YES ? object_form.li1 = true : object_form.li1 = false;
    ui->comboBox_2->currentText() == YES_NO::YES ? object_form.li2 = true : object_form.li2 = false;
}

/* Doing items` color are black
 * Input: -
 * Output: - */
void MotorGrader_Form::Default() {
    QList<QLineEdit *> allEdits = this->findChildren<QLineEdit *>();
    for (auto &element : allEdits) {
        element->setStyleSheet(COLOR_EDIT::BLACK);
    }
    QList<QLabel *> allLabels = this->findChildren<QLabel *>();
    for (auto &element : allLabels) {
        element->setStyleSheet(COLOR_EDIT::BLACK);
    }
    ui->comboBox->setStyleSheet(COLOR_EDIT::BLACK);
}

/* Cheking logical structure
 * Input: structure
 * Output: - */
bool MotorGrader_Form::CheckAnswer(form_answer_motorgrader form) {
    bool flag(true);

    if (!form.s) {
        ui->lineEdit->setStyleSheet(COLOR_EDIT::RED);
        ui->label->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.t) {
        ui->lineEdit_2->setStyleSheet(COLOR_EDIT::RED);
        ui->label_2->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.wd) {
        ui->lineEdit_3->setStyleSheet(COLOR_EDIT::RED);
        ui->label_3->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.b) {
        ui->lineEdit_4->setStyleSheet(COLOR_EDIT::RED);
        ui->label_4->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.n) {
        ui->lineEdit_5->setStyleSheet(COLOR_EDIT::RED);
        ui->label_5->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.li1) {
        ui->label_9->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.li2) {
        ui->label_15->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.nli1) {
        ui->lineEdit_9->setStyleSheet(COLOR_EDIT::RED);
        ui->label_14->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.nli2) {
        ui->lineEdit_10->setStyleSheet(COLOR_EDIT::RED);
        ui->label_20->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.t1) {
        ui->lineEdit_6->setStyleSheet(COLOR_EDIT::RED);
        ui->label_11->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.t2) {
        ui->lineEdit_11->setStyleSheet(COLOR_EDIT::RED);
        ui->label_21->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.w1) {
        ui->lineEdit_7->setStyleSheet(COLOR_EDIT::RED);
        ui->label_12->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.w2) {
        ui->lineEdit_12->setStyleSheet(COLOR_EDIT::RED);
        ui->label_22->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.l1) {
        ui->lineEdit_8->setStyleSheet(COLOR_EDIT::RED);
        ui->label_13->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.l2) {
        ui->lineEdit_13->setStyleSheet(COLOR_EDIT::RED);
        ui->label_23->setStyleSheet(COLOR_EDIT::RED);
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
