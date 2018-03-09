#include <iostream>
#include <vector>
#include "Users.h"
#include "UsersFile.h"

using namespace std;

Uzytkownicy::Uzytkownicy(){
    PlikUzytkownicy plikUzytkownicy;
    plikUzytkownicy.wczytajRekordy(uzytkownicyLista);
}

void Uzytkownicy::dodajUzytkownika(User uzytkownik) {
    uzytkownicyLista.push_back(uzytkownik);
}

void Uzytkownicy::wyswietlUzytkownikow() {
    system("cls");
    vector<User>::iterator koniec = uzytkownicyLista.end();
    for(vector<User>::iterator itr = uzytkownicyLista.begin(); itr != koniec; ++itr) {
        cout << " ~ " << (*itr).getName() << endl;
    }
    system("pause");
}

int Uzytkownicy::iloscZarejestrowanychUzytkownikow(){
    return uzytkownicyLista.size();
}

int Uzytkownicy::idOstatniegoUzytkownika() {
    if (uzytkownicyLista.size() == 0) return 0;
    vector<User>::iterator ostatniUzytkownik = uzytkownicyLista.end();
    --ostatniUzytkownik;
    return (*ostatniUzytkownik).getId();

}


void Uzytkownicy::rejestracja() {
    PlikUzytkownicy plik;
    string name, password;
    cout << "Podaj nazwe uzytkownika: ";
    cin >> name;
    vector<User>::iterator koniec = uzytkownicyLista.end();
    for(vector<User>::iterator itr = uzytkownicyLista.begin(); itr != koniec; ++itr) {
        if((*itr).getName() == name) {
            cout << "Taki uzytkownik juz istnieje. Wpisz inna nazwe uzytkownika: ";
            cin >> name;
            itr = uzytkownicyLista.begin();
        }
    }
    cout << "Podaj haslo: ";
    cin >> password;

    User pojedynczyUzytkownik(idOstatniegoUzytkownika() + 1, name, password);
    dodajUzytkownika(pojedynczyUzytkownik);

    PlikUzytkownicy plikUzytkownicy();
    plik.dodajNowyRekord(pojedynczyUzytkownik);
}

int Uzytkownicy::logowanie() {
    Komunikat komunikat;
    string name, password;
    cout << "Podaj nazwe:  ";
    cin >> name;
    vector<User>::iterator koniec = uzytkownicyLista.end();
    for(vector<User>::iterator itr = uzytkownicyLista.begin(); itr != koniec; ++itr) {
        if((*itr).getName() == name) {
            for(int j=3; j>0; j--) {
                cout << "Podaj haslo. pozostalo prob " << j << ": ";
                cin >> password;
                if ((*itr).checkPassword(password)) {
                    cout << "Zalogowales sie" << endl;
                    Sleep(1000);
                    return (*itr).getId();
                }
            }
            komunikat.wyswietl("Podales 3 razy bledne haslo, odczekaj 3s", "ostrzegawczy", 3000);
            return 0;
        }
    }
    komunikat.wyswietl("Nie ma uzytkownika: " + name, "ostrzegawczy");
    return 0;
}

void Uzytkownicy::changePassword(int idZalogowanegoUzytkownika) {
    string password;
    PlikUzytkownicy plik;
    vector<User>::iterator koniec = uzytkownicyLista.end();
    for(vector<User>::iterator itr = uzytkownicyLista.begin(); itr != koniec; ++itr) {
        if((*itr).getId() == idZalogowanegoUzytkownika) {
            cout << "Wprawadz nowe haslo: ";
            cin >> password;
            (*itr).changePassword(password);
            plik.edytujRekord(*itr);
        }
    }
}
