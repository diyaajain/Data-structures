/* This program implements a basic version of a Spotify-like music streaming service. 
It allows a user to create an account with a name and email and manage a playlist. 
The playlist has a list of songs, represented by the Song class, which includes information such as the song name, artist, album name, and duration. 
The Playlist class supplies methods to manage the playlist, such as add a song, play, play next or previous, and so on. 
The User class allows to create a user and holds name and email of the user. 
The program allows the user to interact with the system and manage the playlist of songs, simulating the basic functionality of a music streaming service. */

#include <cstdlib>
#include <iostream>
#include <string>
#include "classUser.hpp"
#include "classSong.hpp"
#include "classPlaylist.hpp"

using namespace std;

int main() {
    User<Song> player; // creating a user
    int choice;
    cout << endl;
    // menu of options to work with the playlist
    cout << "What would you like to do, " << player.getName() << "?" << endl;
    cout << "1. Add a song" << endl;
    cout << "2. Play a song" << endl;
    cout << "3. Play next song" << endl;
    cout << "4. Play previous song" << endl;
    cout << "5. Show playlist" << endl;
    cout << "6. Remove a song" << endl;
    cout << "7. Update song information" << endl;
    cout << "8. Quit" << endl;
    cout << endl;
    for (;;) {
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        // switch statement to call a specific function
        switch (choice) {
            case 1: player.addSong();
                    break;
            case 2: player.playSong();
                    break;
            case 3: player.playNext();
                    break;
            case 4: player.playPrev();
                    break;
            case 5: player.printPlaylist(player.getName(), player.getEmail());
                    break;
            case 6: player.removeSong();
                    break;
            case 7: player.updateInfo();
                    break;
            case 8: player.clearPlaylist();
                    cout << "Thank you! See you next time!" << endl;  
                    return EXIT_SUCCESS;
            default: 
                    cout << "You entered the wrong choice, please try again." << endl;
        }
    cout << endl;
    }
}