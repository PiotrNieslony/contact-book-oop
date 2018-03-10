#include "GetInt.h"

int GetInt::enterValue() {
    cin >> intNumber;
    while (cin.fail()) {
        cin.clear();
        cin.ignore();
        cin.sync();
        ConsoleMessage message("Wprowadziles niepoprawna wartosc. ", "warning", 0);
        cout  << "Wprowadz nowa wartosc (liczbe): ";
        cin >> intNumber;
    }
    return intNumber;
}

GetInt::GetInt() {
    intNumber = 0;
}
