#include <iostream>
#include <fstream>

using namespace std;

#ifndef PLIK_H
#define PLIK_H

class File {
protected:
    string fileName;
public:
    File(string name);
    bool czyPlikJestPusty();
};

#endif
