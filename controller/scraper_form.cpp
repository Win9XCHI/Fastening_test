#include "scraper_form.h"
#include "ui_scraper_form.h"

Scraper_Form::Scraper_Form(ScraperDB db, User u, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Scraper_Form)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    count = 0;
    name = EQUIPMENT_NAME::SCRAPER;
    ui->comboBox->addItem(YES_NO::EMPTY);
    ui->comboBox->addItem(YES_NO::NO);
    ui->comboBox->addItem(YES_NO::YES);
    object_scraper = new Scraper(db);
    Scraper_Form::set_image();

    object_user = u;
    object_scraper->GetDB()->SetUser(object_user);

    QList<QLineEdit *> allEdits = this->findChildren<QLineEdit *>();
    Validation::LineEdit::SetDoubleValidator(allEdits);
}

Scraper_Form::~Scraper_Form()
{
    object_scraper->GetDB()->close();
    delete ui;
    delete object_scraper;
    delete scene;
}

/* Showing graphics
 * Input: -
 * Output: - */
void Scraper_Form::show_graphics() {
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}

/* Functions with graphics
 * Input: pen
 * Output: - */
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

/* Pressing "To main window" button
 * Input: -
 * Output: - */
void Scraper_Form::on_pushButton_clicked()
{
    emit firstWindow();
    this->~Scraper_Form();
}

/* Pressing "Done" button
 * Input: -
 * Output: - */
void Scraper_Form::on_pushButton_2_clicked()
{
    Default();
    form_scraper object_form;
    FillingFormMotorScraper(object_form);
    form_answer_scraper object_answer = object_scraper->CheckAnswer(object_form);

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
    message.preparation = MESSAGE::SCRAPER;
    object_scraper->GetDB()->SetAttempt(object_user, name, grade);

    Message_Form *object = new Message_Form(message);
    object->show();
}

/* Set up image in the form
 * Input: -
 * Output: - */
void Scraper_Form::set_image() {
    object_scraper->GetDB()->SELECT("Icon", "Equipment", "Name = '" + name + "'");
    image(PATHS::RESOURCES + object_scraper->GetDB()->GetIcon());
    show_graphics();
}

/* Filling а structure from form`s items
 * Input: structure
 * Output: - */
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

    ui->comboBox->currentText() == YES_NO::YES ? object_form.li = true : object_form.li = false;
}

/* Doing items` color are black
 * Input: -
 * Output: - */
void Scraper_Form::Default() {
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
bool Scraper_Form::CheckAnswer(form_answer_scraper form) {
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
    if (!form.b1) {
        ui->lineEdit_4->setStyleSheet(COLOR_EDIT::RED);
        ui->label_4->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.n1) {
        ui->lineEdit_5->setStyleSheet(COLOR_EDIT::RED);
        ui->label_5->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.b2) {
        ui->lineEdit_10->setStyleSheet(COLOR_EDIT::RED);
        ui->label_12->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.n2) {
        ui->lineEdit_11->setStyleSheet(COLOR_EDIT::RED);
        ui->label_14->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.t2) {
        ui->lineEdit_12->setStyleSheet(COLOR_EDIT::RED);
        ui->label_16->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.w2) {
        ui->lineEdit_13->setStyleSheet(COLOR_EDIT::RED);
        ui->label_15->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.l2) {
        ui->lineEdit_14->setStyleSheet(COLOR_EDIT::RED);
        ui->label_17->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.li) {
        ui->label_6->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.nli) {
        ui->lineEdit_9->setStyleSheet(COLOR_EDIT::RED);
        ui->label_11->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.t1) {
        ui->lineEdit_6->setStyleSheet(COLOR_EDIT::RED);
        ui->label_8->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.w1) {
        ui->lineEdit_7->setStyleSheet(COLOR_EDIT::RED);
        ui->label_9->setStyleSheet(COLOR_EDIT::RED);
        flag = false;
    }
    if (!form.l1) {
        ui->lineEdit_8->setStyleSheet(COLOR_EDIT::RED);
        ui->label_10->setStyleSheet(COLOR_EDIT::RED);
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
