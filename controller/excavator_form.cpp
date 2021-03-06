#include "excavator_form.h"
#include "ui_excavator_form.h"

Excavator_Form::Excavator_Form(ExcavatorDB db, User u, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Excavator_Form)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    object_excavator = new Excavator(db);
    count = 0;
    name = EQUIPMENT_NAME::EXCAVATOR;
    ui->comboBox->addItem(YES_NO::EMPTY);
    ui->comboBox->addItem(YES_NO::NO);
    ui->comboBox->addItem(YES_NO::YES);
    Excavator_Form::set_image();

    object_user = u;
    object_excavator->GetDB()->SetUser(object_user);

    QList<QLineEdit *> allEdits = this->findChildren<QLineEdit *>();
    Validation::LineEdit::SetDoubleValidator(allEdits);
}

Excavator_Form::~Excavator_Form()
{
    object_excavator->GetDB()->close();
    delete ui;
    delete object_excavator;
    delete scene;
}

/* Showing graphics
 * Input: -
 * Output: - */
void Excavator_Form::show_graphics() {
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}

/* Functions with graphics
 * Input: pen
 * Output: - */
void Excavator_Form::SM_swilev_cursor(QPen pen) {
    triangle(pen, 180, 130);
}

void Excavator_Form::SM_undercarriage_cursor(QPen pen) {
    triangle(pen, 245, 170);
    triangle(pen, 375, 170);
}

void Excavator_Form::SM_root_cursor(QPen pen) {
    triangle(pen, 330, 110);
}

void Excavator_Form::SM_handle_cursor(QPen pen) {
    triangle(pen, 590, 100);
}

void Excavator_Form::SM_trolley_cursor(QPen pen) {
    triangle(pen, 310, 190);
}

void Excavator_Form::lining_cursor(QPen pen) {
    triangle(pen, 520, 190);
}

void Excavator_Form::arrow_cursor(QPen pen) {
    scene->addLine(450, 35, 700, 35, pen);
    scene->addLine(700, 35, 700, 190, pen);
    scene->addLine(700, 190, 520, 190, pen);
}

void Excavator_Form::axis_turnover_cursor(QPen pen) {
    scene->addLine(310, 0, 310, 220, pen);
}

void Excavator_Form::axis_longitudinal_cursor(QPen pen) {
    scene->addLine(100, 140, 400, 140, pen);
}

void Excavator_Form::SM_swilev(QPen pen) {
    scene->addLine(100, 190, 180, 130, pen);
}

void Excavator_Form::SM_undercarriage(QPen pen) {
    scene->addLine(200, 190, 220, 170, pen);
    scene->addLine(500, 200, 395, 170, pen);
}

void Excavator_Form::SM_root(QPen pen) {
    scene->addLine(330, 110, 395, 200, pen);
    scene->addLine(330, 110, 500, 200, pen);
}

void Excavator_Form::SM_handle(QPen pen) {
    scene->addLine(590, 100, 635, 220, pen);
}

void Excavator_Form::SM_trolley(QPen pen) {
    scene->addLine(245, 170, 310, 190, pen);
    scene->addLine(310, 190, 375, 170, pen);
}

void Excavator_Form::bar_thrust(QPen pen) {
    scene->addLine(225, 190, 235, 190, pen);
    scene->addLine(390, 190, 400, 190, pen);
}

void Excavator_Form::bar_side(QPen pen) {
    scene->addLine(240, 185, 390, 185, pen);
}

void Excavator_Form::lining(QPen pen) {
    scene->addLine(505, 187, 530, 187, pen);
}

/* Pressing "To main window" button
 * Input: -
 * Output: - */
void Excavator_Form::on_pushButton_2_clicked()
{
    emit firstWindow();
    this->~Excavator_Form();
}

/* Filling ?? structure from form`s items
 * Input: structure
 * Output: - */
