#include <iostream>
#include <vector>
#include <windows.h>
#include <cstdio>
#include "ConsolMessage.h"
#include "Recipient.h"
#include "RecipientsFile.h"
#include "GetInt.h"

using namespace std;

class KsiazkaAdresowa {
    vector<Adresat> adresaci;
    int idZalogowanegoUzytkownika;
    int idOstatniegoAdresataWPliku;

    void wyswieltLinieOdzielajaca();
    void wyswietlNaglowekTabeli();
    void wyswietlWierszTabeli(Adresat adresat);
    void komunikatOilosciZnalezionychKontaktow(int iloscZnalezionychKontaktow, string szukanaWartosc);
public:
    bool czyAresatOTakimIDistnieje(int id);
    KsiazkaAdresowa();
    KsiazkaAdresowa(int idZalogowanegoUzytkownika);
    void wczytajKontaktyZPliku();
    void dodajAdresata(Adresat adresat);
    void wpiszAdresata();
    int iloscAdresatow();
    int pobierzIdZalogowanegoUzytkownika();
    int ustawIdZalogowanegoUzytkownika(int id);
    void wyswietlAdresatow();
    void wyszukajAdresataPoImieniu(string imie);
    void wyszukajAdresataPoNazwisku(string nazwisko);
    void edytujDaneAdresata();
    void usunAdresata(int id);
    void czyszczenieVektora();
};
