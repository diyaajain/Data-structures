#ifndef CLASSSONG_HPP
#define CLASSSONG_HPP
#include <iostream>
#include "classPlaylist.hpp"

using namespace std;

class Song {
  private:
    string title;
    string artist;
    string album;
    int min;
    int sec;
  
  public:
    Song(){};
    Song(string& name, string& singer, string& albumName, int m, int s) {
      title = name;
      artist = singer;
      album = albumName;
      min = m;
      sec = s;
    };
    string getTitle() const{
      return title;
    }
    string getArtist() const{
      return artist;
    }
};

#endif