void Excavator_Form::FillingFormExcavator(form_excavator &object_form) {
    object_form.s1 = ui->lineEdit_7->text().toUInt();
    object_form.s2 = ui->lineEdit_9->text().toUInt();
    object_form.s3 = ui->lineEdit_11->text().toUInt();
    object_form.s4 = ui->lineEdit_13->text().toUInt();
    object_form.s5 = ui->lineEdit_15->text().toUInt();

    object_form.t1 = ui->lineEdit_8->text().toUInt();
    object_form.t2 = ui->lineEdit_10->text().toUInt();
    object_form.t3 = ui->lineEdit_12->text().toUInt();
    object_form.t4 = ui->lineEdit_14->text().toUInt();
    object_form.t5 = ui->lineEdit_17->text().toUInt();

    object_form.wd = ui->lineEdit_18->text().toUInt();
    object_form.bh = ui->lineEdit_5->text().toUInt();
    object_form.b1 = ui->lineEdit->text().toUInt();
    object_form.b2 = ui->lineEdit_3->text().toUInt();
    object_form.n1 = ui->lineEdit_2->text().toUInt();
    object_form.n2 = ui->lineEdit_4->text().toUInt();

    ui->comboBox->currentText() == YES_NO::YES ? object_form.l = true : object_form.l = false;

    object_form.at = ui->lineEdit_6->text().toDouble();
    object_form.al = ui->lineEdit_16->text().toDouble();
    object_form.gb1 = ui->lineEdit_19->text().toUInt();
    object_form.gb2 = ui->lineEdit_20->text().toUInt();
}

/* Doing items` color are black
 * Input: -
 * Output: - */
