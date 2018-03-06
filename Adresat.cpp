#include "Adresat.h"

Adresat::Adresat(int sId, string sImie, string sNazwisko, string sTelefon, string sEmail, string sAdres){
    wczytaj(sId, sImie, sNazwisko, sTelefon, sEmail, sAdres);
}
void  Adresat::wczytaj(int sId, string sImie, string sNazwisko, string sTelefon, string sEmail, string sAdres){
    id = sId;
    imie = sImie;
    nazwisko = sNazwisko;
    telefon = sTelefon;
    email = sEmail;
    adres = sAdres;
}

int Adresat::pobierzId(){
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
