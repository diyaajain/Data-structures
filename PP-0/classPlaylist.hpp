#ifndef CLASSPLAYLIST_HPP
#define CLASSPLAYLIST_HPP
#include "classNode.hpp"
#include <iostream>

using namespace std;

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
    void print();
    void remove();
    void remove(string songTitle);
};
template <typename E>
void Playlist<E>::remove(string songTitle) {
  Node<E>* cur = header->next;
  while (cur != trailer) {
    if (cur->songInfo->getTitle() == songTitle) {
      cur->prev->next = cur->next;
      cur->next->prev = cur->prev;
      delete cur->songInfo;
      delete cur;
      return;
    }
    cur = cur->next;
  }
  cout << "Song not found." << endl;
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

template <typename E>
void Playlist<E>::print() {
      Node<E>* cur = header->next;
      cout << "PRINTING:" << endl;
      while (cur != trailer) {
        cout << cur->songInfo->getTitle() << endl;
        cur = cur->next;
      }
}
#endif