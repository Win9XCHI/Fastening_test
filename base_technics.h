#ifndef BASE_TECHNICS_H
#define BASE_TECHNICS_H
#include <QGraphicsScene>

class base_technics
{
public:
    base_technics();

    QGraphicsScene *scene;
    void image(QString);
    QPen green_pen(int width = 5);
    void triangle(QPen, int, int);
};

#endif // BASE_TECHNICS_H
