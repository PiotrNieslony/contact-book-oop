#include <iostream>
#include "Users.h"
#include "UsersFile.h"
#include "AddressBook.h"
#include "ConsolMessage.h"
#include "GetInt.h"

using namespace std;

void naglowekAplikacji ();

int main() {
    char wybor;
    int idZalogowanegoUzytkownika = 0;
    int id = 0;
    string szukanaWartosc;
    Uzytkownicy uzytkownicy;
    KsiazkaAdresowa adresaci;
    Komunikat komunikat;
    PobierzLiczbeCalkowita liczba;

    while(true) {
        if( idZalogowanegoUzytkownika == 0) {
            system("cls");
            naglowekAplikacji();
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout << "Ilosc zarejestrowanych uzytkownikow: " << uzytkownicy.iloscZarejestrowanychUzytkownikow() << endl << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            cout << "1. Rejestracja" << endl;
            cout << "2. Logownaie" << endl;
            cout << "3. Wyswietl uzytkownikow" << endl;
            cout << "9. Zakoncz program" << endl << endl;
            cout << "wybor: ";
            cin >> wybor;
            cin.sync();

            if(wybor == '1') {
                uzytkownicy.rejestracja();
            } else if(wybor == '2')     {
                idZalogowanegoUzytkownika = uzytkownicy.logowanie();
                adresaci.ustawIdZalogowanegoUzytkownika(idZalogowanegoUzytkownika);
                adresaci.wczytajKontaktyZPliku();
            } else if(wybor == '3') {
                uzytkownicy.wyswietlUzytkownikow();
            } else if(wybor == '9') {
                exit(0);
            }
        } else {
            system("cls");
            naglowekAplikacji();
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout << "Ilosc zapisanych kontaktow: "<< adresaci.iloscAdresatow()  << endl << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            cout << "MENU GLOWNE: "<< endl;
            cout << "1. Dodaj nowy kontakt" << endl;
            cout << "2. Edytuj kontakt" << endl;
            cout << "3. Usun kontakt" << endl;
            cout << "4. Znajdz kontakt" << endl;
            cout << "5. Wyswietl wszystkie zapisane kontaky" << endl;
            cout << "8. Uzytkownik" << endl;
            cout << "9. Zakoncz program" << endl << endl;
            cout << "wybor: ";
            cin.sync();
            cin >> wybor;
            cin.sync();

            switch(wybor) {
            case '1':
                adresaci.wpiszAdresata();
                break;
            case '2':
                system("cls");
                cout << "EDYCJA:" << endl;
                adresaci.edytujDaneAdresata();
                break;
            case '3':
                system("cls");
                cout << "Usuwanie:" << endl;
                cout << "Podaj ID kontaktu ktory chcesz usunac: ";
                id = liczba.wprowadzWartosc();
                system("cls");
                adresaci.usunAdresata(id);
                break;
            case '4':
                system("cls");
                cout << "WYSZUKIWANIE:" << endl;
                cout << "1. Wyszukaj imie" << endl;
                cout << "2. Wyszukaj nazwisko" << endl;
                cout << "9. Menu glowne" << endl << endl;
                cout << "wybor: ";
                cin >> wybor;
                cin.sync();
                if (wybor == '1') {
                    system("cls");
                    cout << "Podaj szukane Imie: ";
                    cin >> szukanaWartosc;
                    adresaci.wyszukajAdresataPoImieniu(szukanaWartosc);
                    system("pause");
                } else if(wybor == '2') {
                    system("cls");
                    cout << "Podaj szukane nazwisko: ";
                    cin >> szukanaWartosc;
                    adresaci.wyszukajAdresataPoNazwisku(szukanaWartosc);
                    system("pause");
                } else if(wybor == '9') {
                    break;
                }

                break;
            case '5':
                system("cls");
                adresaci.wyswietlAdresatow();
                system("pause");
                break;
            case  '8':
                system("cls");
                cout << "1. Zmiana hasla" << endl;
                cout << "2. Wyloguj" << endl;
                cout << "9. Menu glowne" << endl;
                cin >> wybor;
                cin.sync();
                if(wybor == '1') {
                    uzytkownicy.zmienHaslo(idZalogowanegoUzytkownika);
                } else if(wybor == '2') {
                    adresaci.czyszczenieVektora();
                    idZalogowanegoUzytkownika = 0;
                } else if(wybor == '9') {
                    break;
                }
                break;
            case  '9':
                exit(0);
                break;
            default:
                komunikat.ostrzegawczy("Nie ma takiej opcji w menu");
                break;
            }
        }
    }
    return 0;
}

void naglowekAplikacji() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout << "KSIAZKA ADRESOWA v.OBIETKOWA 1.0" << endl;
    cout << "---------------------------" << endl;
}
