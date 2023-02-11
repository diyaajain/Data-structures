/* This is the header file for the Song class. */
#ifndef CLASSSONG_HPP
#define CLASSSONG_HPP
#include <iostream>
#include "classPlaylist.hpp"

using namespace std;

class Song {
  private: /* define private data members of class song */
    string title;
    string artist;
    string album;
    int min;
    int sec;
  
  public: /* default constructor for the song class */
    Song(){};
    Song(string& name, string& singer, string& albumName, int m, int s) {
      title = name;
      artist = singer;
      album = albumName;
      min = m;
      sec = s;
    };
    /* member functions */
    void setTitle(string& newTitle) { title = newTitle; }
    void setArtist(string& newArtist) { artist = newArtist; }
    void setAlbum(string& newAlbum) { album = newAlbum; }
    string getTitle() const { return title; }
    string getArtist() const { return artist; }
};

#endif