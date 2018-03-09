#include "ConsolMessage.h"

void Komunikat::komunikatOgolny(string tekstDoWyswietlenia, int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
    cout << tekstDoWyswietlenia << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}

int Komunikat::czasWysietlaniaKomunikatu(){
    int dlugosKomunikatu = tekst.length();
    int czasWyswietlaniaKomunikatu = 1200 + (dlugosKomunikatu *25);
    if (czasWyswietlaniaKomunikatu > 5000) czasWyswietlaniaKomunikatu = 5000;
    return czasWyswietlaniaKomunikatu;
}

void Komunikat::wstrzymanieDzialaniaProgramu(){
    Sleep(czasWyswietlania);
}

Komunikat::Komunikat(){
    typ = "neutralny";
    tekst = "komunikat";
    czasWyswietlania = 1500;
}

Komunikat::Komunikat(string tekstDoWyswietlenia) {
    wyswietl(tekstDoWyswietlenia);
}

Komunikat::Komunikat(string tekstDoWyswietlenia, string styp) {
    wyswietl(tekstDoWyswietlenia, styp);
}

Komunikat::Komunikat(string tekstDoWyswietlenia, string styp, int sczas) {
    wyswietl(tekstDoWyswietlenia, styp, sczas);
}

void Komunikat::neutralny(string tekstDoWyswietlenia) {
    typ = "neutralny";
    tekst = tekstDoWyswietlenia;
    komunikatOgolny(tekstDoWyswietlenia, 10);
    wstrzymanieDzialaniaProgramu();
}

void Komunikat::ostrzegawczy(string tekstDoWyswietlenia) {
    typ = "ostrzegawczy";
    tekst = tekstDoWyswietlenia;
    komunikatOgolny(tekstDoWyswietlenia, 14);
    wstrzymanieDzialaniaProgramu();
}
void Komunikat::krytyczny(string tekstDoWyswietlenia) {
    typ = "krytyczny";
    tekst = tekstDoWyswietlenia;
    komunikatOgolny(tekstDoWyswietlenia, 12);
    system("pause");
}

void Komunikat::wyswietl() {
    if(typ == "neutralny")         neutralny(tekst);
    else if(typ == "ostrzegawczy") ostrzegawczy(tekst);
    else if(typ == "neutralny")    krytyczny(tekst);
}

void Komunikat::wyswietl(string tekstDoWyswietlenia){
    tekst = tekstDoWyswietlenia;
    typ = "neutralny";
    czasWyswietlania = czasWysietlaniaKomunikatu();
    wyswietl();
}

void Komunikat::wyswietl(string tekstDoWyswietlenia, string styp){
    tekst = tekstDoWyswietlenia;
    typ = styp;
    czasWyswietlania = czasWysietlaniaKomunikatu();
    wyswietl();
}

void Komunikat::wyswietl(string tekstDoWyswietlenia, string styp, int sczas){
    tekst = tekstDoWyswietlenia;
    typ = styp;
    czasWyswietlania = sczas;
    wyswietl();
}

void Komunikat::wczytajTekst(string tresc){
    tekst = tresc;
    typ = "neutralny";
}


