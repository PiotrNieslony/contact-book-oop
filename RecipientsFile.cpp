#include "RecipientsFile.h"

RecipientsFile::RecipientsFile()
    :File("Recipients.txt") {
    fileName = "Recipients.txt";
}
RecipientsFile::RecipientsFile(string name)
    :File(name) {
    fileName = name;
}

void RecipientsFile::editRecord(Recipient recipient, int idLoggedUser) {
    string lineFromFile;
    int recipientId;
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
        recipientId = atoi(lineFromFile.substr(0, separatorPositin).c_str());
        if (recipientId == recipient.getId()) {
            file << recipient.getId() << "|";
            file << idLoggedUser << "|";
            file << recipient.getFirstName() << "|";
            file << recipient.getLastName() << "|";
            file << recipient.getPhoneNumber() << "|";
            file << recipient.getEmail() << "|";
            file << recipient.getAddress() << "|" << endl;
        } else {
            file << lineFromFile << endl;
        }
    }
    file.close();
    fileCopy.close();
}

int RecipientsFile::deleteRecord(Recipient recipient, int idLoggedUser) {
    string lineFromFile;
    int recipientId;
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
        recipientId = atoi(lineFromFile.substr(0, separatorPositin).c_str());

        if (recipientId == recipient.getId()) continue;
        else {
                idOstatniegoAdresataWPliku = recipientId;
                file << lineFromFile << endl;
        }
    }
    file.close();
    fileCopy.close();
    return idOstatniegoAdresataWPliku;
}

void RecipientsFile::addRecord(Recipient recipient,  int idLoggedUser) {
    fstream file;
    file.open(fileName.c_str(), ios::out | ios::app);
    if(file.good() == false) {
        ConsoleMessage message("Wystapil problem przy probie zapisu danych do pliku." + fileName, "critical");
        return ;
    }

    file << recipient.getId() << "|";
    file << idLoggedUser << "|";
    file << recipient.getFirstName() << "|";
    file << recipient.getLastName() << "|";
    file << recipient.getPhoneNumber() << "|";
    file << recipient.getEmail() << "|";
    file << recipient.getAddress() << "|" << endl;
    file.close();
}

int RecipientsFile::loadAllRecords(vector<Recipient> & recipients, int idLoggedUser) {
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

        Recipient pojedynczyAdresat(id, firstName, lastName, phone, email, address);

        recipients.push_back(pojedynczyAdresat);
    }
    plikAdresaci.close();
    return idOstatniegoAdresata;
}
