#include "RecipientsFile.h"

PlikAdresaci::PlikAdresaci()
    :File("Adresaci.txt") {
    fileName = "Adresaci.txt";
}
PlikAdresaci::PlikAdresaci(string name)
    :File(name) {
    fileName = name;
}

void PlikAdresaci::editRecord(Adresat adresat, int idLoggedUser) {
    string lineFromFile;
    int idAdresata;
    size_t separatorPositin;
    string copyFileName = "." + fileName;
    remove(copyFileName.c_str());
    if((rename(fileName.c_str(), copyFileName.c_str())) != 0) {
        ConsoleMessage message( "Blad przy tworzeniu kopii pliku" + copyFileName, "critical");
        return;
    }
    fstream file;
    fstream fileCopy;
    file.open(fileName.c_str(), ios::out | ios::app);
    fileCopy.open(copyFileName.c_str(),ios::in);
    if(file.good() == false || fileCopy.good() == false) {
        ConsoleMessage message("Wystapil problem przy probie zapisu danych do pliku." + fileName, "critical");
        return;
    }
    while(getline(fileCopy, lineFromFile)) {

        separatorPositin = lineFromFile.find("|");
        idAdresata = atoi(lineFromFile.substr(0, separatorPositin).c_str());
        if (idAdresata == adresat.getId()) {
            file << adresat.getId() << "|";
            file << idLoggedUser << "|";
            file << adresat.getFirstName() << "|";
            file << adresat.getLastName() << "|";
            file << adresat.getPhoneNumber() << "|";
            file << adresat.getEmail() << "|";
            file << adresat.getAddress() << "|" << endl;
        } else {
            file << lineFromFile << endl;
        }
    }
    file.close();
    fileCopy.close();
}

int PlikAdresaci::usunRekord(Adresat adresat, int idLoggedUser) {
    string lineFromFile;
    int idAdresata;
    int idOstatniegoAdresataWPliku;
    size_t separatorPositin;
    string copyFileName = "." + fileName;
    remove(copyFileName.c_str());
    if((rename(fileName.c_str(), copyFileName.c_str())) != 0) {
        ConsoleMessage message( "Blad przy tworzeniu kopii pliku" + copyFileName, "critical");
        return 0;
    }
    fstream file;
    fstream fileCopy;
    file.open(fileName.c_str(), ios::out | ios::app);
    fileCopy.open(copyFileName.c_str(),ios::in);
    if(file.good() == false || fileCopy.good() == false) {
        ConsoleMessage message("Wystapil problem przy probie zapisu danych do pliku." + fileName, "critical");
        return 0;
    }
    while(getline(fileCopy, lineFromFile)) {

        separatorPositin = lineFromFile.find("|");
        idAdresata = atoi(lineFromFile.substr(0, separatorPositin).c_str());

        if (idAdresata == adresat.getId()) continue;
        else {
                idOstatniegoAdresataWPliku = idAdresata;
                file << lineFromFile << endl;
        }
    }
    file.close();
    fileCopy.close();
    return idOstatniegoAdresataWPliku;
}

void PlikAdresaci::addRecord(Adresat adresat,  int idLoggedUser) {
    fstream file;
    file.open(fileName.c_str(), ios::out | ios::app);
    if(file.good() == false) {
        ConsoleMessage message("Wystapil problem przy probie zapisu danych do pliku." + fileName, "critical");
        return ;
    }

    file << adresat.getId() << "|";
    file << idLoggedUser << "|";
    file << adresat.getFirstName() << "|";
    file << adresat.getLastName() << "|";
    file << adresat.getPhoneNumber() << "|";
    file << adresat.getEmail() << "|";
    file << adresat.getAddress() << "|" << endl;
    file.close();
}

int PlikAdresaci::loadAllRecords(vector<Adresat> & adresaci, int idLoggedUser) {
    string lineFromFile;
    int id;
    int idWlascicielaKontaktu;
    int idOstatniegoAdresata;
    string firstName, lastName, phone, email, address;
    fstream plikAdresaci;
    size_t pozycjaZnakuOd;
    size_t separatorPositin;
    int charQuantity;

    plikAdresaci.open(fileName.c_str(),ios::in);
    if(plikAdresaci.good() == false) {
        ConsoleMessage message("Wystapil problem z odczytem kontaktow z pliku: " + fileName, "critical");
        return 0;
    }

    while(getline(plikAdresaci, lineFromFile)) {

        separatorPositin = lineFromFile.find("|");
        id = atoi(lineFromFile.substr(0, separatorPositin).c_str());
        idOstatniegoAdresata = id;

        pozycjaZnakuOd = separatorPositin+1;
        separatorPositin = lineFromFile.find("|",pozycjaZnakuOd);
        charQuantity = separatorPositin - pozycjaZnakuOd;
        idWlascicielaKontaktu = atoi(lineFromFile.substr(pozycjaZnakuOd, charQuantity).c_str());
        if(idWlascicielaKontaktu != idLoggedUser) continue;

        pozycjaZnakuOd = separatorPositin+1;
        separatorPositin = lineFromFile.find("|",pozycjaZnakuOd);
        charQuantity = separatorPositin - pozycjaZnakuOd;
        firstName = lineFromFile.substr(pozycjaZnakuOd, charQuantity);

        pozycjaZnakuOd = separatorPositin+1;
        separatorPositin = lineFromFile.find("|",pozycjaZnakuOd);
        charQuantity = separatorPositin - pozycjaZnakuOd;
        lastName = lineFromFile.substr(pozycjaZnakuOd, charQuantity);

        pozycjaZnakuOd = separatorPositin+1;
        separatorPositin = lineFromFile.find("|",pozycjaZnakuOd);
        charQuantity = separatorPositin - pozycjaZnakuOd;
        phone = lineFromFile.substr(pozycjaZnakuOd, charQuantity);

        pozycjaZnakuOd = separatorPositin+1;
        separatorPositin = lineFromFile.find("|",pozycjaZnakuOd);
        charQuantity = separatorPositin - pozycjaZnakuOd;
        email = lineFromFile.substr(pozycjaZnakuOd, charQuantity);

        pozycjaZnakuOd = separatorPositin+1;
        separatorPositin = lineFromFile.find("|",pozycjaZnakuOd);
        charQuantity = separatorPositin - pozycjaZnakuOd;
        address = lineFromFile.substr(pozycjaZnakuOd, charQuantity);

        Adresat pojedynczyAdresat(id, firstName, lastName, phone, email, address);

        adresaci.push_back(pojedynczyAdresat);
    }
    plikAdresaci.close();
    return idOstatniegoAdresata;
}
