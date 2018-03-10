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
    size_t separatorPosition;
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

        separatorPosition = lineFromFile.find("|");
        recipientId = atoi(lineFromFile.substr(0, separatorPosition).c_str());
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
    int idOfLastRecipientInFile;
    size_t separatorPosition;
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

        separatorPosition = lineFromFile.find("|");
        recipientId = atoi(lineFromFile.substr(0, separatorPosition).c_str());

        if (recipientId == recipient.getId()) continue;
        else {
                idOfLastRecipientInFile = recipientId;
                file << lineFromFile << endl;
        }
    }
    file.close();
    fileCopy.close();
    return idOfLastRecipientInFile;
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
    int idContactOwner;
    int idOfLastRecipient;
    string firstName, lastName, phone, email, address;
    fstream recipientsFile;
    size_t charPosition_from;
    size_t separatorPosition;
    int charQuantity;

    recipientsFile.open(fileName.c_str(),ios::in);
    if(recipientsFile.good() == false) {
        ConsoleMessage message("Wystapil problem z odczytem kontaktow z pliku: " + fileName, "critical");
        return 0;
    }

    while(getline(recipientsFile, lineFromFile)) {

        separatorPosition = lineFromFile.find("|");
        id = atoi(lineFromFile.substr(0, separatorPosition).c_str());
        idOfLastRecipient = id;

        charPosition_from = separatorPosition+1;
        separatorPosition = lineFromFile.find("|",charPosition_from);
        charQuantity = separatorPosition - charPosition_from;
        idContactOwner = atoi(lineFromFile.substr(charPosition_from, charQuantity).c_str());
        if(idContactOwner != idLoggedUser) continue;

        charPosition_from = separatorPosition+1;
        separatorPosition = lineFromFile.find("|",charPosition_from);
        charQuantity = separatorPosition - charPosition_from;
        firstName = lineFromFile.substr(charPosition_from, charQuantity);

        charPosition_from = separatorPosition+1;
        separatorPosition = lineFromFile.find("|",charPosition_from);
        charQuantity = separatorPosition - charPosition_from;
        lastName = lineFromFile.substr(charPosition_from, charQuantity);

        charPosition_from = separatorPosition+1;
        separatorPosition = lineFromFile.find("|",charPosition_from);
        charQuantity = separatorPosition - charPosition_from;
        phone = lineFromFile.substr(charPosition_from, charQuantity);

        charPosition_from = separatorPosition+1;
        separatorPosition = lineFromFile.find("|",charPosition_from);
        charQuantity = separatorPosition - charPosition_from;
        email = lineFromFile.substr(charPosition_from, charQuantity);

        charPosition_from = separatorPosition+1;
        separatorPosition = lineFromFile.find("|",charPosition_from);
        charQuantity = separatorPosition - charPosition_from;
        address = lineFromFile.substr(charPosition_from, charQuantity);

        Recipient singleRecipients(id, firstName, lastName, phone, email, address);

        recipients.push_back(singleRecipients);
    }
    recipientsFile.close();
    return idOfLastRecipient;
}
