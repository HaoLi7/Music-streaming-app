#ifndef ALBUM_H
#define ALBUM_H

#include <iostream>
#include <string>
#include "Song.h"
#include "Array.h"

using namespace std;

class Album {

	friend ostream& operator<<(ostream& ost, Album& alb);
		
	public:
		//constructors
		Album(const string& artist, const string& albumTitle);

		//destructor
		~Album();

		//getters
		const string& getTitle() const {return title;}
		const string& getArtist() const {return artist;}
		int getSize() const;

		//comparison
		bool matches(const string& artist, const string& albumTitle) const;
		bool lessThan(const Album&) const;

		//add and remove
		bool addSong(Song*);
		bool getSong(const string& songTitle, Song**) const;
		bool getSong(int, Song**) const;
		Song* operator[](int);
		bool removeSong(const string& songTitle, Song**);
		bool removeSong(int, Song**);

		void printShort(ostream&) const;
		void print(ostream&) const;
	
	private:
		string title;
		string artist;
		Array<Song*>* songs;
	
};
#endif