#include "kraz_pl_form.h"
#include "ui_kraz_pl_form.h"

KRAZ_pl_form::KRAZ_pl_form(KRAZ_pl_DB db, User u, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KRAZ_pl_form)
{
    ui->setupUi(this);
    name = EQUIPMENT_NAME::KRAZ_PL;
    scene = new QGraphicsScene;
    object_KRAZ_pl = new KRAZ_pl(db);
    KRAZ_pl_form::set_image();

    object_user = u;
    object_KRAZ_pl->GetDB()->SetUser(object_user);

    QList<QLineEdit *> allEdits = this->findChildren<QLineEdit *>();
    Validation::LineEdit::SetDoubleValidator(allEdits);
}

KRAZ_pl_form::~KRAZ_pl_form()
{
    object_KRAZ_pl->GetDB()->close();
    delete ui;
    delete object_KRAZ_pl;
    delete scene;
}

/* Showing graphics
 * Input: -
 * Output: - */
void KRAZ_pl_form::show_graphics() {
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}

/* Functions with graphics
 * Input: pen
 * Output: - */
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

/* Pressing "To main window" button
 * Input: -
 * Output: - */
void KRAZ_pl_form::on_pushButton_2_clicked()
{
    emit firstWindow();
    this->~KRAZ_pl_form();
}

/* Pressing "Done" button
 * Input: -
 * Output: - */
void KRAZ_pl_form::on_pushButton_clicked()
{
    Default();
    form_KRAZ_pl object_form;
    FillingFormKRAZ_pl(object_form);
    form_answer_KRAZ_pl object_answer = object_KRAZ_pl->CheckAnswer(object_form);

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
    message.preparation = MESSAGE::KRAZ_PL;
    object_KRAZ_pl->GetDB()->SetAttempt(object_user, name, grade);

    Message_Form *object = new Message_Form(message);
    object->show();
}

/* Set up image in the form
 * Input: -
 * Output: - */
void KRAZ_pl_form::set_image() {
    object_KRAZ_pl->GetDB()->SELECT("Icon", "Equipment", "Name = '" + name + "'");
    image(PATHS::RESOURCES + object_KRAZ_pl->GetDB()->GetIcon());
    show_graphics();
}

/* Filling а structure from form`s items
 * Input: structure
 * Output: - */
void KRAZ_pl_form::FillingFormKRAZ_pl(form_KRAZ_pl &object_form) {
    object_form.b = ui->lineEdit->text().toUInt();
    object_form.t1 = ui->lineEdit_12->text().toUInt();
    object_form.w1 = ui->lineEdit_4->text().toUInt();
    object_form.l1 = ui->lineEdit_5->text().toUInt();
    object_form.t2 = ui->lineEdit_3->text().toUInt();
    object_form.w2 = ui->lineEdit_13->text().toUInt();
    object_form.l2 = ui->lineEdit_14->text().toUInt();
    object_form.n = ui->lineEdit_6->text().toUInt();
    object_form.s = ui->lineEdit_7->text().toUInt();
    object_form.t = ui->lineEdit_8->text().toUInt();
    object_form.wd = ui->lineEdit_9->text().toUInt();
    object_form.kg = ui->lineEdit_10->text().toDouble();
    object_form.pog = ui->lineEdit_11->text().toDouble();
}

/* Doing items` color are black
 * Input: -
 * Output: - */
void KRAZ_pl_form::Default() {
    QList<QLineEdit *> allEdits = this->findChildren<QLineEdit *>();
    for (auto &element : allEdits) {
        element->setStyleSheet(COLOR_EDIT::BLACK);
    }
    QList<QLabel *> allLabels = this->findChildren<QLabel *>();
    for (auto &element : allLabels) {
        element->setStyleSheet(COLOR_EDIT::BLACK);
    }
}

/* Cheking logical structure
 * Input: structure
 * Output: - */
bool KRAZ_pl_form::CheckAnswer(form_answer_KRAZ_pl form) {
    bool flag(true);

    if (!form.b) {
        ui->lineEdit->setStyleSheet(COLOR_EDIT::RED);
        ui->label->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.t1) {
        ui->lineEdit_3->setStyleSheet(COLOR_EDIT::RED);
        ui->label_5->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.w1) {
        ui->lineEdit_4->setStyleSheet(COLOR_EDIT::RED);
        ui->label_4->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.l1) {
        ui->lineEdit_5->setStyleSheet(COLOR_EDIT::RED);
        ui->label_3->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.t2) {
        ui->lineEdit_12->setStyleSheet(COLOR_EDIT::RED);
        ui->label_7->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.w2) {
        ui->lineEdit_13->setStyleSheet(COLOR_EDIT::RED);
        ui->label_14->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.l2) {
        ui->lineEdit_14->setStyleSheet(COLOR_EDIT::RED);
        ui->label_8->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.n) {
        ui->lineEdit_6->setStyleSheet(COLOR_EDIT::RED);
        ui->label_6->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.s) {
        ui->lineEdit_7->setStyleSheet(COLOR_EDIT::RED);
        ui->label_9->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.t) {
        ui->lineEdit_8->setStyleSheet(COLOR_EDIT::RED);
        ui->label_10->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.wd) {
        ui->lineEdit_9->setStyleSheet(COLOR_EDIT::RED);
        ui->label_11->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.kg) {
        ui->lineEdit_10->setStyleSheet(COLOR_EDIT::RED);
        ui->label_12->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.pog) {
        ui->lineEdit_11->setStyleSheet(COLOR_EDIT::RED);
        ui->label_12->setStyleSheet(COLOR_EDIT::RED);
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
