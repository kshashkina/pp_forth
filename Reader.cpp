#include "Reader.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string Reader::Read(const string& filePath) {
    ifstream file(filePath);
    if (!file) {
        throw runtime_error("File does not exist");
    }

    string content;
    char buffer[128];

    while (file.read(buffer, sizeof(buffer))) {
        content.append(buffer, file.gcount());
    }
    return content;
}
