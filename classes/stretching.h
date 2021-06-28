#ifndef STRETCHING_H
#define STRETCHING_H

class Stretching {
    unsigned int count;
    unsigned int thread;

public:
    Stretching();
    Stretching(unsigned int c);
    Stretching(unsigned int c, unsigned int t);

    unsigned int GetCount();
    unsigned int GetThread();

    void SetCount(unsigned int);
    void SetThread(unsigned int);
};

#endif // STRETCHING_H
