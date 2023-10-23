#ifndef PP_FORTH_WRITER_H
#define PP_FORTH_WRITER_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class Writer {
public:
    void Write(const string& filePath, const string& text);

};


#endif //PP_FORTH_WRITER_H
