#ifndef EQUIPMENT_H
#define EQUIPMENT_H
#include "stretching.h"
#include "bar.h"
#include "lining.h"

class Equipment {
    Stretching *masStretching;
    Bar *masBar;

public:
    Equipment();
};

#endif // EQUIPMENT_H
