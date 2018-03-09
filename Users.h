#include <iostream>
#include <vector>
#include <windows.h>
#include <cstdio>
#include "User.h"
#include "ConsolMessage.h"

using namespace std;

class Uzytkownicy {
    vector<User> listOfUser;

    void dodajUzytkownika(User user);
    int idOstatniegoUzytkownika();
public:
    Uzytkownicy();
    void wyswietlUzytkownikow();
    int iloscZarejestrowanychUzytkownikow();
    int logowanie();
    void rejestracja();
    void changePassword(int idZalogowanegoUzytkownika);
};
