#include <iostream>
#include <fstream>
#include "File.h"

using namespace std;

File::File(string name) {
    fileName = name;
}

bool File::isFileEmpty() {
    ifstream file (fileName.c_str(), ifstream::in);
    return file.peek() == ifstream::traits_type::eof();
}

