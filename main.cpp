#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include "Writer.h"
#include "Reader.h"
#include <cstdlib>  // For random number generation
#include <ctime>    // For seeding random number generator

using namespace std;

typedef string (*encrypt_ptr_t)(string, int);
typedef string (*decrypt_ptr_t)(string, int);

// Function to handle Normal Mode - Encryption
void HandleNormalEncrypt(Reader& reader, Writer& writer, encrypt_ptr_t encrypt_ptr) {
    string inputFilePath, outputFilePath;
    int key;

    cout << "Enter input file path: ";
    cin.ignore();
    getline(cin, inputFilePath);

    cout << "Enter output file path: ";
    getline(cin, outputFilePath);

    cout << "Enter the key: ";
    cin >> key;

    string fileContent = reader.Read(inputFilePath);
    string encryptedText = encrypt_ptr(fileContent, key);
    writer.Write(outputFilePath, encryptedText);

    cout << "Encryption completed successfully.\n";
}

// Function to handle Normal Mode - Decryption
void HandleNormalDecrypt(Reader& reader, Writer& writer, decrypt_ptr_t decrypt_ptr) {
    string inputFilePath, outputFilePath;
    int key;

    cout << "Enter input file path: ";
    cin.ignore();
    getline(cin, inputFilePath);

    cout << "Enter output file path: ";
    getline(cin, outputFilePath);

    cout << "Enter the key: ";
    cin >> key;

    string fileContent = reader.Read(inputFilePath);
    string decryptedText = decrypt_ptr(fileContent, key);
    writer.Write(outputFilePath, decryptedText);

    cout << "Decryption completed successfully.\n";
}

// Function to handle Secret Mode - Encryption with Random Key
void HandleSecretEncrypt(Reader& reader, Writer& writer, encrypt_ptr_t encrypt_ptr) {
    string inputFilePath, outputFilePath;
    int randomKey;

    // Generate a random key
    srand(time(nullptr));
    randomKey = rand() % 1000;  // Generate a random key between 0 and 999

    cout << "Enter input file path: ";
    cin.ignore();
    getline(cin, inputFilePath);

    cout << "Enter output file path: ";
    getline(cin, outputFilePath);

    string fileContent = reader.Read(inputFilePath);
    string encryptedText = encrypt_ptr(fileContent, randomKey);
    writer.Write(outputFilePath, encryptedText);

    cout << "Encryption completed successfully with a random key: " << randomKey << "\n";
}

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
                        HandleNormalEncrypt(reader, writer, encrypt_ptr);
                        break;
                    case 2:
                        HandleNormalDecrypt(reader, writer, decrypt_ptr);
                        break;
                    default:
                        break;
                }
                break;

            case 2: // Secret mode
                HandleSecretEncrypt(reader, writer, encrypt_ptr);
                break;
            default:
                return 0;
        }
    }
}
