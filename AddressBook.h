#include <iostream>
#include <vector>
#include <windows.h>
#include <cstdio>
#include "ConsoleMessage.h"
#include "Recipient.h"
#include "RecipientsFile.h"
#include "GetInt.h"

using namespace std;

class KsiazkaAdresowa {
    vector<Adresat> adresaci;
    int idLoggedUser;
    int idOstatniegoAdresataWPliku;

    void wyswieltLinieOdzielajaca();
    void wyswietlNaglowekTabeli();
    void wyswietlWierszTabeli(Adresat adresat);
    void komunikatOilosciZnalezionychKontaktow(int iloscZnalezionychKontaktow, string szukanaWartosc);
public:
    bool czyAresatOTakimIDistnieje(int id);
    KsiazkaAdresowa();
    KsiazkaAdresowa(int idLoggedUser);
    void wczytajKontaktyZPliku();
    void dodajAdresata(Adresat adresat);
    void wpiszAdresata();
    int iloscAdresatow();
    int pobierzIdZalogowanegoUzytkownika();
    int ustawIdZalogowanegoUzytkownika(int id);
    void wyswietlAdresatow();
    void wyszukajAdresataPoImieniu(string firstName);
    void wyszukajAdresataPoNazwisku(string lastName);
    void edytujDaneAdresata();
    void usunAdresata(int id);
    void czyszczenieVektora();
};
