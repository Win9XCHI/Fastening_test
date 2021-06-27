#ifndef FROMTO_H
#define FROMTO_H


class FromTo {
    double from;
    double to;

public:
    FromTo();
    FromTo(double f, double t);
    FromTo(const FromTo &);

    double GetFrom();
    double GetTo();
};

#endif // FROMTO_H
