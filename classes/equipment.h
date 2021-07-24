#ifndef EQUIPMENT_H
#define EQUIPMENT_H
#include <map>
#include <QString>
#include "stretching.h"
#include "bar.h"
#include "lining.h"
#include "fromto.h"
#include "../constants.h"

class Equipment {

protected:
    QString name;
    std::map<QString, Stretching> mas_stretching;
    std::map<QString, Bar> mas_bar;
    std::map<QString, FromTo> mas_fromto;
    std::map<QString, Lining> mas_lining;

public:
    Equipment();
};

#endif // EQUIPMENT_H
