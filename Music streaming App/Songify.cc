#include "Songify.h"

Songify::Songify() {
    albums = new Array<Album*>();
    mf = new MediaFactory();
}

Songify::~Songify() {
    for (int i = 0; i < albums->getSize(); ++i) {
        Album* currAlbum = (*albums)[i];
        for (int j = 0; j < currAlbum->getSize(); ++j) {
            Song* currSong = (*currAlbum)[j];
            delete currSong;
        }
        delete currAlbum;
    }
    delete albums;
    delete mf;
}

bool Songify::addAlbum(const string& artist, const string& albumTitle) {
    if (albums->isFull()) return false;
    Album* newAlbum;
    mf->createAlbum(albumTitle, artist, &newAlbum);
    albums->add(newAlbum);
    return true;
}

bool Songify::addSong(const string& artist, const string& songTile, const string& albumTitle) {
    Song* newSong = NULL;
    Album* alb = NULL;
    bool songFlag = mf->createSong(artist, songTile, &newSong);
    if (!songFlag) {
        return false;
    }
    for (int i = 0; i < albums->getSize(); ++i) {
        if ((*albums)[i]->matches(artist, albumTitle)) {
            alb = (*albums)[i];
            break;
        }
    }
    alb->addSong(newSong);
    return true;
}

bool Songify::removeSong(const string& artist, const string& songTile, const string& albumTitle) {
    Song* removed = NULL;
    Album* alb = NULL;
    bool albFlag = false;
    for (int i = 0; i < albums->getSize(); ++i) {
        if ((*albums)[i]->matches(artist, albumTitle)) {
            alb = (*albums)[i];
            albFlag = true;
            break;
        }
    }
    if (!albFlag) {
        return false;
    }
    bool removeFlag = alb->removeSong(songTile, &removed);
    delete removed;
    return removeFlag;

}

bool Songify::removeAlbum(const string& artist, const string& albumTitle) {
    Album* removed = NULL;
    for (int i = 0; i < albums->getSize(); ++i) {
        if ((*albums)[i]->matches(artist, albumTitle)) {
            removed = (*albums)[i];
            *albums -= removed;
            Song* rmSong = NULL;
            for (int j = 0; j < removed->getSize(); ++j) {
                removed->removeSong(j,&rmSong);
                delete rmSong;
            }
            delete removed;
            return true;
        }
    }
    return false;
}

bool Songify::getAlbum(int index, Album** matched) const {
    *matched = NULL;
    *matched = (*albums)[index];
    return *matched != NULL;
}

bool Songify::getPlaylist(const string& artist, const string& category, Array<Song*>& playlist) const {
    Criteria* crit;
    bool flag = mf->createCriteria(artist, category, &crit);
    if (!flag) {
        return false;
    }
    for (int i = 0; i < albums->getSize(); ++i) {
        Album* currAlbum = (*albums)[i];
        for (int j = 0; j < currAlbum->getSize(); ++j) {
            Song* currSong = (*currAlbum)[j];
            if (crit->matches(*currSong)) {
                playlist.add(currSong);
            }
        }
    }
    delete crit;
    return true;
}