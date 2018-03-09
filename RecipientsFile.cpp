#include "RecipientsFile.h"

PlikAdresaci::PlikAdresaci()
    :Plik("Adresaci.txt") {
    nazwaPliku = "Adresaci.txt";
}
PlikAdresaci::PlikAdresaci(string nazwa)
    :Plik(nazwa) {
    nazwaPliku = nazwa;
}

void PlikAdresaci::edytujRekord(Adresat adresat, int idZalogowanegoUzytkownika) {
    string linia;
    int idAdresata;
    size_t pozycjaSeparatora;
    string kopiaPliku = "." + nazwaPliku;
    remove(kopiaPliku.c_str());
    if((rename(nazwaPliku.c_str(), kopiaPliku.c_str())) != 0) {
        Komunikat komunikat( "Blad przy tworzeniu kopii pliku" + kopiaPliku, "krytyczny");
        return;
    }
    fstream plik;
    fstream plikKopia;
    plik.open(nazwaPliku.c_str(), ios::out | ios::app);
    plikKopia.open(kopiaPliku.c_str(),ios::in);
    if(plik.good() == false || plikKopia.good() == false) {
        Komunikat komunikat("Wystapil problem przy probie zapisu danych do pliku." + nazwaPliku, "krytyczny");
        return;
    }
    while(getline(plikKopia, linia)) {

        pozycjaSeparatora = linia.find("|");
        idAdresata = atoi(linia.substr(0, pozycjaSeparatora).c_str());
        if (idAdresata == adresat.pobierzId()) {
            plik << adresat.pobierzId() << "|";
            plik << idZalogowanegoUzytkownika << "|";
            plik << adresat.pobierzImie() << "|";
            plik << adresat.pobierzNazwisko() << "|";
            plik << adresat.pobierzTelefon() << "|";
            plik << adresat.pobierzEmail() << "|";
            plik << adresat.pobierzAdres() << "|" << endl;
        } else {
            plik << linia << endl;
        }
    }
    plik.close();
    plikKopia.close();
}

int PlikAdresaci::usunRekord(Adresat adresat, int idZalogowanegoUzytkownika) {
    string linia;
    int idAdresata;
    int idOstatniegoAdresataWPliku;
    size_t pozycjaSeparatora;
    string kopiaPliku = "." + nazwaPliku;
    remove(kopiaPliku.c_str());
    if((rename(nazwaPliku.c_str(), kopiaPliku.c_str())) != 0) {
        Komunikat komunikat( "Blad przy tworzeniu kopii pliku" + kopiaPliku, "krytyczny");
        return 0;
    }
    fstream plik;
    fstream plikKopia;
    plik.open(nazwaPliku.c_str(), ios::out | ios::app);
    plikKopia.open(kopiaPliku.c_str(),ios::in);
    if(plik.good() == false || plikKopia.good() == false) {
        Komunikat komunikat("Wystapil problem przy probie zapisu danych do pliku." + nazwaPliku, "krytyczny");
        return 0;
    }
    while(getline(plikKopia, linia)) {

        pozycjaSeparatora = linia.find("|");
        idAdresata = atoi(linia.substr(0, pozycjaSeparatora).c_str());

        if (idAdresata == adresat.pobierzId()) continue;
        else {
                idOstatniegoAdresataWPliku = idAdresata;
                plik << linia << endl;
        }
    }
    plik.close();
    plikKopia.close();
    return idOstatniegoAdresataWPliku;
}

void PlikAdresaci::dodajNowyRekord(Adresat adresat,  int idZalogowanegoUzytkownika) {
    fstream plik;
    plik.open(nazwaPliku.c_str(), ios::out | ios::app);
    if(plik.good() == false) {
        Komunikat komunikat("Wystapil problem przy probie zapisu danych do pliku." + nazwaPliku, "krytyczny");
        return ;
    }

    plik << adresat.pobierzId() << "|";
    plik << idZalogowanegoUzytkownika << "|";
    plik << adresat.pobierzImie() << "|";
    plik << adresat.pobierzNazwisko() << "|";
    plik << adresat.pobierzTelefon() << "|";
    plik << adresat.pobierzEmail() << "|";
    plik << adresat.pobierzAdres() << "|" << endl;
    plik.close();
}

int PlikAdresaci::wczytajRekordy(vector<Adresat> & adresaci, int idZalogowanegoUzytkownika) {
    string linia;
    int id;
    int idWlascicielaKontaktu;
    int idOstatniegoAdresata;
    string imie, nazwisko, telefon, email, adres;
    fstream plikAdresaci;
    size_t pozycjaZnakuOd;
    size_t pozycjaSeparatora;
    int iloscZnakow;

    plikAdresaci.open(nazwaPliku.c_str(),ios::in);
    if(plikAdresaci.good() == false) {
        Komunikat komunikat("Wystapil problem z odczytem kontaktow z pliku: " + nazwaPliku, "krytyczny");
        return 0;
    }

    while(getline(plikAdresaci, linia)) {

        pozycjaSeparatora = linia.find("|");
        id = atoi(linia.substr(0, pozycjaSeparatora).c_str());
        idOstatniegoAdresata = id;

        pozycjaZnakuOd = pozycjaSeparatora+1;
        pozycjaSeparatora = linia.find("|",pozycjaZnakuOd);
        iloscZnakow = pozycjaSeparatora - pozycjaZnakuOd;
        idWlascicielaKontaktu = atoi(linia.substr(pozycjaZnakuOd, iloscZnakow).c_str());
        if(idWlascicielaKontaktu != idZalogowanegoUzytkownika) continue;

        pozycjaZnakuOd = pozycjaSeparatora+1;
        pozycjaSeparatora = linia.find("|",pozycjaZnakuOd);
        iloscZnakow = pozycjaSeparatora - pozycjaZnakuOd;
        imie = linia.substr(pozycjaZnakuOd, iloscZnakow);

        pozycjaZnakuOd = pozycjaSeparatora+1;
        pozycjaSeparatora = linia.find("|",pozycjaZnakuOd);
        iloscZnakow = pozycjaSeparatora - pozycjaZnakuOd;
        nazwisko = linia.substr(pozycjaZnakuOd, iloscZnakow);

        pozycjaZnakuOd = pozycjaSeparatora+1;
        pozycjaSeparatora = linia.find("|",pozycjaZnakuOd);
        iloscZnakow = pozycjaSeparatora - pozycjaZnakuOd;
        telefon = linia.substr(pozycjaZnakuOd, iloscZnakow);

        pozycjaZnakuOd = pozycjaSeparatora+1;
        pozycjaSeparatora = linia.find("|",pozycjaZnakuOd);
        iloscZnakow = pozycjaSeparatora - pozycjaZnakuOd;
        email = linia.substr(pozycjaZnakuOd, iloscZnakow);

        pozycjaZnakuOd = pozycjaSeparatora+1;
        pozycjaSeparatora = linia.find("|",pozycjaZnakuOd);
        iloscZnakow = pozycjaSeparatora - pozycjaZnakuOd;
        adres = linia.substr(pozycjaZnakuOd, iloscZnakow);

        Adresat pojedynczyAdresat(id, imie, nazwisko, telefon, email, adres);

        adresaci.push_back(pojedynczyAdresat);
    }
    plikAdresaci.close();
    return idOstatniegoAdresata;
}
