#include <cstdlib>
#include <iostream>
#include "classUser.hpp"
#include "classSong.hpp"
#include "classPlaylist.hpp"
using namespace std;

int main() {
  User<Song> myUser;
  myUser.getPlaylist();
  // Playlist myPlaylist;
  // myPlaylist.add();
  // myPlaylist.add();
  // myPlaylist.print();
  
  return EXIT_SUCCESS;
}