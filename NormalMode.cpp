#include "NormalMode.h"

NormalMode::NormalMode(Reader& reader, Writer& writer, encrypt_ptr_t encrypt_ptr, decrypt_ptr_t decrypt_ptr)
        : reader(reader), writer(writer), encrypt_ptr(encrypt_ptr), decrypt_ptr(decrypt_ptr) {}

void NormalMode::HandleEncrypt() {
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


void NormalMode::HandleDecrypt() {
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
