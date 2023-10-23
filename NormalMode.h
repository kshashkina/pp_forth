#ifndef PP_FORTH_NORMALMODE_H
#define PP_FORTH_NORMALMODE_H


#include "Reader.h"
#include "Writer.h"
typedef string (*encrypt_ptr_t)(string, int);
typedef string (*decrypt_ptr_t)(string, int);


class NormalMode {
public:
    NormalMode(Reader& reader, Writer& writer, encrypt_ptr_t encrypt_ptr, decrypt_ptr_t decrypt_ptr);

    void HandleEncrypt();
    void HandleDecrypt();

private:
    Reader& reader;
    Writer& writer;
    encrypt_ptr_t encrypt_ptr;
    decrypt_ptr_t decrypt_ptr;
};


#endif //PP_FORTH_NORMALMODE_H
