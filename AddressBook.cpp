#include "AddressBook.h"

void KsiazkaAdresowa::wyswieltLinieOdzielajaca() {
    const int ILOSC_WYSIETLONYCH_ZNAKOW = 120;
    for(int i = 0; i < ILOSC_WYSIETLONYCH_ZNAKOW ; i++) cout << "_";
    cout << endl;
}

void KsiazkaAdresowa::wyswietlNaglowekTabeli() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    printf ("|%-3s|%-12s|%-12s|%-11s|%-30s|%-45s|\n",
            "id", "nr", "nazwisko", "tel", "email", "adres");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    wyswieltLinieOdzielajaca();
}

void KsiazkaAdresowa::wyswietlWierszTabeli(Adresat adresat) {
    printf ("|%-3i|%-12s|%-12s|%-11s|%-30s|%-45s|\n",
            adresat.getId(),
            adresat.getFirstName().c_str(),
            adresat.getLastName().c_str(),
            adresat.getPhoneNumber().c_str(),
            adresat.getEmail().c_str(),
            adresat.getAddress().c_str());
}

void KsiazkaAdresowa::komunikatOilosciZnalezionychKontaktow(int iloscZnalezionychKontaktow, string szukanaWartosc) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11); //cyjan
    switch(iloscZnalezionychKontaktow) {
    case 0:
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14); //zolty
        cout << endl <<"Nie znaleziono zadnego kontaktu dla nazwy: \"" << szukanaWartosc <<"\"" << endl << endl;
        break;
    case 1:
        cout << endl <<"Znaleziono 1 kontakt" << endl  << endl;
        break;
    case 2:
    case 3:
    case 4:
        cout << endl <<"Znaleziono " << iloscZnalezionychKontaktow << " kontakty" << endl << endl;
        break;
    default:
        cout << endl <<"Znaleziono " << iloscZnalezionychKontaktow << " kontaktow" << endl << endl;
        break;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15); // bialy
}

bool KsiazkaAdresowa::czyAresatOTakimIDistnieje(int id) {
    vector<Adresat>::iterator vectorEnd = adresaci.end();
    for(vector<Adresat>::iterator itr = adresaci.begin(); itr != vectorEnd; ++itr) {
        if((*itr).getId() == id) return true;
    }
    return false;
}

KsiazkaAdresowa::KsiazkaAdresowa() {

}

KsiazkaAdresowa::KsiazkaAdresowa(int id) {
    idLoggedUser = id;
    PlikAdresaci plikAdresaci;
    idOstatniegoAdresataWPliku = plikAdresaci.loadAllRecords(adresaci, idLoggedUser);
}

void KsiazkaAdresowa::wczytajKontaktyZPliku() {
    PlikAdresaci plikAdresaci;
    if(plikAdresaci.isFileEmpty()) idOstatniegoAdresataWPliku = 0;
    else idOstatniegoAdresataWPliku = plikAdresaci.loadAllRecords(adresaci, idLoggedUser);
}

void KsiazkaAdresowa::dodajAdresata(Adresat adresat) {
    adresaci.push_back(adresat);
    PlikAdresaci plikAdresaci;
    plikAdresaci.addRecord(adresat, idLoggedUser);
}

void KsiazkaAdresowa::wpiszAdresata() {
    int id;
    string firstName, lastName, phone, email, address;

    system("cls");
    id = idOstatniegoAdresataWPliku + 1;
    cout << "Podaj imie: ";
    cin >> firstName;
    cout << "Podaj nazwisko: ";
    cin >> lastName;
    cout << "Podaj nr. telefonu: ";
    cin.sync();
    getline(cin, phone);
    cout << "Podaj adres email: ";
    cin >> email;
    cout << "Podaj adres: ";
    cin.sync();
    getline(cin, address);

    Adresat adresat(id, firstName, lastName, phone, email, address);
    dodajAdresata(adresat);
    idOstatniegoAdresataWPliku++;
    ConsoleMessage message("Super, dodales nowe dane kontaktowe.");
}

int KsiazkaAdresowa::iloscAdresatow() {
    return adresaci.size();
}

int KsiazkaAdresowa::pobierzIdZalogowanegoUzytkownika() {
    return idLoggedUser;
}

int KsiazkaAdresowa::ustawIdZalogowanegoUzytkownika(int id) {
    idLoggedUser = id;
}

void KsiazkaAdresowa::wyswietlAdresatow() {
    wyswietlNaglowekTabeli();
    vector<Adresat>::iterator vectorEnd = adresaci.end();
    for(vector<Adresat>::iterator itr = adresaci.begin(); itr != vectorEnd; ++itr) {
        wyswietlWierszTabeli(*itr);
    }

    wyswieltLinieOdzielajaca();
}

void KsiazkaAdresowa::wyszukajAdresataPoImieniu(string szukanaWartosc) {
    int iloscZnalezionychKontaktow = 0;
    wyswietlNaglowekTabeli();
    vector<Adresat>::iterator vectorEnd = adresaci.end();
    for(vector<Adresat>::iterator itr = adresaci.begin(); itr != vectorEnd; ++itr) {
        if((*itr).getFirstName() == szukanaWartosc) {
            wyswietlWierszTabeli(*itr);
            iloscZnalezionychKontaktow++;
        }
    }
    wyswieltLinieOdzielajaca();
    komunikatOilosciZnalezionychKontaktow(iloscZnalezionychKontaktow, szukanaWartosc);
}

