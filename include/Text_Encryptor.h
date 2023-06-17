#ifndef TEXT_ENCRYPTOR_H
#define TEXT_ENCRYPTOR_H

#include "Cube.h"

#include <string>
#include <vector>

class Text_Encryptor
{
    public:
    std::string encrypt(std::string &target);
    void decrypt(std::string &encrypted, std::string key);

    private: 
    void decrypt_cube(Cube &cube, const std::string &key);
    int get_random_rotate();
    std::vector<std::string> split(const std::string& s, char delimiter);
    std::vector<Cube> str_to_cube(const std::string& str);
};

#endif