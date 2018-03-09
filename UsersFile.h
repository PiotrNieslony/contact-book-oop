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
    PlikUzytkownicy(string name);
    void edytujRekord(User uzytkownik);
    void dodajNowyRekord(User uzytkownik);
    void wczytajRekordy(vector<User> & uzytkownicyLista);
};

#endif