void KsiazkaAdresowa::wyszukajAdresataPoNazwisku(string szukanaWartosc) {
    int iloscZnalezionychKontaktow = 0;
    wyswietlNaglowekTabeli();
    vector<Adresat>::iterator vectorEnd = adresaci.end();
    for(vector<Adresat>::iterator itr = adresaci.begin(); itr != vectorEnd; ++itr) {
        if((*itr).getLastName() == szukanaWartosc) {
            wyswietlWierszTabeli(*itr);
            iloscZnalezionychKontaktow++;
        }
    }
    wyswieltLinieOdzielajaca();
    komunikatOilosciZnalezionychKontaktow(iloscZnalezionychKontaktow, szukanaWartosc);
}

void KsiazkaAdresowa::edytujDaneAdresata() {
    int id;
    char wybor;
    string firstName, lastName, phone, email, address;
    ConsoleMessage message;
    message.setText("Dane zostaly zmienione.");
    PlikAdresaci file;
    PobierzLiczbeCalkowita pobierzLiczbe;

    system("cls");
    cout << "EDYCJA:" << endl;
    cout << "Podaj ID kontaktu ktory chcesz edytowac: ";
    id = pobierzLiczbe.wprowadzWartosc();
    vector<Adresat>::iterator vectorEnd = adresaci.end();
    for(vector<Adresat>::iterator itr = adresaci.begin(); itr != vectorEnd; ++itr) {
        if((*itr).getId() == id) {

            firstName = (*itr).getFirstName();
            lastName = (*itr).getLastName();
            phone = (*itr).getPhoneNumber();
            email = (*itr).getEmail();
            address = (*itr).getAddress();

            wyswietlNaglowekTabeli();
            wyswietlWierszTabeli(*itr);
            wyswieltLinieOdzielajaca();

            cout << "EDYCJA: " << endl << endl;
            cout << "Co chcesz edytowac?: " << endl;
            cout << "1. Imie" << endl;
            cout << "2. Nazwisko" << endl;
            cout << "3. Telefon" << endl;
            cout << "4. Email" << endl;
            cout << "5. Adres" << endl;
            cout << "6. Wszystko" << endl;
            cout << "9. Nic" << endl << endl;

            while(true) {
                cout << "wybor: ";
                cin.sync();
                cin >> wybor;


                switch(wybor) {
                case '1':
                    cout << "Wprowadz imie: ";
                    cin >> firstName;
                    (*itr).setAll(id, firstName, lastName, phone, email, address);
                    file.editRecord(*itr, idLoggedUser);
                    message.display();
                    return;
                case '2':
                    cout << "Wprowadz nazwisko: ";
                    cin >> lastName;
                    (*itr).setAll(id, firstName, lastName, phone, email, address);
                    file.editRecord(*itr, idLoggedUser);
                    message.display();
                    return;
                case 3:
                    cout << "Wprowadz telefon: ";
                    cin.sync();
                    getline(cin, phone);
                    (*itr).setAll(id, firstName, lastName, phone, email, address);
                    file.editRecord(*itr, idLoggedUser);
                    message.display();
                    return;
                case '4':
                    cout << "Wprowadz emial: ";
                    cin >> email;
                    (*itr).setAll(id, firstName, lastName, phone, email, address);
                    file.editRecord(*itr, idLoggedUser);
                    message.display();
                    return;
                case '5':
                    cout << "Wprowadz adres: ";
                    cin.sync();
                    getline(cin, address);
                    (*itr).setAll(id, firstName, lastName, phone, email, address);
                    file.editRecord(*itr, idLoggedUser);
                    message.display();
                    return;
                case '6':
                    cout << "Wprowadz imie: ";
                    cin >> firstName;
                    cout << "Wprowadz nazwisko: ";
                    cin >> lastName;
                    cout << "Wprowadz telefon: ";
                    cin.sync();
                    getline(cin, phone);
                    cout << "Wprowadz emial: ";
                    cin >> email;
                    cout << "Wprowadz adres: ";
                    cin.sync();
                    getline(cin,address);
                    (*itr).setAll(id, firstName, lastName, phone, email, address);
                    file.editRecord(*itr, idLoggedUser);
                    message.display();

                    return;
                case '9':
                    return;
                default:
                    message.display("Nie ma takiej opcji w menu", "warning", 0);
                }
            }
        }
    }
    message.neutral("Kontakt o takim ID nie istnieje. W celu sprawdzenia ID wyszukaj lub wyswietl wszystkie kontakty");
}

void KsiazkaAdresowa::usunAdresata(int id) {
    char wybor;
    vector<Adresat>::iterator vectorEnd = adresaci.end();
    for(vector<Adresat>::iterator itr = adresaci.begin(); itr != vectorEnd; ++itr) {
        if((*itr).getId() == id) {
            wyswietlNaglowekTabeli();
            wyswietlWierszTabeli(*itr);
            wyswieltLinieOdzielajaca();

            cout << endl << "Czy napewno chcesz usunc wybrany kontakt?(T - tak, N - nie): ";
            cin >> wybor;
            if(wybor  == 't' || wybor  == 'T') {
                PlikAdresaci file;
                idOstatniegoAdresataWPliku = file.usunRekord(*itr, idLoggedUser);
                adresaci.erase(itr);
                if(file.isFileEmpty()) idOstatniegoAdresataWPliku = 0;
                ConsoleMessage message("Kontakt zostal usuniety.");
                return;
            } else {
                return;
            }
        }
    }
    ConsoleMessage message("Kontakt o takim ID nie istnieje", "warning");
}

void KsiazkaAdresowa::czyszczenieVektora() {
    adresaci.clear();
}
