#ifndef BAR_H
#define BAR_H
#include "dimensions.h"

class Bar {
    unsigned int count;
    unsigned int nails;
    Dimensions object;

public:
    Bar();
    Bar(unsigned int c, unsigned int n = 0);
    Bar(unsigned int c, Dimensions o, unsigned int n = 0);

    unsigned int GetCount();
    unsigned int GetNails();
    Dimensions GetDimensions();
};

#endif // BAR_H
