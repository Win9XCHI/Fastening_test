#include "base_technics.h"

base_technics::base_technics() {

}

void base_technics::image(QString src) {
    scene->addPixmap(QPixmap(src));
}

QPen base_technics::green_pen(int width) {
    QPen pen(Qt::green);
    pen.setWidth(width);
    return pen;
}

QPen base_technics::red_pen(int width) {
    QPen pen(Qt::red);
    pen.setWidth(width);
    return pen;
}

void base_technics::triangle(QPen pen, int x, int y) {
    QPolygonF polygon;
    polygon << QPointF(10 + x, 30 + y) << QPointF(30 + x, 10 + y) << QPointF(0 + x, 0 + y);
    scene->addPolygon(polygon, pen);
}

void base_technics::remove_last_item() {
    QList<QGraphicsItem *> ob = scene->items();
    scene->removeItem(ob[0]);
}



