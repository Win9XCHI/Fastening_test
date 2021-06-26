#ifndef BAR_H
#define BAR_H
#include "dimensions.h"

class Bar {
    unsigned int count;
    unsigned int nails;
    Dimensions object;

public:
    Bar();
    Bar(unsigned int, unsigned int);
    Bar(unsigned int, unsigned int, Dimensions);

    unsigned int GetCount();
    unsigned int GetNails();
};

#endif // BAR_H
