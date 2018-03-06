#include <iostream>
#include <fstream>
#include "Plik.h"

using namespace std;

Plik::Plik(string nazwa) {
    nazwaPliku = nazwa;
}

bool Plik::czyPlikJestPusty() {
    ifstream plik (nazwaPliku.c_str(), ifstream::in);
    return plik.peek() == ifstream::traits_type::eof();
}

