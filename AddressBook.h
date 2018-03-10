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
    bool checkIfRecipientWithThisIdExist(int id);
    AddressBook();
    AddressBook(int idLoggedUser);
    void loadRecipientsFromFile();
    void addRecipient(Recipient recipient);
    void typeRecipientData();
    int quantityOfRecipients();
    int getIdOfLoggedUser();
    int setIdOfLoggedUser(int id);
    void displayRecipients();
    void findRecipientUsingFirstName(string firstName);
    void findRecipientUsingLastName(string lastName);
    void editRecipientData();
    void removeRecipient(int id);
    void clearVector();
};
