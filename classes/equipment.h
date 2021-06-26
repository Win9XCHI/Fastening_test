#ifndef EQUIPMENT_H
#define EQUIPMENT_H
#include <map>
#include <QString>
#include "stretching.h"
#include "bar.h"
#include "lining.h"
#include "fromto.h"

class Equipment {

    std::map<QString, Stretching> mas_stretching;
    std::map<QString, Bar> mas_bar;
    std::map<QString, FromTo> mas_fromto;

public:
    Equipment();
};

#endif // EQUIPMENT_H
