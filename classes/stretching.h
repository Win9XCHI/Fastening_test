#ifndef STRETCHING_H
#define STRETCHING_H

class Stretching {
    unsigned int count;
    unsigned int thread;
    unsigned int wire_diameter;

public:
    Stretching();
    Stretching(unsigned int c);
    Stretching(unsigned int c, unsigned int t = 0, unsigned int wd = 0);

    unsigned int GetCount();
    unsigned int GetThread();
    unsigned int GetWireDiameter();

    void SetCount(unsigned int);
    void SetThread(unsigned int);
    void SetWireDiameter(unsigned int);
};

#endif // STRETCHING_H
