#include <iostream>
#include <vector>
#include "Users.h"
#include "UsersFile.h"

using namespace std;

Uzytkownicy::Uzytkownicy(){
    PlikUzytkownicy plikUzytkownicy;
    plikUzytkownicy.wczytajRekordy(uzytkownicyLista);
}

void Uzytkownicy::dodajUzytkownika(Uzytkownik uzytkownik) {
    uzytkownicyLista.push_back(uzytkownik);
}

void Uzytkownicy::wyswietlUzytkownikow() {
    system("cls");
    vector<Uzytkownik>::iterator koniec = uzytkownicyLista.end();
    for(vector<Uzytkownik>::iterator itr = uzytkownicyLista.begin(); itr != koniec; ++itr) {
        cout << " ~ " << (*itr).pobierzNazwe() << endl;
    }
    system("pause");
}

int Uzytkownicy::iloscZarejestrowanychUzytkownikow(){
    return uzytkownicyLista.size();
}

int Uzytkownicy::idOstatniegoUzytkownika() {
    if (uzytkownicyLista.size() == 0) return 0;
    vector<Uzytkownik>::iterator ostatniUzytkownik = uzytkownicyLista.end();
    --ostatniUzytkownik;
    return (*ostatniUzytkownik).pobierzId();

}


void Uzytkownicy::rejestracja() {
    PlikUzytkownicy plik;
    string nazwa, haslo;
    cout << "Podaj nazwe uzytkownika: ";
    cin >> nazwa;
    vector<Uzytkownik>::iterator koniec = uzytkownicyLista.end();
    for(vector<Uzytkownik>::iterator itr = uzytkownicyLista.begin(); itr != koniec; ++itr) {
        if((*itr).pobierzNazwe() == nazwa) {
            cout << "Taki uzytkownik juz istnieje. Wpisz inna nazwe uzytkownika: ";
            cin >> nazwa;
            itr = uzytkownicyLista.begin();
        }
    }
    cout << "Podaj haslo: ";
    cin >> haslo;

    Uzytkownik pojedynczyUzytkownik(idOstatniegoUzytkownika() + 1, nazwa, haslo);
    dodajUzytkownika(pojedynczyUzytkownik);

    PlikUzytkownicy plikUzytkownicy();
    plik.dodajNowyRekord(pojedynczyUzytkownik);
}

int Uzytkownicy::logowanie() {
    Komunikat komunikat;
    string nazwa, haslo;
    cout << "Podaj nazwe:  ";
    cin >> nazwa;
    vector<Uzytkownik>::iterator koniec = uzytkownicyLista.end();
    for(vector<Uzytkownik>::iterator itr = uzytkownicyLista.begin(); itr != koniec; ++itr) {
        if((*itr).pobierzNazwe() == nazwa) {
            for(int j=3; j>0; j--) {
                cout << "Podaj haslo. pozostalo prob " << j << ": ";
                cin >> haslo;
                if ((*itr).sprawdzHaslo(haslo)) {
                    cout << "Zalogowales sie" << endl;
                    Sleep(1000);
                    return (*itr).pobierzId();
                }
            }
            komunikat.wyswietl("Podales 3 razy bledne haslo, odczekaj 3s", "ostrzegawczy", 3000);
            return 0;
        }
    }
    komunikat.wyswietl("Nie ma uzytkownika: " + nazwa, "ostrzegawczy");
    return 0;
}

void Uzytkownicy::zmienHaslo(int idZalogowanegoUzytkownika) {
    string haslo;
    PlikUzytkownicy plik;
    vector<Uzytkownik>::iterator koniec = uzytkownicyLista.end();
    for(vector<Uzytkownik>::iterator itr = uzytkownicyLista.begin(); itr != koniec; ++itr) {
        if((*itr).pobierzId() == idZalogowanegoUzytkownika) {
            cout << "Wprawadz nowe haslo: ";
            cin >> haslo;
            (*itr).zmienHaslo(haslo);
            plik.edytujRekord(*itr);
        }
    }
}
