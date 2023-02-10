#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include "classUser.hpp"
#include "classSong.hpp"
#include "classPlaylist.hpp"

using namespace std;

int main() {
  User<Song> player;
  int choice;
  string option;
  cout << endl;
  cout << "What would you like to do, " << player.getName() << "?" << endl;
  cout << "1. Add a song" << endl;
  cout << "2. Play a song" << endl;
  cout << "3. Play next song" << endl;
  cout << "4. Play previous song" << endl;
  cout << "5. Show playlist" << endl;
  cout << "6. Remove a song" << endl;
  cout << "7. Quit" << endl;
  cout << endl;
  // cout << "7. Delete the playlist" << endl;
  // cout << "8. Delete account and all the information" << endl;
  for (;;) {
    cout << "Enter your choice: ";
    cin >> choice;
    cout << endl;
    switch (choice) {
      case 1: player.addSong();
              break;
      // case 2: player.getCurrentSong() = player.getPlaylist().play();
      //         break;
      // case 3: player.getPlaylist() = player.getPlaylist().next(player->playlist);
      //         break;
      // case 4: player->playlist = player->playlist.prev(player->playlist);
      //         break;
      case 5: player.printPlaylist(player.getName(), player.getEmail());
              break;
      case 6: player.removeSong();
              break;
      case 7: player.clearPlaylist();
              cout << "Thank you! Come again." << endl;  
              return EXIT_SUCCESS;
      default: cout << "You entered the wrong choice, please try again." << endl;
                break;
    }
    cout << endl;
  }
  }