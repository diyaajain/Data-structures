#ifndef CLASSNODE_HPP
#define CLASSNODE_HPP
#include "classPlaylist.hpp"

using namespace std;

template <typename E> class Playlist;
template <typename E>
class Node {
  private:
    E* songInfo;
    Node<E>* prev;
    Node<E>* next;
  
  public:
    Node(){};
    Node<E>(E* song, Node<E>* back, Node<E>* forward) {
      songInfo = song;
      prev = back;
      next = forward;
    }
  friend class Playlist<E>;
};



#endif