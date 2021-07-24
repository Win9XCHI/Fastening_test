#ifndef STRUCTURE_H
#define STRUCTURE_H
#include <QString>

/* Structure for message form */
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

struct form_answer_excavator {
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

    form_answer_excavator() {
        s1 = s2 = s3 = s4 = s5 = t1 = t2 = t3 = t4 = t5 = wd = bh = b1 = b2 = n1 = n2 = l = at = al = gb1 = gb2 = true;
    }
};

struct form_motorgrader {
    unsigned int s;
    unsigned int t;
    unsigned int wd;
    unsigned int b;
    unsigned int n;
    bool li1;
    bool li2;
    unsigned int nli1;
    unsigned int nli2;
    unsigned int t1;
    unsigned int t2;
    unsigned int w1;
    unsigned int w2;
    unsigned int l1;
    unsigned int l2;
};

struct form_answer_motorgrader {
    bool s;
    bool t;
    bool wd;
    bool b;
    bool n;
    bool li1;
    bool li2;
    bool nli1;
    bool nli2;
    bool t1;
    bool t2;
    bool w1;
    bool w2;
    bool l1;
    bool l2;

    form_answer_motorgrader() {
        s = t = wd = b = n = li1 = li2 = nli1 = nli2 = t1 = t2 = w1 = w2 = l1 = l2 = true;
    }
};

struct form_scraper {
    unsigned int s;
    unsigned int t;
    unsigned int wd;
    unsigned int b1;
    unsigned int n1;
    unsigned int b2;
    unsigned int n2;
    unsigned int t2;
    unsigned int w2;
    unsigned int l2;
    bool li;
    unsigned int nli;
    unsigned int t1;
    unsigned int w1;
    unsigned int l1;
};

struct form_answer_scraper {
    bool s;
    bool t;
    bool wd;
    bool b1;
    bool n1;
    bool b2;
    bool n2;
    bool t2;
    bool w2;
    bool l2;
    bool li;
    bool nli;
    bool t1;
    bool w1;
    bool l1;

    form_answer_scraper() {
        s = t = wd = b1 = n1 = b2 = n2 = nli = li = t1 = t2 = w1 = w2 = l1 = l2 = true;
    }
};

struct form_bulldozer {
    QString weight;
    unsigned int s;
    unsigned int wd;
    unsigned int t;
    unsigned int b;
    QString nail_boards;
    unsigned int st1;
    unsigned int n1;
    unsigned int nl1;
    QString side_bar;
    unsigned int st2;
    QString width;
    unsigned int st;
    unsigned int sw;
    unsigned int sl;
    unsigned int sn;
    unsigned int gap1;
    unsigned int gap2;
    bool l;
    unsigned int ln;
    unsigned int lt;
    unsigned int lw;
    unsigned int ll;

    form_bulldozer() {
        s = wd = t = b = st1 = n1 = nl1 = st2 = st = sw = sl = sn = gap1 = gap2 = l = ln = lt = lw = ll = 0;
        weight = nail_boards = nail_boards = width = "";
    }
};

struct form_answer_bulldozer {
    bool weight;
    bool nail_boards;
    bool side_bar;
    bool s;
    bool wd;
    bool t;
    bool b;
    bool st1;
    bool n1;
    bool nl1;
    bool st2;
    bool st;
    bool sw;
    bool sl;
    bool sn;
    bool gap1;
    bool gap2;
    bool l;
    bool ln;
    bool lt;
    bool lw;
    bool ll;

    form_answer_bulldozer() {
        weight = nail_boards = side_bar = s = wd = t = b = st1 = n1 = nl1 = st2 = st = sw = sl = sn = gap1 = gap2 = l = ln = lt = lw = ll = true;
    }
};

struct form_KRAZ_pl {
    unsigned int b;
    unsigned int t1;
    unsigned int w1;
    unsigned int l1;
    unsigned int t2;
    unsigned int w2;
    unsigned int l2;
    unsigned int n;
    unsigned int s;
    unsigned int t;
    unsigned int wd;
    double kg;
    double pog;
};

struct form_answer_KRAZ_pl {
    bool b;
    bool t1;
    bool w1;
    bool l1;
    bool t2;
    bool w2;
    bool l2;
    bool n;
    bool s;
    bool t;
    bool wd;
    bool kg;
    bool pog;

    form_answer_KRAZ_pl() {
        b = t1 = w1 = l1 = t2 = w2 = l2 = n = s = t = wd = kg = pog = true;
    }
};

struct form_KRAZ {
    unsigned int b1;
    unsigned int t1;
    unsigned int w1;
    unsigned int l1;
    unsigned int n1;
    unsigned int s;
    unsigned int t;
    unsigned int wd;
    unsigned int b2;
    unsigned int t2;
    unsigned int w2;
    unsigned int l2;
    unsigned int n2;
    double kg;
    double pog;
    unsigned int distance1;
    unsigned int distance2;
};

struct form_answer_KRAZ {
    bool b1;
    bool t1;
    bool w1;
    bool l1;
    bool n1;
    bool s;
    bool t;
    bool wd;
    bool b2;
    bool t2;
    bool w2;
    bool l2;
    bool n2;
    bool kg;
    bool pog;
    bool distance1;
    bool distance2;

    form_answer_KRAZ() {
        b1 = t1 = w1 = l1 = s = t = wd = b2 = t2 = w2 = l2 =  kg = pog = n1 = n2 = distance1 = distance2 = true;
    }
};

struct form_VGM {
    QString weight;
    unsigned int s;
    unsigned int wd;
    unsigned int t;
    unsigned int b;
    QString nail_boards;
    unsigned int st1;
    unsigned int n1;
    unsigned int nl1;
    QString side_bar;
    unsigned int st2;
    QString width;
    unsigned int st;
    unsigned int sw;
    unsigned int sl;
    unsigned int sn;
    unsigned int gap1;
    unsigned int gap2;

    form_VGM() {
        s = wd = t = b = st1 = n1 = nl1 = st2 = st = sw = sl = sn = gap1 = gap2 = 0;
        weight = nail_boards = nail_boards = width = "";
    }
};

struct form_answer_VGM {
    bool weight;
    bool nail_boards;
    bool side_bar;
    bool s;
    bool wd;
    bool t;
    bool b;
    bool st1;
    bool n1;
    bool nl1;
    bool st2;
    bool st;
    bool sw;
    bool sl;
    bool sn;
    bool gap1;
    bool gap2;

    form_answer_VGM() {
        weight = nail_boards = side_bar = s = wd = t = b = st1 = n1 = nl1 = st2 = st = sw = sl = sn = gap1 = gap2 = true;
    }
};

#endif // STRUCTURE_H
