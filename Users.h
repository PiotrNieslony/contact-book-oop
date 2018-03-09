#include <iostream>
#include <vector>
#include <windows.h>
#include <cstdio>
#include "User.h"
#include "ConsolMessage.h"

using namespace std;

class Uzytkownicy {
    vector<Uzytkownik> uzytkownicyLista;

    void dodajUzytkownika(Uzytkownik uzytkownik);
    int idOstatniegoUzytkownika();
public:
    Uzytkownicy();
    void wyswietlUzytkownikow();
    int iloscZarejestrowanychUzytkownikow();
    int logowanie();
    void rejestracja();
    void zmienHaslo(int idZalogowanegoUzytkownika);
};
