#include <iostream>
#include "User.h"

using namespace std;

User::User(){};

User::User(int iID, string iName, string iPassword) {
    setAll (iID, iName, iPassword);
}

void User::setAll (int iID, string iName, string iPassword) {
    id = iID;
    name = iName;
    password = iPassword;
}

int User::getId () {
    return id;
}

string User::getName () {
    return name;
}

string User::getPassword () {
    return password;
}

bool User::checkPassword (string passwordToCompare) {
    if(password == passwordToCompare) return true;
    else return false;
}

void User::changePassword(string newPassword){
    password = newPassword;
}

