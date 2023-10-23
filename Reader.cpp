#include "Reader.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string Reader::Read(const string& filePath)  {
    ifstream file(filePath);
    if (!file) {
        throw runtime_error("File does not exist");
    }
    string content;
    string line;
    while (getline(file, line)) {
        content += line + "\n";
    }
    return content;
}