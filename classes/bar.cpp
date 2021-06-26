#include "bar.h"

Bar::Bar() : count(0), nails(0) {

}

Bar::Bar(unsigned int a, unsigned int b) : count(a), nails(b) {

}

Bar::Bar(unsigned int a, unsigned int b, Dimensions c) : count(a), nails(b), object(c) {

}

unsigned int Bar::GetCount() {
    return count;
}

unsigned int Bar::GetNails() {
    return nails;
}
