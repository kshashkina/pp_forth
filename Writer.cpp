#include "Writer.h"


void Writer::Write(const string& filePath, const string& text) {
    ifstream fileCheck(filePath);
    if (fileCheck) {
        throw runtime_error("File already exists");
    }

    ofstream file(filePath);
    if (!file) {
        throw runtime_error("Unable to create the file");
    }

    file << text;
    file.close();
}