#include "Album.h"

Album::Album(const string& artist, const string& albumTitle) {
    songs = new Array<Song*>();
    this->artist = artist;
    this->title = albumTitle;
}

Album::~Album() { delete songs; }

int Album::getSize() const { return songs->getSize(); }

bool Album::matches(const string& artist, const string& albumTitle) const {
    if (this->artist.compare(artist) == 0 && this->title.compare(albumTitle) == 0) return true;
    else return false;
}

bool Album::lessThan(const Album& alb) const {
    if (this->artist.compare(alb.artist) < 0) {
        return true;
    } else if (this->artist.compare(alb.artist) == 0) {
        if (this->title.compare(alb.title) < 0) {
            return true;
        }else {
            return false;
        }
    }else {
        return false;
    }
}

bool Album::addSong(Song* newSong) { 
    if (songs->isFull()) return false;
    else {
        songs->add(newSong);
        return true;
    }
}

bool Album::getSong(const string& songTitle, Song** matched) const {
    for (int i = 0; i < songs->getSize(); ++i) {
        if ((*songs)[i]->matches(artist, title)) {
            *matched = (*songs)[i];
            return true;
        }
    }
    return false;
}

bool Album::getSong(int index, Song** matched) const {
    if (index < 0 || index >= songs->getSize()) {
        *matched = NULL;
        return false;
    }else {
        *matched = (*songs)[index];
        return true;
    }
}

Song* Album::operator[](int index) {
    Song* matched;
    getSong(index, &matched);
    return matched;
}

bool Album::removeSong(const string& songTitle, Song** removed) {
    bool flag = getSong(songTitle,removed);
    if (flag) {
        *songs -= *removed;
    }
    return flag;
}

bool Album::removeSong(int index, Song** removed) {
    if (index < 0 || index >= songs->getSize()) {
        *removed = NULL;
        return false;
    }else {
        *removed = (*songs)[index];
        *songs -= *removed;
        return true;
    }
}

void Album::printShort(ostream& ost) const {
    ost << "Album artist: " << artist << endl;
    ost << "Album title: " << title << endl;
}

void Album::print(ostream& ost) const {
    ost << "Album artist: " << artist << endl;
    ost << "Album title: " << title << endl;
    for (int i = 0; i < songs->getSize(); ++i) {
        (*songs)[i]->print(ost);
    }
}

ostream& operator<<(ostream& ost, Album& alb) {
	alb.print(ost);
	return ost;
}