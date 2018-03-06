#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include "Adresat.h"
#include "Plik.h"
#include "Komunikat.h"

#ifndef PLIK_UZYTKOWNICY_H
#define PLIK_UZYTKOWNICY_H

using namespace std;

class PlikAdresaci :public Plik {
public:
    PlikAdresaci();
    PlikAdresaci(string nazwa);
    void edytujRekord(Adresat adresat, int idZalogowanegoUzytkownika);
    int usunRekord(Adresat adresat, int idZalogowanegoUzytkownika);
    void dodajNowyRekord(Adresat adresat, int idZalogowanegoUzytkownika);
    int wczytajRekordy(vector<Adresat> & adresaci, int idZalogowanegoUzytkownika);
};

#endif
