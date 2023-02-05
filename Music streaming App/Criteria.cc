#include "Criteria.h"

ostream& operator<<(ostream& ost, const Criteria& c) {
    c.print(ost);
    return ost;
}