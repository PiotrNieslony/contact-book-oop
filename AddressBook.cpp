#include "AddressBook.h"

void AddressBook::displaySeparatingLine() {
    const int ILOSC_WYSIETLONYCH_ZNAKOW = 120;
    for(int i = 0; i < ILOSC_WYSIETLONYCH_ZNAKOW ; i++) cout << "_";
    cout << endl;
}

void AddressBook::displayHeaderTable() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    printf ("|%-3s|%-12s|%-12s|%-11s|%-30s|%-45s|\n",
            "id", "nr", "nazwisko", "tel", "email", "adres");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    displaySeparatingLine();
}

void AddressBook::displayTableRow(Recipient recipient) {
    printf ("|%-3i|%-12s|%-12s|%-11s|%-30s|%-45s|\n",
            recipient.getId(),
            recipient.getFirstName().c_str(),
            recipient.getLastName().c_str(),
            recipient.getPhoneNumber().c_str(),
            recipient.getEmail().c_str(),
            recipient.getAddress().c_str());
}

void AddressBook::messageNumberOfFoundRecipients(int quantityOfFoundRecipients, string searchedValue) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11); //cyjan
    switch(quantityOfFoundRecipients) {
    case 0:
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14); //zolty
        cout << endl <<"Nie znaleziono zadnego kontaktu dla nazwy: \"" << searchedValue <<"\"" << endl << endl;
        break;
    case 1:
        cout << endl <<"Znaleziono 1 kontakt" << endl  << endl;
        break;
    case 2:
    case 3:
    case 4:
        cout << endl <<"Znaleziono " << quantityOfFoundRecipients << " kontakty" << endl << endl;
        break;
    default:
        cout << endl <<"Znaleziono " << quantityOfFoundRecipients << " kontaktow" << endl << endl;
        break;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15); // bialy
}

bool AddressBook::czyAresatOTakimIDistnieje(int id) {
    vector<Recipient>::iterator vectorEnd = recipients.end();
    for(vector<Recipient>::iterator itr = recipients.begin(); itr != vectorEnd; ++itr) {
        if((*itr).getId() == id) return true;
    }
    return false;
}

AddressBook::AddressBook() {

}

AddressBook::AddressBook(int id) {
    idLoggedUser = id;
    RecipientsFile recipientsFile;
    idOfLastRecipientInFile = recipientsFile.loadAllRecords(recipients, idLoggedUser);
}

void AddressBook::wczytajKontaktyZPliku() {
    RecipientsFile recipientsFile;
    if(recipientsFile.isFileEmpty()) idOfLastRecipientInFile = 0;
    else idOfLastRecipientInFile = recipientsFile.loadAllRecords(recipients, idLoggedUser);
}

void AddressBook::dodajAdresata(Recipient recipient) {
    recipients.push_back(recipient);
    RecipientsFile recipientsFile;
    recipientsFile.addRecord(recipient, idLoggedUser);
}

void AddressBook::wpiszAdresata() {
    int id;
    string firstName, lastName, phone, email, address;

    system("cls");
    id = idOfLastRecipientInFile + 1;
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

    Recipient recipient(id, firstName, lastName, phone, email, address);
    dodajAdresata(recipient);
    idOfLastRecipientInFile++;
    ConsoleMessage message("Super, dodales nowe dane kontaktowe.");
}

int AddressBook::iloscAdresatow() {
    return recipients.size();
}

int AddressBook::pobierzIdZalogowanegoUzytkownika() {
    return idLoggedUser;
}

int AddressBook::ustawIdZalogowanegoUzytkownika(int id) {
    idLoggedUser = id;
}

void AddressBook::wyswietlAdresatow() {
    displayHeaderTable();
    vector<Recipient>::iterator vectorEnd = recipients.end();
    for(vector<Recipient>::iterator itr = recipients.begin(); itr != vectorEnd; ++itr) {
        displayTableRow(*itr);
    }

    displaySeparatingLine();
}

void AddressBook::wyszukajAdresataPoImieniu(string searchedValue) {
    int quantityOfFoundRecipients = 0;
    displayHeaderTable();
    vector<Recipient>::iterator vectorEnd = recipients.end();
    for(vector<Recipient>::iterator itr = recipients.begin(); itr != vectorEnd; ++itr) {
        if((*itr).getFirstName() == searchedValue) {
            displayTableRow(*itr);
            quantityOfFoundRecipients++;
        }
    }
    displaySeparatingLine();
    messageNumberOfFoundRecipients(quantityOfFoundRecipients, searchedValue);
}

void AddressBook::wyszukajAdresataPoNazwisku(string searchedValue) {
    int quantityOfFoundRecipients = 0;
    displayHeaderTable();
    vector<Recipient>::iterator vectorEnd = recipients.end();
    for(vector<Recipient>::iterator itr = recipients.begin(); itr != vectorEnd; ++itr) {
        if((*itr).getLastName() == searchedValue) {
            displayTableRow(*itr);
            quantityOfFoundRecipients++;
        }
    }
    displaySeparatingLine();
    messageNumberOfFoundRecipients(quantityOfFoundRecipients, searchedValue);
}

void AddressBook::edytujDaneAdresata() {
    int id;
    char wybor;
    string firstName, lastName, phone, email, address;
    ConsoleMessage message;
    message.setText("Dane zostaly zmienione.");
    RecipientsFile file;
    PobierzLiczbeCalkowita pobierzLiczbe;

    system("cls");
    cout << "EDYCJA:" << endl;
    cout << "Podaj ID kontaktu ktory chcesz edytowac: ";
    id = pobierzLiczbe.wprowadzWartosc();
    vector<Recipient>::iterator vectorEnd = recipients.end();
    for(vector<Recipient>::iterator itr = recipients.begin(); itr != vectorEnd; ++itr) {
        if((*itr).getId() == id) {

            firstName = (*itr).getFirstName();
            lastName = (*itr).getLastName();
            phone = (*itr).getPhoneNumber();
            email = (*itr).getEmail();
            address = (*itr).getAddress();

            displayHeaderTable();
            displayTableRow(*itr);
            displaySeparatingLine();

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

void AddressBook::usunAdresata(int id) {
    char wybor;
    vector<Recipient>::iterator vectorEnd = recipients.end();
    for(vector<Recipient>::iterator itr = recipients.begin(); itr != vectorEnd; ++itr) {
        if((*itr).getId() == id) {
            displayHeaderTable();
            displayTableRow(*itr);
            displaySeparatingLine();

            cout << endl << "Czy napewno chcesz usunc wybrany kontakt?(T - tak, N - nie): ";
            cin >> wybor;
            if(wybor  == 't' || wybor  == 'T') {
                RecipientsFile file;
                idOfLastRecipientInFile = file.deleteRecord(*itr, idLoggedUser);
                recipients.erase(itr);
                if(file.isFileEmpty()) idOfLastRecipientInFile = 0;
                ConsoleMessage message("Kontakt zostal usuniety.");
                return;
            } else {
                return;
            }
        }
    }
    ConsoleMessage message("Kontakt o takim ID nie istnieje", "warning");
}

void AddressBook::czyszczenieVektora() {
    recipients.clear();
}
