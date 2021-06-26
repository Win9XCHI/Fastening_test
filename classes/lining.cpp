#include "lining.h"

Lining::Lining() : YesNo(0) {

}

Lining::Lining(bool a) : YesNo(a) {

}

Lining::Lining(bool a, Dimensions b) : YesNo(a), object(b) {

}

bool Lining::GetYesNo() {
    return YesNo;
}
