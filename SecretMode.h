#ifndef PP_FORTH_SECRETMODE_H
#define PP_FORTH_SECRETMODE_H

#include "Reader.h"
#include "Writer.h"
typedef string (*encrypt_ptr_t)(string, int);


class SecretMode {
public:
    SecretMode(Reader& reader, Writer& writer, encrypt_ptr_t encrypt_ptr);

    void HandleSecretEncrypt();

private:
    Reader& reader;
    Writer& writer;
    encrypt_ptr_t encrypt_ptr;
};

#endif //PP_FORTH_SECRETMODE_H
