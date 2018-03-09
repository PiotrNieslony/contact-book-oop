#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include "User.h"
#include "File.h"

#ifndef PLIK_UZYTKOWNICY_H
#define PLIK_UZYTKOWNICY_H

using namespace std;

class PlikUzytkownicy :public Plik {
public:
    PlikUzytkownicy();
    PlikUzytkownicy(string nazwa);
    void edytujRekord(Uzytkownik uzytkownik);
    void dodajNowyRekord(Uzytkownik uzytkownik);
    void wczytajRekordy(vector<Uzytkownik> & uzytkownicyLista);
};

#endif
