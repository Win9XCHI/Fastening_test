#ifndef EQUIPMENT_H
#define EQUIPMENT_H
#include <map>
#include "stretching.h"
#include "bar.h"
#include "lining.h"
#include "fromto.h"

class Equipment {
    std::map<std::string, Stretching> mas_stretching;
    std::map<std::string, Bar> mas_bar;
    std::map<std::string, FromTo> mas_fromto;

public:
    Equipment();
};

#endif // EQUIPMENT_H
