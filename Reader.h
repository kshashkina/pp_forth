#ifndef PP_FORTH_READER_H
#define PP_FORTH_READER_H
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class IReader {
public:
    virtual std::string Read(const std::string& filePath) = 0;
};

class Reader : public IReader{
public:
    string Read(const string& filePath);
};


#endif //PP_FORTH_READER_H
