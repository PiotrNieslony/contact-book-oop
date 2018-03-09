#include <iostream>

using namespace std;

#ifndef UZYTKOWNIK_H
#define UZYTKOWNIK_H

class Uzytkownik {
    int id;
    string nazwa, haslo;
public:
    Uzytkownik();
    Uzytkownik(int sID, string sNazwa, string sHaslo);
    void wczytaj (int sID, string sNazwa, string sHaslo);
    int pobierzId();
    string pobierzNazwe();
    string pobierzHaslo();
    bool sprawdzHaslo(string podaneHaslo);
    void zmienHaslo(string noweHaslo);
};

#endif




