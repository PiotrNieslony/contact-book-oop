#include <iostream>

using namespace std;

#ifndef ADRESAT_H
#define ADRESAT_H

class Adresat{
    int id;
    string imie, nazwisko, telefon, email, adres;
public:
    Adresat(int sId, string sImie, string sNazwisko, string sTelefon, string sEmail, string sAdres);
    void wczytaj(int sId, string sImie, string sNazwisko, string sTelefon, string sEmail, string sAdres);
    int pobierzId();
    string pobierzImie();
    string pobierzNazwisko();
    string pobierzTelefon();
    string pobierzEmail();
    string pobierzAdres();
};

#endif