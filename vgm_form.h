#ifndef VGM_FORM_H
#define VGM_FORM_H

#include <QWidget>

namespace Ui {
class VGM_Form;
}

class VGM_Form : public QWidget
{
    Q_OBJECT

public:
    explicit VGM_Form(QWidget *parent = nullptr);
    ~VGM_Form();

private:
    Ui::VGM_Form *ui;
};

#endif // VGM_FORM_H
