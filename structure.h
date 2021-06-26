#ifndef STRUCTURE_H
#define STRUCTURE_H
#include <QString>

struct frame {
    QString result;
    QString string;
    QString preparation;
};

struct form_excavator {
    unsigned int s1;
    unsigned int s2;
    unsigned int s3;
    unsigned int s4;
    unsigned int s5;
    unsigned int t1;
    unsigned int t2;
    unsigned int t3;
    unsigned int t4;
    unsigned int t5;
    unsigned int wd;
    unsigned int b1;
    unsigned int b2;
    unsigned int n1;
    unsigned int n2;
    bool l;
    double at;
    double al;
    unsigned int gb1;
    unsigned int gb2;
};

#endif // STRUCTURE_H
