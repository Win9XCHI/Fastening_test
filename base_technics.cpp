#include "base_technics.h"

base_technics::base_technics()
{

}

void base_technics::image(QString src) {
    scene->addPixmap(QPixmap(src));
}

QPen base_technics::green_pen() {
    QPen pen(Qt::green);
    pen.setWidth(5);
    return pen;
}


