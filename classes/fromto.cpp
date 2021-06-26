#include "fromto.h"

FromTo::FromTo() : from(0), to(0) {

}

FromTo::FromTo(double a, double b) : from(a), to(b) {

}

FromTo::FromTo(const FromTo &other) : from(other.from), to(other.to) {
}

double FromTo::GetFrom() {
    return from;
}

double FromTo::GetTo() {
    return to;
}
