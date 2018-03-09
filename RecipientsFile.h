#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include "Recipient.h"
#include "File.h"
#include "ConsolMessage.h"

#ifndef RECIPIENTS_FILE_H
#define RECIPIENTS_FILE_H

using namespace std;

class PlikAdresaci :public File {
public:
    PlikAdresaci();
    PlikAdresaci(string name);
    void editRecord(Adresat adresat, int idLoggedUser);
    int usunRekord(Adresat adresat, int idLoggedUser);
    void addRecord(Adresat adresat, int idLoggedUser);
    int loadAllRecords(vector<Adresat> & adresaci, int idLoggedUser);
};

#endif
