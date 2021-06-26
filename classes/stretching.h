#ifndef STRETCHING_H
#define STRETCHING_H

class Stretching {
    unsigned int count;
    unsigned int thread;

public:
    Stretching();
    Stretching(unsigned int, unsigned int);

    unsigned int GetCount();
    unsigned int GetThread();
};

#endif // STRETCHING_H
