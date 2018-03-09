#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include "Recipient.h"
#include "File.h"
#include "ConsoleMessage.h"

#ifndef RECIPIENTS_FILE_H
#define RECIPIENTS_FILE_H

using namespace std;

class RecipientsFile :public File {
public:
    RecipientsFile();
    RecipientsFile(string name);
    void editRecord(Recipient recipient, int idLoggedUser);
    int deleteRecord(Recipient recipient, int idLoggedUser);
    void addRecord(Recipient recipient, int idLoggedUser);
    int loadAllRecords(vector<Recipient> & recipients, int idLoggedUser);
};

#endif
