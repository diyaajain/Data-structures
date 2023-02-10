#include <iostream>
#include <regex>
#include <string>
#include "classUser.hpp"


using namespace std;

template <typename E>
void User<E>::emailVerification(const string& email) {
  regex pattern("[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}");
  bool validity = regex_match(email, pattern);
  while (!validity) {
    cout << "Please re-enter your email (required format: janedoe@gmail.com): ";
    string newEmail;
    getline(cin, newEmail);
    validity = regex_match(newEmail, pattern);
    setEmail(newEmail);
  }
}


