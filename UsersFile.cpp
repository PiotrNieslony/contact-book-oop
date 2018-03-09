#include <iostream>
#include <fstream>
#include <windows.h>
#include "User.h"
#include "UsersFile.h"

using namespace std;

PlikUzytkownicy::PlikUzytkownicy()
    :Plik("Uzytkownicy.txt"){
    nazwaPliku = "Uzytkownicy.txt";
}

PlikUzytkownicy::PlikUzytkownicy(string name)
    :Plik(name){
    nazwaPliku = name;
}


void PlikUzytkownicy::dodajNowyRekord(User uzytkownik){
    fstream plik;
    plik.open(nazwaPliku.c_str(), ios::out | ios::app);
    if(plik.good() == false) {
        cout << "Wystapil problem przy probie zapisu danych do pliku." << endl;
        return ;
    }

    plik << uzytkownik.getId() << "|";
    plik << uzytkownik.getName() << "|";
    plik << uzytkownik.getPassword() << "|" << endl;
    plik.close();
}

void PlikUzytkownicy::edytujRekord(User uzytkownik){
    string linia;
    int idUzytkownika;
    size_t pozycjaSeparatora;
    int i = 0;
    string kopiaPliku = "." + nazwaPliku;
    remove(kopiaPliku.c_str());
    if((rename(nazwaPliku.c_str(), kopiaPliku.c_str())) != 0) {
        cout << ( "Blad przy tworzeniu kopii pliku" ) << endl;
        return;
    }
    fstream plik;
    fstream plikKopia;
    plik.open(nazwaPliku.c_str(), ios::out | ios::app);
    plikKopia.open(kopiaPliku.c_str(),ios::in);
    if(plik.good() == false || plikKopia.good() == false) {
        cout << "Wystapil problem przy probie zapisu danych do pliku." << endl;
        return;
    }
    while(getline(plikKopia, linia)) {
        pozycjaSeparatora = linia.find("|");
        idUzytkownika = atoi(linia.substr(0, pozycjaSeparatora).c_str());
        if (idUzytkownika == uzytkownik.getId()) {
            plik << uzytkownik.getId() << "|";
            plik << uzytkownik.getName() << "|";
            plik << uzytkownik.getPassword()<< "|" << endl;
        } else {
            plik << linia << endl;
        }
    }
    plik.close();
    plikKopia.close();
}

void PlikUzytkownicy::wczytajRekordy(vector<User>& uzytkownicyLista){
    string linia;
    int id;
    string name, password;
    User pojedynczyUzytkownik;
    fstream plikUzytkownicy;
    size_t pozycjaZnakuOd;
    size_t pozycjaSeparatora;
    int iloscZnakow;

    plikUzytkownicy.open("Uzytkownicy.txt",ios::in);
    if(plikUzytkownicy.good() == false) {
        cout << "Wystapil problem z odczytem kontaktow z pliku: " << "Uzytkownicy.txt" <<  endl;
        return;
    }

    while(getline(plikUzytkownicy, linia)) {

        pozycjaSeparatora = linia.find("|");
       id = atoi(linia.substr(0, pozycjaSeparatora).c_str());

        pozycjaZnakuOd = pozycjaSeparatora+1;
        pozycjaSeparatora = linia.find("|",pozycjaZnakuOd);
        iloscZnakow = pozycjaSeparatora - pozycjaZnakuOd;
        name = linia.substr(pozycjaZnakuOd, iloscZnakow);

        pozycjaZnakuOd = pozycjaSeparatora+1;
        pozycjaSeparatora = linia.find("|",pozycjaZnakuOd);
        iloscZnakow = pozycjaSeparatora - pozycjaZnakuOd;
        password = linia.substr(pozycjaZnakuOd, iloscZnakow);

        pojedynczyUzytkownik.setAll(id, name, password);
        uzytkownicyLista.push_back(pojedynczyUzytkownik);
    }
    plikUzytkownicy.close();
}