void Excavator_Form::Default() {
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
bool Excavator_Form::CheckAnswer(form_answer_excavator form) {
    bool flag(true);

    if (!form.s1) {
        ui->lineEdit_7->setStyleSheet(COLOR_EDIT::RED);
        ui->label->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.t1) {
        ui->lineEdit_8->setStyleSheet(COLOR_EDIT::RED);
        ui->label_3->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.s2) {
        ui->lineEdit_9->setStyleSheet(COLOR_EDIT::RED);
        ui->label_4->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.t2) {
        ui->lineEdit_10->setStyleSheet(COLOR_EDIT::RED);
        ui->label_5->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.s3) {
        ui->lineEdit_11->setStyleSheet(COLOR_EDIT::RED);
        ui->label_6->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.t3) {
        ui->lineEdit_12->setStyleSheet(COLOR_EDIT::RED);
        ui->label_7->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.s4) {
        ui->lineEdit_13->setStyleSheet(COLOR_EDIT::RED);
        ui->label_8->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.t4) {
        ui->lineEdit_14->setStyleSheet(COLOR_EDIT::RED);
        ui->label_9->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.s5) {
        ui->lineEdit_15->setStyleSheet(COLOR_EDIT::RED);
        ui->label_10->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.t5) {
        ui->lineEdit_17->setStyleSheet(COLOR_EDIT::RED);
        ui->label_11->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }

    if (!form.gb1) {
        ui->lineEdit_19->setStyleSheet(COLOR_EDIT::RED);
        ui->label_12->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.gb2) {
        ui->lineEdit_20->setStyleSheet(COLOR_EDIT::RED);
        ui->label_12->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }

    if (!form.b1) {
        ui->lineEdit->setStyleSheet(COLOR_EDIT::RED);
        ui->label_13->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.n1) {
        ui->lineEdit_2->setStyleSheet(COLOR_EDIT::RED);
        ui->label_14->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.b2) {
        ui->lineEdit_3->setStyleSheet(COLOR_EDIT::RED);
        ui->label_15->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.n2) {
        ui->lineEdit_4->setStyleSheet(COLOR_EDIT::RED);
        ui->label_16->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }

    if (!form.wd) {
        ui->lineEdit_18->setStyleSheet(COLOR_EDIT::RED);
        ui->label_2->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.at) {
        ui->lineEdit_6->setStyleSheet(COLOR_EDIT::RED);
        ui->label_20->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.al) {
        ui->lineEdit_16->setStyleSheet(COLOR_EDIT::RED);
        ui->label_17->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.l) {
        ui->comboBox->setStyleSheet(COLOR_EDIT::RED);
        ui->label_18->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.bh) {
        ui->lineEdit_5->setStyleSheet(COLOR_EDIT::RED);
        ui->label_19->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }

    return flag;
}

/* Set up image in the form
 * Input: -
 * Output: - */
void Excavator_Form::set_image() {
    object_excavator->GetDB()->SELECT("Icon", "Equipment", "Name = '" + name + "'");
    image(PATHS::RESOURCES + object_excavator->GetDB()->GetIcon());
    show_graphics();
}

/* Pressing "Done" button
 * Input: -
 * Output: - */
void Excavator_Form::on_pushButton_clicked()
{
    Default();
    form_excavator object_form;
    FillingFormExcavator(object_form);
    form_answer_excavator object_answer = object_excavator->CheckAnswer(object_form);

    frame message;
    QString grade = YES_NO::EMPTY;

    if (CheckAnswer(object_answer)) {
        message.result = MESSAGE::SUCCESS;
        grade = "??????????";
    } else {
        message.result = MESSAGE::FAIL;
        scene->clear();
        set_image();
        grade = "???? ??????????";
    }
    message.string = MESSAGE::PREPARATION;
    message.preparation = MESSAGE::EXCAVATOR;
    object_excavator->GetDB()->SetAttempt(object_user, name, grade);

    Message_Form *object = new Message_Form(message);
    object->show();
}

void Excavator_Form::on_lineEdit_7_cursorPositionChanged(int arg1, int arg2) {
    if ((arg1 == -1 || arg1 == 1) && arg2 == 0) {
        SM_swilev_cursor(green_pen());
        show_graphics();
    }
}

void Excavator_Form::on_lineEdit_7_editingFinished() {
    remove_last_item();
    SM_swilev(red_pen());
    show_graphics();
}

void Excavator_Form::on_lineEdit_9_cursorPositionChanged(int arg1, int arg2) {
    if ((arg1 == -1 || arg1 == 1) && arg2 == 0) {
        SM_undercarriage_cursor(green_pen());
        show_graphics();
    }
}

void Excavator_Form::on_lineEdit_9_editingFinished() {
    remove_last_item();
    remove_last_item();
    SM_undercarriage(red_pen());
    show_graphics();
}

void Excavator_Form::on_lineEdit_11_cursorPositionChanged(int arg1, int arg2) {
    if ((arg1 == -1 || arg1 == 1) && arg2 == 0) {
        SM_root_cursor(green_pen());
        show_graphics();
    }
}

void Excavator_Form::on_lineEdit_11_editingFinished() {
    remove_last_item();
    SM_root(red_pen());
    show_graphics();
}

void Excavator_Form::on_lineEdit_13_cursorPositionChanged(int arg1, int arg2)
{
    if ((arg1 == -1 || arg1 == 1) && arg2 == 0) {
        SM_handle_cursor(green_pen());
        show_graphics();
    }
}

void Excavator_Form::on_lineEdit_13_editingFinished()
{
    remove_last_item();
    SM_handle(red_pen());
    show_graphics();
}

void Excavator_Form::on_lineEdit_15_cursorPositionChanged(int arg1, int arg2)
{
    if ((arg1 == -1 || arg1 == 1) && arg2 == 0) {
        SM_trolley_cursor(green_pen());
        show_graphics();
    }
}

void Excavator_Form::on_lineEdit_15_editingFinished()
{
    remove_last_item();
    SM_trolley(red_pen());
    show_graphics();
}

void Excavator_Form::on_comboBox_highlighted(int index)
{
    lining_cursor(green_pen());
    count++;
    show_graphics();
}

void Excavator_Form::on_comboBox_activated(int index)
{
    for (unsigned int i = 0; i < count; i++) {
        remove_last_item();
    }
    count = 0;
    lining(red_pen());
    show_graphics();
}

void Excavator_Form::on_lineEdit_5_cursorPositionChanged(int arg1, int arg2)
{
    if ((arg1 == -1 || arg1 == 1) && arg2 == 0) {
        arrow_cursor(green_pen());
        show_graphics();
    }
}

void Excavator_Form::on_lineEdit_5_editingFinished()
{
    remove_last_item();
    remove_last_item();
    remove_last_item();
    show_graphics();
}

void Excavator_Form::on_lineEdit_6_cursorPositionChanged(int arg1, int arg2)
{
    if ((arg1 == -1 || arg1 == 1) && arg2 == 0) {
        axis_turnover_cursor(green_pen());
        show_graphics();
    }
}

void Excavator_Form::on_lineEdit_6_editingFinished()
{
    remove_last_item();
    show_graphics();
}

void Excavator_Form::on_lineEdit_16_cursorPositionChanged(int arg1, int arg2)
{
    if ((arg1 == -1 || arg1 == 1) && arg2 == 0) {
        axis_longitudinal_cursor(green_pen());
        show_graphics();
    }
}

void Excavator_Form::on_lineEdit_16_editingFinished()
{
    remove_last_item();
    show_graphics();
}

void Excavator_Form::on_lineEdit_editingFinished()
{
    bar_thrust(red_pen());
    show_graphics();
}

void Excavator_Form::on_lineEdit_3_editingFinished()
{
    bar_side(red_pen());
    show_graphics();
}

