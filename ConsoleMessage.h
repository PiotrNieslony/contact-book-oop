#include <iostream>
#include <windows.h>
#include <cstdio>

using namespace std;

#ifndef CONSOLE_MESSAGE_H
#define CONSOLE_MESSAGE_H

class ConsoleMessage{
    string text;
    string type;
    int timeOfDisplay;
    void generalMessage(string text, int color);
    int calculateTimeOfMessageDisplay();
    void programPause();
public:
    ConsoleMessage();
    ConsoleMessage(string text);
    ConsoleMessage(string text, string type);
    ConsoleMessage(string text, string type, int time);
    void neutral(string text);
    void warning(string text);
    void critical(string text);
    void display();
    void display(string text);
    void display(string text, string type);
    void display(string text, string type, int time);
    void setText(string text);
};

#endif
