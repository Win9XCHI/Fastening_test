#include "base_technics.h"

base_technics::base_technics()
{

}

void base_technics::image(QString src) {
    scene->addPixmap(QPixmap(src));
}


