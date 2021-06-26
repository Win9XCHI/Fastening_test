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
    unsigned int bh;
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

struct form_answer {
    bool s1;
    bool s2;
    bool s3;
    bool s4;
    bool s5;
    bool t1;
    bool t2;
    bool t3;
    bool t4;
    bool t5;
    bool wd;
    bool bh;
    bool b1;
    bool b2;
    bool n1;
    bool n2;
    bool l;
    bool at;
    bool al;
    bool gb1;
    bool gb2;

    form_answer() {
        s1 = s2 = s3 = s4 = s5 = t1 = t2 = t3 = t4 = t5 = wd = bh = b1 = b2 = n1 = n2 = l = at = al = gb1 = gb2 = true;
    }
};

#endif // STRUCTURE_H
