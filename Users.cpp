#include <iostream>
#include <vector>
#include "Users.h"
#include "UsersFile.h"

using namespace std;

Users::Users(){
    UsersFile usersFile;
    usersFile.loadAllRecords(listOfUser);
}

void Users::addUser(User user) {
    listOfUser.push_back(user);
}

void Users::displayUsers() {
    system("cls");
    vector<User>::iterator vectorEnd = listOfUser.end();
    for(vector<User>::iterator itr = listOfUser.begin(); itr != vectorEnd; ++itr) {
        cout << " ~ " << (*itr).getName() << endl;
    }
    system("pause");
}

int Users::numberOfRegisteredUsers(){
    return listOfUser.size();
}

int Users::idOfLastUser() {
    if (listOfUser.size() == 0) return 0;
    vector<User>::iterator lastUser = listOfUser.end();
    --lastUser;
    return (*lastUser).getId();

}


void Users::singUp() {
    UsersFile file;
    string name, password;
    cout << "Podaj nazwe uzytkownika: ";
    cin >> name;
    vector<User>::iterator vectorEnd = listOfUser.end();
    for(vector<User>::iterator itr = listOfUser.begin(); itr != vectorEnd; ++itr) {
        if((*itr).getName() == name) {
            cout << "Taki uzytkownik juz istnieje. Wpisz inna nazwe uzytkownika: ";
            cin >> name;
            itr = listOfUser.begin();
        }
    }
    cout << "Podaj haslo: ";
    cin >> password;

    User singleUser(idOfLastUser() + 1, name, password);
    addUser(singleUser);

    UsersFile usersFile();
    file.addRecord(singleUser);
}

int Users::logIn() {
    ConsoleMessage komunikat;
    string name, password;
    cout << "Podaj nazwe:  ";
    cin >> name;
    vector<User>::iterator vectorEnd = listOfUser.end();
    for(vector<User>::iterator itr = listOfUser.begin(); itr != vectorEnd; ++itr) {
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

void Users::changePassword(int idLoggedUser) {
    string password;
    UsersFile file;
    vector<User>::iterator vectorEnd = listOfUser.end();
    for(vector<User>::iterator itr = listOfUser.begin(); itr != vectorEnd; ++itr) {
        if((*itr).getId() == idLoggedUser) {
            cout << "Wprawadz nowe haslo: ";
            cin >> password;
            (*itr).changePassword(password);
            file.editRecord(*itr);
        }
    }
}
