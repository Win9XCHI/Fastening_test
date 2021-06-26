#ifndef LINING_H
#define LINING_H
#include "dimensions.h"

class Lining {
    bool YesNo;
    Dimensions object;

public:
    Lining();
    Lining(bool);
    Lining(bool, Dimensions);

    bool GetYesNo();
};

#endif // LINING_H
