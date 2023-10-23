#ifndef PP_FORTH_READER_H
#define PP_FORTH_READER_H
#include <iostream>
#include <fstream>
#include <string>

using namespace std;



class Reader{
public:
    string Read(const string& filePath);
};


#endif //PP_FORTH_READER_H
