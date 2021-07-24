#include "lining.h"

Lining::Lining() : YesNo(0) {

}

Lining::Lining(bool yn, unsigned int n) : YesNo(yn), nails(n) {

}

Lining::Lining(bool yn, Dimensions o, unsigned int n) : YesNo(yn), object(o), nails(n) {

}

bool Lining::GetYesNo() {
    return YesNo;
}

Dimensions Lining::GetDimensions() {
    return object;
}

unsigned int Lining::GetNails() {
    return nails;
}
