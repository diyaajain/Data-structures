#ifndef CLASSPLAYLIST_HPP
#define CLASSPLAYLIST_HPP
#include "classNode.hpp"
#include "classUser.hpp"
#include <iostream>
#include <string>

using namespace std;
template <typename E> class User;
template <typename E>
class Playlist {
  private:
    Node<E>* header;
    Node<E>* trailer;

  public:
    Playlist<E>() {
      header = new Node<E>();
      trailer = new Node<E>();
      header->next = trailer;
      trailer->prev = header;
    }

    ~Playlist<E>() {
      while (!empty()) {
        clear();
      }
      delete header;
      delete trailer;
    }

    bool empty() const { return (header->next == trailer); } 
    void clear();
    void add();
    // void print();
    // Node<E>* next(Node<E>* currentSong);
    // Node<E>* prev(Node<E>* currentSong);
    Node<E>* play();
    void remove();
    void update();
    void showPlaylist(const string& user, const string& email);
};

// template <typename E>
// Node<E>* Playlist<E>::next(Node<E>* currentSong) {
//   if (currentSong == trailer || currentSong == trailer->prev) {
//     cout << "No next song." << endl;
//     return;
//   }
//   currentSong = currentSong->next;
//   cout << "Now playing: " << currentSong->songInfo->getTitle() << " by " << currentSong->songInfo->getArtist() << endl;
//   return currentSong;
// }

// template <typename E>
// Node<E>* Playlist<E>::prev(Node<E>* currentSong) {
//   if (currentSong == header->next || currentSong == header) {
//     cout << "No previous song." << endl;
//     return;
//   }
//   currentSong = currentSong->prev;
//   cout << "Now playing: " << currentSong->songInfo->getTitle() << " by " << currentSong->songInfo->getArtist() << endl;
//   return currentSong;
// }

template <typename E>
Node<E>* Playlist<E>::play() {
  if (header->next == trailer) {
    cout << "There are no songs in the playlist." << endl;
    return header->next;
  }
  string songName;
  cout << "Enter the song title: ";
  getline(cin, songName);
  cout<<songName<<endl;
  Node<E>* cur = header->next;
  while (cur != trailer && cur->songInfo->getTitle() != songName) {
    cur = cur->next;
  }
  if (cur == trailer) {
    cout << "No song with title " << songName << " found." << endl;
    return header->next;
  }
  cout << "Now playing: " << cur->songInfo->getTitle() << " by " << cur->songInfo->getArtist() << endl;
  return cur;
}

template <typename E>
void Playlist<E>::remove() {
  cin.ignore();
  if (empty()) {
    cout << "No songs in the playlist." << endl;
    return;
  }
  string songName;
  cout << "Enter your song title: ";
  getline(cin, songName);
  Node<E>* cur = header->next;
  while (cur != trailer && cur->songInfo->getTitle() != songName) {
    cur = cur->next;
  }
  if (cur == trailer) {
    cout << "No song with title " << songName << " found." << endl;
    return;
  }
  cur->prev->next = cur->next;
  cur->next->prev = cur->prev;
  delete cur;
  cout << "Song with title \"" << songName << "\" removed!" << endl;
}

template <typename E>
void Playlist<E>::showPlaylist(const string& user, const string& email) {
  if (empty()) {
    cout << "No songs in the playlist." << endl;
    return;
  }

  Node<E>* temp = header->next;
  cout << "Playlist for " << user << " (" << email << ")" << endl;
  while (temp != trailer) {
    cout << temp->songInfo->getTitle() << " by " << temp->songInfo->getArtist() << endl;
    temp = temp->next;
  }
}

template <typename E>
void Playlist<E>::clear() {
  Node<E>* cur = header->next;
  while (cur != trailer) {
    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
    delete cur;
    cur = header->next;
  }
}
template <typename E>
void Playlist<E>::update() {
  cin.ignore();
  cout << "What would you like to update?" << endl;
  cout << "1. Song information" << endl;
  cout << "2. Your name" << endl;
  cout << "3. Your email - id" << endl;
  cout << "Enter your choice: ";
  int choice;
  cin >> choice;
  switch(choice) {
    case 1: 
    {
      if (empty()) {
    cout << "No songs in the playlist." << endl;
    return;
    }
      cout << "Enter the name of the song you want to update: ";
      string songName;
      cin.ignore();
      getline(cin, songName);
      Node<E>* cur = header;
      while (cur != trailer) {
        if (cur->songInfo->getTitle() == songName) {
          cur->songInfo->setTitle(songName);
          break;
        }
        cur = cur->next;
      }
      if (cur == nullptr) {
        cout << "No such song was found in the playlist." << endl;
      }
      break;
    }
    case 2:
    { 
      cout << "Enter a new name: ";
      string name;
      cin.ignore();
      getline(cin, name);
      break;
    }  
    case 3:
    { 
      cout << "Enter a new email - id: ";
      string email_id;
      cin.ignore();
      getline(cin, email_id);
      break;
    } 
    default:
      cout << "Invalid choice. Please try again." << endl;
      break;
  }
}

template <typename E>
void Playlist<E>::add() {
  string songTitle, artistName, albumName;
  int numMin, numSec;
  char ch;
  cin.ignore();
  cout << "Enter your song title: ";
  getline(cin, songTitle);
  cout << "Enter artist name: ";
  getline(cin, artistName);
  cout << "Enter album name (if none, enter \"N/A\"): ";
  getline(cin, albumName);
  cout << "Enter song length (MM:SS): ";
  while (true) {
    cin >> numMin >> ch >> numSec;
    if (numMin >= 0 && numMin <= 60 && ch == ':' && numSec >= 0 && numSec < 60) {
      break;
    }
    cout << "Invalid format. Please re-enter song length (MM:SS): ";
  }

  Node<E>* newNode = new Node<E>(new E(songTitle, artistName, albumName, numMin, numSec), header, trailer);
  Node<E>* cur = header->next;

  if (empty()) {
    header->next = newNode;
    return;
  }

  while (cur->next != trailer) {
    cur = cur->next;
  }

  cur->next = newNode;
  newNode->prev = cur;
}

// template <typename E>
// void Playlist<E>::print() {
//       Node<E>* cur = header->next;
//       cout << "PRINTING:" << endl;
//       while (cur != trailer) {
//         cout << cur->songInfo->getTitle() << endl;
//         cur = cur->next;
//       }
// }
#endif
