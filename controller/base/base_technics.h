#ifndef BASE_TECHNICS_H
#define BASE_TECHNICS_H
#include <QGraphicsScene>
#include "../message_form.h"

class base_technics {
protected:
    base_technics();
    QGraphicsScene *scene;
    void image(QString);
    QPen green_pen(int width = 5);
    QPen red_pen(int width = 5);
    void triangle(QPen, int, int);
    void remove_last_item();
    virtual void set_image() = 0;
};

#endif // BASE_TECHNICS_H
