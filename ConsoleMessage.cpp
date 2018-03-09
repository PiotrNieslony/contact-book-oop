#include "ConsoleMessage.h"

void ConsoleMessage::generalMessage(string textToDisplay, int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);
    cout << textToDisplay << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}

int ConsoleMessage::calculateTimeOfMessageDisplay(){
    int lengthOfMessage = text.length();
    int timeOfMessageDisplay = 1200 + (lengthOfMessage *25);
    if (timeOfMessageDisplay > 5000) timeOfMessageDisplay = 5000;
    return timeOfMessageDisplay;
}

void ConsoleMessage::programPause(){
    Sleep(timeOfDisplay);
}

ConsoleMessage::ConsoleMessage(){
    type = "neutral";
    text = "message";
    timeOfDisplay = 1500;
}

ConsoleMessage::ConsoleMessage(string textToDisplay) {
    display(textToDisplay);
}

ConsoleMessage::ConsoleMessage(string textToDisplay, string sType) {
    display(textToDisplay, sType);
}

ConsoleMessage::ConsoleMessage(string textToDisplay, string sType, int sTime) {
    display(textToDisplay, sType, sTime);
}

void ConsoleMessage::neutral(string textToDisplay) {
    type = "neutral";
    text = textToDisplay;
    generalMessage(textToDisplay, 10);
    programPause();
}

void ConsoleMessage::warning(string textToDisplay) {
    type = "warning";
    text = textToDisplay;
    generalMessage(textToDisplay, 14);
    programPause();
}
void ConsoleMessage::critical(string textToDisplay) {
    type = "critical";
    text = textToDisplay;
    generalMessage(textToDisplay, 12);
    system("pause");
}

void ConsoleMessage::display() {
    if(type == "neutral")         neutral(text);
    else if(type == "warning") warning(text);
    else if(type == "neutral")    critical(text);
}

void ConsoleMessage::display(string textToDisplay){
    text = textToDisplay;
    type = "neutral";
    timeOfDisplay = calculateTimeOfMessageDisplay();
    display();
}

void ConsoleMessage::display(string textToDisplay, string sType){
    text = textToDisplay;
    type = sType;
    timeOfDisplay = calculateTimeOfMessageDisplay();
    display();
}

void ConsoleMessage::display(string textToDisplay, string sType, int sTime){
    text = textToDisplay;
    type = sType;
    timeOfDisplay = sTime;
    display();
}

void ConsoleMessage::setText(string sText){
    text = sText;
    type = "neutral";
}


