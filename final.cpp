#include <iostream>
#include <string>

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

class Song {
  private:
    string title;
    string artist;
    string album;
    int min;
    int sec;
  
  public:
    Song(){};
    Song(string& name, string& singer, string& albumName, int m, int s) {
      title = name;
      artist = singer;
      album = albumName;
      min = m;
      sec = s;
    };
    string getTitle() const{
      return title;
    }
  string getArtist() const{
      return artist;
    }
};

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
      this->name = name;
      this->email = email;
      this->playlist = playlist;
    };
  
    void getPlaylist() { playlist.print(); };
    void createAccount();
  
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

void createAccount() {
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
};
void addSong(string title, string artist) {
    Song* newSong = new Song();
    newSong->title = title;
    newSong->artist = artist;
    newSong->next = nullptr;
    newSong->prev = tail;

    if (tail != nullptr) {
      tail->next = newSong;
    }

    tail = newSong;

    if (head == nullptr) {
      head = newSong;
    }
  }

int main()
{
    User player;
    player.createAccount();

    int choice;
    do
    {
        cout << "1. Add a song" << endl;
        cout << "2. Play a song" << endl;
        cout << "3. Play next song" << endl;
        cout << "4. Play previous song" << endl;
        cout << "5. Show playlist" << endl;
        cout << "6. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        if (choice == 1) 
        {
          string title, artist;
          player.addSong(title, artist);
        } 
    else if (choice == 2) 
    {
      string title;
      cout << "Enter song title: ";
      getline(cin, title);
      player.play(title);
    } 
    else if (choice == 3) 
    {
      player.next();
    } 
    else if (choice == 4) 
    {
      player.prev();
    } 
    else if (choice == 5) 
    {
      player.showPlaylist();
    }
  } while (choice != 6);

  return 0;
}