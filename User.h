#include <iostream>

using namespace std;

#ifndef USER_H
#define USER_H

class User {
    int id;
    string name, password;
public:
    User();
    User(int iID, string iName, string iPassword);
    void setAll (int iID, string iName, string iPassword);
    int getId();
    string getName();
    string getPassword();
    bool checkPassword(string passwordToCompare);
    void changePassword(string newPassword);
};

#endif




