#include "Song.h"

ostream& operator<<(ostream& ost, const Song& song) {
    song.print(ost);
    return ost;
}

Song::Song(const string& artist, const string&  title, const string& category, const string& content) {
    this->artist = artist;
    this->title = title;
    this->category = category;
    this->content = content;
}

bool Song::matches(const string& artist,const string& title) const{
    if (this->artist.compare(artist) == 0 && this->title.compare(title) == 0) return true;
    else return false;
}

void Song::print(ostream& ost) const {
    ost << "Artist: " << artist << endl;
    ost << "Title: " << title << endl;
    ost << "Category: " << category << endl;
}

void Song::play(ostream& ost) const{
    print(ost);
    ost << "Content: " << content << endl;
}