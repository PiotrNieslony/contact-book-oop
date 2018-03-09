#include "RecipientsFile.h"

PlikAdresaci::PlikAdresaci()
    :File("Adresaci.txt") {
    fileName = "Adresaci.txt";
}
PlikAdresaci::PlikAdresaci(string name)
    :File(name) {
    fileName = name;
}

void PlikAdresaci::editRecord(Adresat adresat, int idZalogowanegoUzytkownika) {
    string lineFromFile;
    int idAdresata;
    size_t separatorPositin;
    string copyFileName = "." + fileName;
    remove(copyFileName.c_str());
    if((rename(fileName.c_str(), copyFileName.c_str())) != 0) {
        Komunikat komunikat( "Blad przy tworzeniu kopii pliku" + copyFileName, "krytyczny");
        return;
    }
    fstream file;
    fstream fileCopy;
    file.open(fileName.c_str(), ios::out | ios::app);
    fileCopy.open(copyFileName.c_str(),ios::in);
    if(file.good() == false || fileCopy.good() == false) {
        Komunikat komunikat("Wystapil problem przy probie zapisu danych do pliku." + fileName, "krytyczny");
        return;
    }
    while(getline(fileCopy, lineFromFile)) {

        separatorPositin = lineFromFile.find("|");
        idAdresata = atoi(lineFromFile.substr(0, separatorPositin).c_str());
        if (idAdresata == adresat.getId()) {
            file << adresat.getId() << "|";
            file << idZalogowanegoUzytkownika << "|";
            file << adresat.pobierzImie() << "|";
            file << adresat.pobierzNazwisko() << "|";
            file << adresat.pobierzTelefon() << "|";
            file << adresat.pobierzEmail() << "|";
            file << adresat.pobierzAdres() << "|" << endl;
        } else {
            file << lineFromFile << endl;
        }
    }
    file.close();
    fileCopy.close();
}

int PlikAdresaci::usunRekord(Adresat adresat, int idZalogowanegoUzytkownika) {
    string lineFromFile;
    int idAdresata;
    int idOstatniegoAdresataWPliku;
    size_t separatorPositin;
    string copyFileName = "." + fileName;
    remove(copyFileName.c_str());
    if((rename(fileName.c_str(), copyFileName.c_str())) != 0) {
        Komunikat komunikat( "Blad przy tworzeniu kopii pliku" + copyFileName, "krytyczny");
        return 0;
    }
    fstream file;
    fstream fileCopy;
    file.open(fileName.c_str(), ios::out | ios::app);
    fileCopy.open(copyFileName.c_str(),ios::in);
    if(file.good() == false || fileCopy.good() == false) {
        Komunikat komunikat("Wystapil problem przy probie zapisu danych do pliku." + fileName, "krytyczny");
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

void PlikAdresaci::addRecord(Adresat adresat,  int idZalogowanegoUzytkownika) {
    fstream file;
    file.open(fileName.c_str(), ios::out | ios::app);
    if(file.good() == false) {
        Komunikat komunikat("Wystapil problem przy probie zapisu danych do pliku." + fileName, "krytyczny");
        return ;
    }

    file << adresat.getId() << "|";
    file << idZalogowanegoUzytkownika << "|";
    file << adresat.pobierzImie() << "|";
    file << adresat.pobierzNazwisko() << "|";
    file << adresat.pobierzTelefon() << "|";
    file << adresat.pobierzEmail() << "|";
    file << adresat.pobierzAdres() << "|" << endl;
    file.close();
}

int PlikAdresaci::loadAllRecords(vector<Adresat> & adresaci, int idZalogowanegoUzytkownika) {
    string lineFromFile;
    int id;
    int idWlascicielaKontaktu;
    int idOstatniegoAdresata;
    string imie, nazwisko, telefon, email, adres;
    fstream plikAdresaci;
    size_t pozycjaZnakuOd;
    size_t separatorPositin;
    int charQuantity;

    plikAdresaci.open(fileName.c_str(),ios::in);
    if(plikAdresaci.good() == false) {
        Komunikat komunikat("Wystapil problem z odczytem kontaktow z pliku: " + fileName, "krytyczny");
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
        if(idWlascicielaKontaktu != idZalogowanegoUzytkownika) continue;

        pozycjaZnakuOd = separatorPositin+1;
        separatorPositin = lineFromFile.find("|",pozycjaZnakuOd);
        charQuantity = separatorPositin - pozycjaZnakuOd;
        imie = lineFromFile.substr(pozycjaZnakuOd, charQuantity);

        pozycjaZnakuOd = separatorPositin+1;
        separatorPositin = lineFromFile.find("|",pozycjaZnakuOd);
        charQuantity = separatorPositin - pozycjaZnakuOd;
        nazwisko = lineFromFile.substr(pozycjaZnakuOd, charQuantity);

        pozycjaZnakuOd = separatorPositin+1;
        separatorPositin = lineFromFile.find("|",pozycjaZnakuOd);
        charQuantity = separatorPositin - pozycjaZnakuOd;
        telefon = lineFromFile.substr(pozycjaZnakuOd, charQuantity);

        pozycjaZnakuOd = separatorPositin+1;
        separatorPositin = lineFromFile.find("|",pozycjaZnakuOd);
        charQuantity = separatorPositin - pozycjaZnakuOd;
        email = lineFromFile.substr(pozycjaZnakuOd, charQuantity);

        pozycjaZnakuOd = separatorPositin+1;
        separatorPositin = lineFromFile.find("|",pozycjaZnakuOd);
        charQuantity = separatorPositin - pozycjaZnakuOd;
        adres = lineFromFile.substr(pozycjaZnakuOd, charQuantity);

        Adresat pojedynczyAdresat(id, imie, nazwisko, telefon, email, adres);

        adresaci.push_back(pojedynczyAdresat);
    }
    plikAdresaci.close();
    return idOstatniegoAdresata;
}
