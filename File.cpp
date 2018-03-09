#include <iostream>
#include <fstream>
#include "File.h"

using namespace std;

Plik::Plik(string name) {
    nazwaPliku = name;
}

bool Plik::czyPlikJestPusty() {
    ifstream plik (nazwaPliku.c_str(), ifstream::in);
    return plik.peek() == ifstream::traits_type::eof();
}

