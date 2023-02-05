#include "C_Criteria.h"

C_Criteria::C_Criteria(const string& category) {
    this->category = category;
}

bool C_Criteria::matches(const Song& song) const {
    return song.getCategory() == category;
}

void C_Criteria::print(ostream& ost) const {
    ost<<"Criteria C: you must match the category with this category: "<<category<<endl;
}