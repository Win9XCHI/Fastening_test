#ifndef LINING_H
#define LINING_H
#include "dimensions.h"

class Lining {
    bool YesNo;
    Dimensions object;
    unsigned int nails;

public:
    Lining();
    Lining(bool yn, unsigned int n = 0);
    Lining(bool yn, Dimensions o, unsigned int n = 0);

    bool GetYesNo();
    Dimensions GetDimensions();
    unsigned int GetNails();
};

#endif // LINING_H
