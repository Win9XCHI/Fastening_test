#ifndef BAR_H
#define BAR_H
#include "dimensions.h"

class Bar {
    unsigned int count;
    unsigned int nails;
    unsigned int length_nail;
    unsigned int staple;
    Dimensions object;

public:
    Bar();
    Bar(unsigned int c, unsigned int n = 0, unsigned int l = 0, unsigned int s = 0);
    Bar(unsigned int c, Dimensions o, unsigned int n = 0, unsigned int l = 0, unsigned int s = 0);

    unsigned int GetCount();
    unsigned int GetNails();
    Dimensions GetDimensions();
    unsigned int GetLengthNail();
    unsigned int GetStaple();

    void SetCount(unsigned int);
    void SetNails(unsigned int);
    void SetDimensions(Dimensions);
    void SetLengthNail(unsigned int);
    void SetStaple(unsigned int);
};

#endif // BAR_H
