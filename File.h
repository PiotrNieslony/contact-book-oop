#include <iostream>
#include <fstream>

using namespace std;

#ifndef FILE_H
#define FILE_H

class File {
protected:
    string fileName;
public:
    File(string name);
    bool isFileEmpty();
};

#endif
