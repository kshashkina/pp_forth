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

    const size_t chunkSize = 128;
    for (size_t i = 0; i < text.size(); i += chunkSize) {
        file.write(text.c_str() + i, min(chunkSize, text.size() - i));
    }

    file.close();
}