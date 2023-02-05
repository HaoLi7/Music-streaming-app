#include "AorC_Criteria.h"

AorC_Criteria::AorC_Criteria(const string& artist, const string& category):A_Criteria(artist), C_Criteria(category) {}

bool AorC_Criteria::matches(const Song& song) const {
    return (this->A_Criteria::matches(song) || this->C_Criteria::matches(song));
}

void AorC_Criteria::print(ostream& ost) const {
    A_Criteria::print(ost);
    C_Criteria::print(ost);
}