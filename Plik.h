#include <iostream>
#include <fstream>

using namespace std;

#ifndef PLIK_H
#define PLIK_H

class Plik {
protected:
    string nazwaPliku;
public:
    Plik(string nazwa);
    bool czyPlikJestPusty();
};

#endif
