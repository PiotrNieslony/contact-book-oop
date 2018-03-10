#include <iostream>
#include <fstream>
#include <windows.h>
#include "User.h"
#include "UsersFile.h"

using namespace std;

UsersFile::UsersFile()
    :File("Users.txt"){
    fileName = "Users.txt";
}

UsersFile::UsersFile(string name)
    :File(name){
    fileName = name;
}


void UsersFile::addRecord(User user){
    fstream file;
    file.open(fileName.c_str(), ios::out | ios::app);
    if(file.good() == false) {
        cout << "Wystapil problem przy probie zapisu danych do pliku." << endl;
        return ;
    }

    file << user.getId() << "|";
    file << user.getName() << "|";
    file << user.getPassword() << "|" << endl;
    file.close();
}

void UsersFile::editRecord(User user){
    string lineFromFile;
    int userId;
    size_t separatorPosition;
    int i = 0;
    string copyFileName = "." + fileName;
    remove(copyFileName.c_str());
    if((rename(fileName.c_str(), copyFileName.c_str())) != 0) {
        cout << ( "Blad przy tworzeniu kopii pliku" ) << endl;
        return;
    }
    fstream file;
    fstream fileCopy;
    file.open(fileName.c_str(), ios::out | ios::app);
    fileCopy.open(copyFileName.c_str(),ios::in);
    if(file.good() == false || fileCopy.good() == false) {
        cout << "Wystapil problem przy probie zapisu danych do pliku." << endl;
        return;
    }
    while(getline(fileCopy, lineFromFile)) {
        separatorPosition = lineFromFile.find("|");
        userId = atoi(lineFromFile.substr(0, separatorPosition).c_str());
        if (userId == user.getId()) {
            file << user.getId() << "|";
            file << user.getName() << "|";
            file << user.getPassword()<< "|" << endl;
        } else {
            file << lineFromFile << endl;
        }
    }
    file.close();
    fileCopy.close();
}

void UsersFile::loadAllRecords(vector<User>& listOfUser){
    string lineFromFile;
    int id;
    string name, password;
    User singleUser;
    fstream usersFile;
    size_t charPosition_from;
    size_t separatorPosition;
    int charQuantity;

    usersFile.open(fileName.c_str(),ios::in);
    if(usersFile.good() == false) {
        cout << "Wystapil problem z odczytem kontaktow z pliku: " << fileName <<  endl;
        return;
    }

    while(getline(usersFile, lineFromFile)) {

        separatorPosition = lineFromFile.find("|");
       id = atoi(lineFromFile.substr(0, separatorPosition).c_str());

        charPosition_from = separatorPosition+1;
        separatorPosition = lineFromFile.find("|",charPosition_from);
        charQuantity = separatorPosition - charPosition_from;
        name = lineFromFile.substr(charPosition_from, charQuantity);

        charPosition_from = separatorPosition+1;
        separatorPosition = lineFromFile.find("|",charPosition_from);
        charQuantity = separatorPosition - charPosition_from;
        password = lineFromFile.substr(charPosition_from, charQuantity);

        singleUser.setAll(id, name, password);
        listOfUser.push_back(singleUser);
    }
    usersFile.close();
}

