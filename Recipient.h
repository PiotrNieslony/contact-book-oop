#include <iostream>

using namespace std;

#ifndef RECIPIENT_H
#define RECIPIENT_H

class Adresat{
    int id;
    string firstName, lastName, phone, email, address;
public:
    Adresat(int sId, string sFirstName, string sLastName, string sPhone, string sEmail, string sAddress);
    void setAll(int sId, string sFirstName, string sLastName, string sPhone, string sEmail, string sAddress);
    int getId();
    string getFirstName();
    string getLastName();
    string getPhoneNumber();
    string getEmail();
    string getAddress();
};

#endif
