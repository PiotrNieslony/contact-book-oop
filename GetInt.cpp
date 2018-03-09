#include "GetInt.h"

int PobierzLiczbeCalkowita::wprowadzWartosc() {
    cin >> liczbaCalkowita;
    while (cin.fail()) {
        cin.clear();
        cin.ignore();
        cin.sync();
        ConsoleMessage message("Wprowadziles niepoprawna wartosc. ", "warning", 0);
        cout  << "Wprowadz nowa wartosc (liczbe): ";
        cin >> liczbaCalkowita;
    }
    return liczbaCalkowita;
}

PobierzLiczbeCalkowita::PobierzLiczbeCalkowita() {
    liczbaCalkowita = 0;
}
