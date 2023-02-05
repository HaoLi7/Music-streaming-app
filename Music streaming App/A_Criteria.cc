#include "A_Criteria.h"

A_Criteria::A_Criteria(const string& artist) {
    this->artist = artist;
}

bool A_Criteria::matches(const Song& song) const {
    return song.getArtist() == artist;
}

void A_Criteria::print(ostream& ost) const {
    ost<<"Criteria A: you must match the artist name with this artist: "<<artist<<endl;
}