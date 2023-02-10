#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include "classPlaylist.hpp"
#include "classNode.hpp"

template <typename E>
bool Playlist<E>::empty() const { return (header->next == trailer); }

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
void Playlist<E>::add() {
  string songTitle, artistName, albumName, time;
  char ch;
  cout << "Enter your song title: ";
  getline(cin, songTitle);
  cout << "Enter artist name: ";
  getline(cin, artistName);
  cout << "Enter album name (if none, enter \"N/A\"): ";
  getline(cin, albumName);
  cout << "Enter song length (MM:SS): ";
  while (true) {
      cin >> time;
      if (timeValidation(time)) {
          break;
      }
      cout << "Invalid time format. Please try again." << endl;
  }
  cin.ignore();
  // Song* newSong = new Song(songTitle, artistName, albumName, time);
  Node<E>* newNode = new Node<E>(new E(songTitle, artistName, albumName, time), header, trailer);
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

template <typename E>
void Playlist<E>::print() {
  Node<E>* cur = header->next;
  cout << "PRINTING:" << endl;
  while (cur != trailer) {
    cout << cur->songInfo->title << endl;
    cur = cur->next;
  }
}

template <typename E>
bool Playlist<E>::timeValidation(const string& time) {
    regex timeFormat("^(\\d{1,2}):(\\d{2})$");
    return regex_match(time, timeFormat);
}
