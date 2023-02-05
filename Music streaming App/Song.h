#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <string>

using namespace std;

class Song {
	friend ostream& operator<<(ostream& ost, const Song& song);
	public:
		//constructors
		Song(const string& artist, const string&  title, const string& category, const string& content);

		//getters
		const string& getTitle() const {return title;}
		const string& getArtist() const {return artist;}
		const string& getCategory() const {return category;}

		bool matches(const string& artist, const string& title) const;

		void print(ostream& ost) const;
		void play(ostream& ost) const;
	
	private:
		string title;
		string artist;
		string content;
		string category;
};
#endif