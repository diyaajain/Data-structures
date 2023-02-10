#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Song {
  private:
      string title;
      string artist;
      string album;
      string min;
      string sec;
      Song* prev;
      Song* next;
  public:
      Song() {}
      Song(string name, string singer, string album_name, string minutes, string seconds, Song* back, Song* forward) {
          title = name;
          singer = artist;
          album_name = album;
          min = minutes;
          sec = seconds;
          prev = back;
          next = forward;
      }
  friend class Playlist;
};

class Playlist {
  private:
      Song* head;
      Song* tail;
  public:
    Playlist() {
      head = NULL;
      tail = NULL;
    }

    ~Playlist() {
      while (!empty()) {
        clear();
      }
    }

    bool empty() const {
      return head->next == tail;
    }

    void clear() {
      Song* oldSong = head;
      head = oldSong->next;
      delete oldSong;
      return;
    }

    void add() {
      string songTitle;
      string artistName;
      string albumName;
      string numSec, numMin;
      cin.ignore();
      cout << "Enter your song title: ";
      getline(cin, songTitle);
      cout<< "Enter artist's name: ";
      getline(cin, artistName);
      cout << "Enter album name (if none, enter \"N/A\"): ";
      getline(cin, albumName);
      cout << "Enter song length: ";
      cin >> numMin;
      cout << "Enter song length: ";
      getline(cin, numSec);
      Song* newSong = new Song(songTitle, artistName, albumName, numMin, numSec, NULL, NULL);
      Song* cur = head;
      
      if (head == NULL) {
        head = newSong;
        return;
      }

      while (cur->next != NULL) {
        cur = cur->next;
      }

      cur->next = newSong;
      newSong->prev = cur;

    }
    void print() {
      Song* cur = head;
      while (cur != NULL) {
        cout << "Song: " << cur->title << endl;
        cur = cur->next; 
      }
    }
};

int main() {
  Playlist myPlaylist;
  myPlaylist.add();
  cout<<endl;
  myPlaylist.print();
  cout<<endl;
  myPlaylist.add();
  myPlaylist.print();
  return EXIT_SUCCESS;
}