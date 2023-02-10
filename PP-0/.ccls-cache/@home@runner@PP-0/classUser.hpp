#ifndef CLASSUSER_HPP
#define CLASSUSER_HPP
#include "classPlaylist.hpp"
#include <iostream>

using namespace std;

template <typename E>
class User {
  private:
    string name;
    string email;
    Playlist<E> playlist;
    bool validateEmail(string& email);
  public:
    User<E>();
    User<E>(string& name, string& email, Playlist<E>& playlist) {
      name = name;
      email = email;
      playlist = playlist;
    };
  
    void getPlaylist() { playlist.print(); };
  
  friend class Playlist<E>;
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

template <typename E>
User<E>::User() {
  cout << "Welcome to COPtify!" << endl;
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
  cout << "Let's create your first COPtify playlist!" << endl;
  playlist.add();
};

#endif