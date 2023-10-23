#include <iostream>
#include <string>
#include <Windows.h>
#include "Writer.h"
#include "Reader.h"
#include "NormalMode.h"
#include "SecretMode.h"

using namespace std;

typedef string (*encrypt_ptr_t)(string, int);
typedef string (*decrypt_ptr_t)(string, int);


int main() {
    int number;
    HMODULE handle = LoadLibrary(TEXT("libCaesar.dll"));

    if (handle == nullptr) {
        cout << "DLL not found" << endl;
        return 1;
    }

    encrypt_ptr_t encrypt_ptr = (encrypt_ptr_t)GetProcAddress(handle, "encrypt");
    decrypt_ptr_t decrypt_ptr = (decrypt_ptr_t)GetProcAddress(handle, "decrypt");

    if (encrypt_ptr == nullptr || decrypt_ptr == nullptr) {
        cout << "Functions not found in DLL" << endl;
        return 1;
    }

    Reader reader;
    Writer writer;

    NormalMode normalMode(reader, writer, encrypt_ptr, decrypt_ptr);
    SecretMode secretMode(reader, writer, encrypt_ptr);


    while (true) {
        cout << "What do you want to do?\n";
        cout << "1 - Normal mode\n";
        cout << "2 - Secret mode\n";
        cout << "3 - Exit\n";
        cin >> number;

        switch (number) {
            case 1: // Normal mode
                int chosenOperation;
                cout << "Choose the operation:\n";
                cout << "1 - Encrypt\n";
                cout << "2 - Decrypt\n";
                cin >> chosenOperation;

                switch (chosenOperation) {
                    case 1:
                        normalMode.HandleEncrypt();
                        break;
                    case 2:
                        normalMode.HandleDecrypt();
                        break;
                    default:
                        break;
                }
                break;

            case 2: // Secret mode
                secretMode.HandleSecretEncrypt();
                break;
            default:
                return 0;
        }
    }
}
