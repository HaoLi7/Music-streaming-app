#ifndef SONGIFY_H
#define SONGIFY_H

#include <iostream>
#include <string>
#include "Album.h"
#include "MediaFactory.h"

using namespace std;

class Songify {
		
	public:
		//constructors
		Songify();

		//destructor
		~Songify();

		//add and remove Songs and Albums
		bool addAlbum(const string& artist, const string& albumTitle);
		bool addSong(const string& artist, const string& songTile, const string& albumTitle);
		// bool addSong(const Song& song);
		bool removeSong(const string& artist, const string& songTile, const string& albumTitle);
		bool removeAlbum(const string& artist, const string& albumTitle);

		bool getAlbum(int, Album**) const;
		bool getPlaylist(const string& artist, const string& category, Array<Song*>&) const;
		const Array<Album*>& getAlbums() const { return *albums; }
	
	private:
		Array<Album*>* albums;
		MediaFactory* mf;
	
};
#endif