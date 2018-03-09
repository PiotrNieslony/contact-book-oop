#include "Recipient.h"

Recipient::Recipient(int sId, string sFirstName, string sLastName, string sPhone, string sEmail, string sAddress){
    setAll(sId, sFirstName, sLastName, sPhone, sEmail, sAddress);
}
void  Recipient::setAll(int sId, string sFirstName, string sLastName, string sPhone, string sEmail, string sAddress){
    id = sId;
    firstName = sFirstName;
    lastName = sLastName;
    phone = sPhone;
    email = sEmail;
    address = sAddress;
}

int Recipient::getId(){
    return id;
}
string Recipient::getFirstName(){
    return firstName;
}

string Recipient::getLastName(){
    return lastName;
}

string Recipient::getPhoneNumber(){
    return phone;
}

string Recipient::getEmail(){
    return email;
}

string Recipient::getAddress(){
    return address;
}
