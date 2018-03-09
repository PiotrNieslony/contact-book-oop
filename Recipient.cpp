#include "Recipient.h"

Adresat::Adresat(int sId, string sImie, string sNazwisko, string sTelefon, string sEmail, string sAdres){
    setAll(sId, sImie, sNazwisko, sTelefon, sEmail, sAdres);
}
void  Adresat::setAll(int sId, string sImie, string sNazwisko, string sTelefon, string sEmail, string sAdres){
    id = sId;
    imie = sImie;
    nazwisko = sNazwisko;
    telefon = sTelefon;
    email = sEmail;
    adres = sAdres;
}

int Adresat::getId(){
    return id;
}
string Adresat::pobierzImie(){
    return imie;
}

string Adresat::pobierzNazwisko(){
    return nazwisko;
}

string Adresat::pobierzTelefon(){
    return telefon;
}

string Adresat::pobierzEmail(){
    return email;
}

string Adresat::pobierzAdres(){
    return adres;
}
