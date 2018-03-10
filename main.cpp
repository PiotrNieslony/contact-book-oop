#include <iostream>
#include "Users.h"
#include "UsersFile.h"
#include "AddressBook.h"
#include "ConsoleMessage.h"
#include "GetInt.h"

using namespace std;

void naglowekAplikacji ();

int main() {
    char wybor;
    int idLoggedUser = 0;
    int id = 0;
    string searchedValue;
    Users uzytkownicy;
    AddressBook recipients;
    ConsoleMessage message;
    PobierzLiczbeCalkowita liczba;

    while(true) {
        if( idLoggedUser == 0) {
            system("cls");
            naglowekAplikacji();
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout << "Ilosc zarejestrowanych uzytkownikow: " << uzytkownicy.numberOfRegisteredUsers() << endl << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            cout << "1. Rejestracja" << endl;
            cout << "2. Logownaie" << endl;
            cout << "3. Wyswietl uzytkownikow" << endl;
            cout << "9. Zakoncz program" << endl << endl;
            cout << "wybor: ";
            cin >> wybor;
            cin.sync();

            if(wybor == '1') {
                uzytkownicy.singUp();
            } else if(wybor == '2')     {
                idLoggedUser = uzytkownicy.logIn();
                recipients.ustawIdZalogowanegoUzytkownika(idLoggedUser);
                recipients.wczytajKontaktyZPliku();
            } else if(wybor == '3') {
                uzytkownicy.displayUsers();
            } else if(wybor == '9') {
                exit(0);
            }
        } else {
            system("cls");
            naglowekAplikacji();
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout << "Ilosc zapisanych kontaktow: "<< recipients.iloscAdresatow()  << endl << endl;
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
                recipients.wpiszAdresata();
                break;
            case '2':
                system("cls");
                cout << "EDYCJA:" << endl;
                recipients.edytujDaneAdresata();
                break;
            case '3':
                system("cls");
                cout << "Usuwanie:" << endl;
                cout << "Podaj ID kontaktu ktory chcesz usunac: ";
                id = liczba.wprowadzWartosc();
                system("cls");
                recipients.usunAdresata(id);
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
                    cin >> searchedValue;
                    recipients.wyszukajAdresataPoImieniu(searchedValue);
                    system("pause");
                } else if(wybor == '2') {
                    system("cls");
                    cout << "Podaj szukane nazwisko: ";
                    cin >> searchedValue;
                    recipients.wyszukajAdresataPoNazwisku(searchedValue);
                    system("pause");
                } else if(wybor == '9') {
                    break;
                }

                break;
            case '5':
                system("cls");
                recipients.wyswietlAdresatow();
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
                    uzytkownicy.changePassword(idLoggedUser);
                } else if(wybor == '2') {
                    recipients.czyszczenieVektora();
                    idLoggedUser = 0;
                } else if(wybor == '9') {
                    break;
                }
                break;
            case  '9':
                exit(0);
                break;
            default:
                message.warning("Nie ma takiej opcji w menu");
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
