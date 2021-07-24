#ifndef MESSAGE_FORM_H
#define MESSAGE_FORM_H
#include "../structure.h"

#include <QWidget>

namespace Ui {
class Message_Form;
}

class Message_Form : public QWidget
{
    Q_OBJECT

public:
    explicit Message_Form(frame, QWidget *parent = nullptr);
    ~Message_Form();

private:
    Ui::Message_Form *ui;
};

#endif // MESSAGE_FORM_H
