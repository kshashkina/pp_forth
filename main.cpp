#include <iostream>
#include <string>
#include <Windows.h>
#include "Reader.h"
#include "Writer.h"

using namespace std;

typedef string (*encrypt_ptr_t)(string, int);
typedef string (*decrypt_ptr_t)(string, int);

int main() {
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

    string rawText;
    int key;
    cout<< "Write your text"<< endl;
    getline(cin, rawText);
    cout << "Write your key"<<endl;
    cin>>key;

    string encryptedText = encrypt_ptr(rawText, key);
    string decryptedText = decrypt_ptr(encryptedText, key);

    cout << "Original Text: " << rawText << endl;
    cout << "Encrypted Text: " << encryptedText << endl;
    cout << "Decrypted Text: " << decryptedText << endl;

    FreeLibrary(handle);

    Reader reader;
    string filePath;
    cout<<"Provide file path"<<endl;
    cin.ignore();
    getline(cin, filePath);

    string fileContent = reader.Read(filePath);
    cout << "File content:\n" << fileContent;

    Writer writer;
    string text;
    string writePath;
    cout<<"Write your text:"<<endl;
    cin.ignore();
    getline(cin, text);
    cout<<"Write name of the file to put text:"<<endl;
    cin.ignore();
    getline(cin, writePath);

    writer.Write(writePath, text);

    return 0;
}
