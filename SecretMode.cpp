#include "SecretMode.h"

SecretMode::SecretMode(Reader& reader, Writer& writer, encrypt_ptr_t encrypt_ptr)
        : reader(reader), writer(writer), encrypt_ptr(encrypt_ptr) {}

void SecretMode::HandleSecretEncrypt() {
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