#include <iostream>
#include "Users.h"
#include "UsersFile.h"
#include "AddressBook.h"
#include "ConsoleMessage.h"
#include "GetInt.h"

using namespace std;

void naglowekAplikacji ();

int main() {
    char choice;
    int idLoggedUser = 0;
    int id = 0;
    string searchedValue;
    Users users;
    AddressBook recipients;
    ConsoleMessage message;
    GetInt getNumber;

    while(true) {
        if( idLoggedUser == 0) {
            system("cls");
            naglowekAplikacji();
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout << "Ilosc zarejestrowanych uzytkownikow: " << users.numberOfRegisteredUsers() << endl << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
            cout << "1. Rejestracja" << endl;
            cout << "2. Logownaie" << endl;
            cout << "3. Wyswietl uzytkownikow" << endl;
            cout << "9. Zakoncz program" << endl << endl;
            cout << "wybor: ";
            cin >> choice;
            cin.sync();

            if(choice == '1') {
                users.singUp();
            } else if(choice == '2')     {
                idLoggedUser = users.logIn();
                recipients.setIdOfLoggedUser(idLoggedUser);
                recipients.loadRecipientsFromFile();
            } else if(choice == '3') {
                users.displayUsers();
            } else if(choice == '9') {
                exit(0);
            }
        } else {
            system("cls");
            naglowekAplikacji();
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
            cout << "Ilosc zapisanych kontaktow: "<< recipients.quantityOfRecipients()  << endl << endl;
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
            cin >> choice;
            cin.sync();

            switch(choice) {
            case '1':
                recipients.typeRecipientData();
                break;
            case '2':
                system("cls");
                cout << "EDYCJA:" << endl;
                recipients.editRecipientData();
                break;
            case '3':
                system("cls");
                cout << "Usuwanie:" << endl;
                cout << "Podaj ID kontaktu ktory chcesz usunac: ";
                id = getNumber.enterValue();
                system("cls");
                recipients.removeRecipient(id);
                break;
            case '4':
                system("cls");
                cout << "WYSZUKIWANIE:" << endl;
                cout << "1. Wyszukaj imie" << endl;
                cout << "2. Wyszukaj nazwisko" << endl;
                cout << "9. Menu glowne" << endl << endl;
                cout << "wybor: ";
                cin >> choice;
                cin.sync();
                if (choice == '1') {
                    system("cls");
                    cout << "Podaj szukane Imie: ";
                    cin >> searchedValue;
                    recipients.findRecipientUsingFirstName(searchedValue);
                    system("pause");
                } else if(choice == '2') {
                    system("cls");
                    cout << "Podaj szukane nazwisko: ";
                    cin >> searchedValue;
                    recipients.findRecipientUsingLastName(searchedValue);
                    system("pause");
                } else if(choice == '9') {
                    break;
                }

                break;
            case '5':
                system("cls");
                recipients.displayRecipients();
                system("pause");
                break;
            case  '8':
                system("cls");
                cout << "1. Zmiana hasla" << endl;
                cout << "2. Wyloguj" << endl;
                cout << "9. Menu glowne" << endl;
                cin >> choice;
                cin.sync();
                if(choice == '1') {
                    users.changePassword(idLoggedUser);
                } else if(choice == '2') {
                    recipients.clearVector();
                    idLoggedUser = 0;
                } else if(choice == '9') {
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
