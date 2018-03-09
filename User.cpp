#include <iostream>
#include "User.h"

using namespace std;

Uzytkownik::Uzytkownik(){};

Uzytkownik::Uzytkownik(int sID, string sNazwa, string sHaslo) {
    wczytaj (sID, sNazwa, sHaslo);
}

void Uzytkownik::wczytaj (int sID, string sNazwa, string sHaslo) {
    id = sID;
    nazwa = sNazwa;
    haslo = sHaslo;
}

int Uzytkownik::pobierzId () {
    return id;
}

string Uzytkownik::pobierzNazwe () {
    return nazwa;
}

string Uzytkownik::pobierzHaslo () {
    return haslo;
}

bool Uzytkownik::sprawdzHaslo (string podaneHaslo) {
    if(haslo == podaneHaslo) return true;
    else return false;
}

void Uzytkownik::zmienHaslo(string noweHaslo){
    haslo = noweHaslo;
}

