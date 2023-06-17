#include "Text_Encryptor.h"
#include <iostream>
#include <string>

int main()
{
    Text_Encryptor encryptor;
    int mode;
    while(1)
    {
        std::cout << "Choose the Mode 1(encryption), 2(decryption)" << std::endl;
        std::cin >> mode;
        std::cin.ignore();
        if(mode == 1)
        {
            std::string text;
            std::cout << "Enter The text for Encryption: " << std::endl;
            std::getline(std::cin, text);
            std::string key = encryptor.encrypt(text);

            std::cout << "Key: " << key << std::endl;
            std::cout << "Encrypted Text: [" << text << "]" << std::endl;
        }
        else if(mode == 2)
        {
            std::string text;
            std::cout << "Enter The text for Decryption: " << std::endl;
            std::getline(std::cin, text);
            std::string key;
            std::cout << "Enter The key for this Text: " << std::endl;
            std::getline(std::cin, key);

            encryptor.decrypt(text, key);
            std::cout << "Decrypted Text: [" << text << "]" << std::endl;
        }
        else if(mode == 0)
            break;
    }
}