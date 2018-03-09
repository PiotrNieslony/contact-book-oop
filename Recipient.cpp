#include "Recipient.h"

Adresat::Adresat(int sId, string sFirstName, string sLastName, string sPhone, string sEmail, string sAddress){
    setAll(sId, sFirstName, sLastName, sPhone, sEmail, sAddress);
}
void  Adresat::setAll(int sId, string sFirstName, string sLastName, string sPhone, string sEmail, string sAddress){
    id = sId;
    firstName = sFirstName;
    lastName = sLastName;
    phone = sPhone;
    email = sEmail;
    address = sAddress;
}

int Adresat::getId(){
    return id;
}
string Adresat::getFirstName(){
    return firstName;
}

string Adresat::getLastName(){
    return lastName;
}

string Adresat::getPhoneNumber(){
    return phone;
}

string Adresat::getEmail(){
    return email;
}

string Adresat::getAddress(){
    return address;
}
