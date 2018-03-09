#include <iostream>
#include <windows.h>
#include <cstdio>

using namespace std;

#ifndef KOMUNIKAT_H
#define KOMUNIKAT_H

class ConsoleMessage{
    string tekst;
    string typ;
    int czasWyswietlania;
    void komunikatOgolny(string tresc, int color);
    int czasWysietlaniaKomunikatu();
    void wstrzymanieDzialaniaProgramu();
public:
    ConsoleMessage();
    ConsoleMessage(string tresc);
    ConsoleMessage(string tresc, string typ);
    ConsoleMessage(string tresc, string typ, int czas);
    void neutralny(string tresc);
    void ostrzegawczy(string tresc);
    void krytyczny(string tresc);
    void wyswietl();
    void wyswietl(string tresc);
    void wyswietl(string tresc, string typ);
    void wyswietl(string tresc, string typ, int czas);
    void wczytajTekst(string tresc);
};

#endif
