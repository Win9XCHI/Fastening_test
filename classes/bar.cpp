#include "bar.h"

Bar::Bar() : count(0), nails(0) {

}

Bar::Bar(unsigned int c, unsigned int n) : count(c), nails(n) {

}

Bar::Bar(unsigned int c, Dimensions o, unsigned int n) : count(c), nails(n), object(o) {

}

unsigned int Bar::GetCount() {
    return count;
}

unsigned int Bar::GetNails() {
    return nails;
}

Dimensions Bar::GetDimensions() {
    return object;
}
