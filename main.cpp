#include <iostream>
#include <string>
#include <Windows.h>
#include "Writer.h"
#include "Reader.h"
#include "NormalMode.h"
#include "SecretMode.h"
#include "LinkedList.h"

using namespace std;

int main() {
    LinkedList list;
    int commandNumber;

    HMODULE handle = LoadLibrary(TEXT("libCaesar.dll"));

    if (handle == nullptr) {
        cout << "DLL not found" << endl;
        return 1;
    }

    encrypt_ptr_t encrypt_ptr = (encrypt_ptr_t) GetProcAddress(handle, "encrypt");
    decrypt_ptr_t decrypt_ptr = (decrypt_ptr_t) GetProcAddress(handle, "decrypt");

    if (encrypt_ptr == nullptr || decrypt_ptr == nullptr) {
        cout << "Functions not found in DLL" << endl;
        return 1;
    }

    Reader reader;
    Writer writer;

    NormalMode normalMode(reader, writer, encrypt_ptr, decrypt_ptr);
    SecretMode secretMode(reader, writer, encrypt_ptr);


    while (true) {
        cout << "Choose the command:" << endl;
        cin >> commandNumber;
        switch (commandNumber) {
            case 1:
                list.appendText();
                break;
            case 2:
                list.addNewLine();
                break;
            case 3:
                list.saveToFile();
                break;
            case 4:
                list.readFromFile();
                break;
            case 5:
                list.displayList();
                break;
            case 6:
                list.insertTextAtPosition();
                break;
            case 7:
                list.searchSubstring();
                break;
            case 8:
                list.Delete();
                break;
            case 9:
                list.undo();
                break;
            case 10:
                list.redo();
                break;
            case 11:
                list.Cut();
                break;
            case 12:
                list.Paste();
                break;
            case 13:
                list.Copy();
                break;
            case 14:
                list.InsertWithReplacement();
                break;
            case 15:
                list.cursor();
                break;
            case 16:
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
            case 17:
                secretMode.HandleSecretEncrypt();
                break;
            default:
                return 0;
                }
        }
    }
