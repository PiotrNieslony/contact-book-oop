#include <iostream>
#include <vector>
#include <windows.h>
#include <cstdio>
#include "ConsoleMessage.h"
#include "Recipient.h"
#include "RecipientsFile.h"
#include "GetInt.h"

using namespace std;

class AddressBook {
    vector<Recipient> recipients;
    int idLoggedUser;
    int idOfLastRecipientInFile;

    void displaySeparatingLine();
    void displayHeaderTable();
    void displayTableRow(Recipient recipient);
    void messageNumberOfFoundRecipients(int quantityOfFoundRecipients, string searchedValue);
public:
    bool czyAresatOTakimIDistnieje(int id);
    AddressBook();
    AddressBook(int idLoggedUser);
    void wczytajKontaktyZPliku();
    void dodajAdresata(Recipient recipient);
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
