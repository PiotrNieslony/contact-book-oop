#include "ConsolMessage.h"

void ConsoleMessage::komunikatOgolny(string tekstDoWyswietlenia, int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
    cout << tekstDoWyswietlenia << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}

int ConsoleMessage::czasWysietlaniaKomunikatu(){
    int dlugosKomunikatu = tekst.length();
    int czasWyswietlaniaKomunikatu = 1200 + (dlugosKomunikatu *25);
    if (czasWyswietlaniaKomunikatu > 5000) czasWyswietlaniaKomunikatu = 5000;
    return czasWyswietlaniaKomunikatu;
}

void ConsoleMessage::wstrzymanieDzialaniaProgramu(){
    Sleep(czasWyswietlania);
}

ConsoleMessage::ConsoleMessage(){
    typ = "neutralny";
    tekst = "komunikat";
    czasWyswietlania = 1500;
}

ConsoleMessage::ConsoleMessage(string tekstDoWyswietlenia) {
    wyswietl(tekstDoWyswietlenia);
}

ConsoleMessage::ConsoleMessage(string tekstDoWyswietlenia, string styp) {
    wyswietl(tekstDoWyswietlenia, styp);
}

ConsoleMessage::ConsoleMessage(string tekstDoWyswietlenia, string styp, int sczas) {
    wyswietl(tekstDoWyswietlenia, styp, sczas);
}

void ConsoleMessage::neutralny(string tekstDoWyswietlenia) {
    typ = "neutralny";
    tekst = tekstDoWyswietlenia;
    komunikatOgolny(tekstDoWyswietlenia, 10);
    wstrzymanieDzialaniaProgramu();
}

void ConsoleMessage::ostrzegawczy(string tekstDoWyswietlenia) {
    typ = "ostrzegawczy";
    tekst = tekstDoWyswietlenia;
    komunikatOgolny(tekstDoWyswietlenia, 14);
    wstrzymanieDzialaniaProgramu();
}
void ConsoleMessage::krytyczny(string tekstDoWyswietlenia) {
    typ = "krytyczny";
    tekst = tekstDoWyswietlenia;
    komunikatOgolny(tekstDoWyswietlenia, 12);
    system("pause");
}

void ConsoleMessage::wyswietl() {
    if(typ == "neutralny")         neutralny(tekst);
    else if(typ == "ostrzegawczy") ostrzegawczy(tekst);
    else if(typ == "neutralny")    krytyczny(tekst);
}

void ConsoleMessage::wyswietl(string tekstDoWyswietlenia){
    tekst = tekstDoWyswietlenia;
    typ = "neutralny";
    czasWyswietlania = czasWysietlaniaKomunikatu();
    wyswietl();
}

void ConsoleMessage::wyswietl(string tekstDoWyswietlenia, string styp){
    tekst = tekstDoWyswietlenia;
    typ = styp;
    czasWyswietlania = czasWysietlaniaKomunikatu();
    wyswietl();
}

void ConsoleMessage::wyswietl(string tekstDoWyswietlenia, string styp, int sczas){
    tekst = tekstDoWyswietlenia;
    typ = styp;
    czasWyswietlania = sczas;
    wyswietl();
}

void ConsoleMessage::wczytajTekst(string tresc){
    tekst = tresc;
    typ = "neutralny";
}


