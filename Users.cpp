#include <iostream>
#include <vector>
#include "Users.h"
#include "UsersFile.h"

using namespace std;

Uzytkownicy::Uzytkownicy(){
    UsersFile usersFile;
    usersFile.loadAllRecords(listOfUser);
}

void Uzytkownicy::dodajUzytkownika(User user) {
    listOfUser.push_back(user);
}

void Uzytkownicy::wyswietlUzytkownikow() {
    system("cls");
    vector<User>::iterator koniec = listOfUser.end();
    for(vector<User>::iterator itr = listOfUser.begin(); itr != koniec; ++itr) {
        cout << " ~ " << (*itr).getName() << endl;
    }
    system("pause");
}

int Uzytkownicy::iloscZarejestrowanychUzytkownikow(){
    return listOfUser.size();
}

int Uzytkownicy::idOstatniegoUzytkownika() {
    if (listOfUser.size() == 0) return 0;
    vector<User>::iterator ostatniUzytkownik = listOfUser.end();
    --ostatniUzytkownik;
    return (*ostatniUzytkownik).getId();

}


void Uzytkownicy::rejestracja() {
    UsersFile file;
    string name, password;
    cout << "Podaj nazwe uzytkownika: ";
    cin >> name;
    vector<User>::iterator koniec = listOfUser.end();
    for(vector<User>::iterator itr = listOfUser.begin(); itr != koniec; ++itr) {
        if((*itr).getName() == name) {
            cout << "Taki uzytkownik juz istnieje. Wpisz inna nazwe uzytkownika: ";
            cin >> name;
            itr = listOfUser.begin();
        }
    }
    cout << "Podaj haslo: ";
    cin >> password;

    User singleUser(idOstatniegoUzytkownika() + 1, name, password);
    dodajUzytkownika(singleUser);

    UsersFile usersFile();
    file.addRecord(singleUser);
}

int Uzytkownicy::logowanie() {
    Komunikat komunikat;
    string name, password;
    cout << "Podaj nazwe:  ";
    cin >> name;
    vector<User>::iterator koniec = listOfUser.end();
    for(vector<User>::iterator itr = listOfUser.begin(); itr != koniec; ++itr) {
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
    UsersFile file;
    vector<User>::iterator koniec = listOfUser.end();
    for(vector<User>::iterator itr = listOfUser.begin(); itr != koniec; ++itr) {
        if((*itr).getId() == idZalogowanegoUzytkownika) {
            cout << "Wprawadz nowe haslo: ";
            cin >> password;
            (*itr).changePassword(password);
            file.editRecord(*itr);
        }
    }
}
