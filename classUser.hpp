/* This is the header file for the User class. */
#ifndef CLASSUSER_HPP
#define CLASSUSER_HPP
#include "classPlaylist.hpp"
#include "classNode.hpp"
#include <iostream>

using namespace std;

// Template class for User
template <typename E>
class User {
  private: // Member variables for User
    string name;
    string email;
    Playlist<E> playlist;
    Node<E>* currentSong;
    bool validateEmail(string& email); // Private method to validate email
  public: 
    User<E>(); // Default constructor for User
    User<E>(string& name, string& email, Playlist<E> playlist, Node<E>* cur) : name(name), email(email), playlist(playlist), currentSong(cur) {}
    Node<E>* getCurrentSong() const { return currentSong; };
    string getName() const { return name; };
    string getEmail() const { return email; };
    void setCurrentSong(Node<E>* newCurrent) { currentSong = newCurrent; };
    void printPlaylist(const string& user, const string& email) { playlist.showPlaylist(user, email); };
    void addSong() { playlist.add(); }
    void removeSong() { playlist.remove(); }
    void clearPlaylist() { playlist.clear(); }
    void playSong() { setCurrentSong(playlist.play()); };
    void playPrev() { setCurrentSong(playlist.prev()); };
    void playNext() { setCurrentSong(playlist.next()); };
    void updateInfo() { playlist.updateSongInfo(); };
  friend class Playlist<E>;
};

template <typename E>
User<E>::User() {
  cout << "********************" << endl;
  cout << "Welcome to COPtify!" << endl;
  cout << "********************" << endl;
  cout << "Let's create your profile." << endl;
  cout << "Please enter your full name: ";
  getline(cin, name);
  bool isValid = false;
  cout << "Please enter your email: ";
  while (!isValid) {
    cin >> email;
    isValid = validateEmail(email);
    if (!isValid) {
      cout << "Invalid email format. Please enter a valid email: ";
    }
  }
  ;
};

template <typename E>
bool User<E>::validateEmail(string& email) {
    int atPos = email.find("@");
    int dotPos = email.find(".");

    if (atPos == string::npos || email.find("@", atPos + 1) != string::npos) {
        return false;
    }

    if (dotPos == string::npos || dotPos < atPos) {
        return false;
    }
    
    if (email.length() - dotPos < 2) {
        return false;
    }
    
    return true;
}

#endif