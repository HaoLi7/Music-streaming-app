#ifndef MEDIAFACTORY_H
#define MEDIAFACTORY_H

#include <iostream>
#include <string>
#include "Album.h"
#include "AorC_Criteria.h"

using namespace std;

class MediaFactory {
		
	public:
		// create a Song 
		bool createSong(const string& a, const string& t, Song** song);

		// create an Album
		bool createAlbum(const string& title, const string& owner, Album** alb);

		// create Criteria
		bool createCriteria(const string& artist, const string& category, Criteria** crit);
	
};
#endif