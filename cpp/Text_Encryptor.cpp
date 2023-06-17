#include "Text_Encryptor.h"

#include <random>
#include <sstream>

std::string Text_Encryptor::encrypt(std::string &target)
{
    std::vector<Cube> Cubs = str_to_cube(target);
    target.clear();

    std::string key{};
    for(auto &elem : Cubs)
    {
        int cnt = get_random_rotate();
        elem.Rotate_Down(cnt % 4);
        if(!key.empty())
            key += ':';
        key = key + "D" + std::to_string(cnt) + ',';

        cnt = get_random_rotate();
        elem.Rotate_Up(cnt % 4);
        key = key + "U" + std::to_string(cnt) + ',';

        cnt = get_random_rotate();
        elem.Rotate_Left(cnt % 4);
        key = key + "L" + std::to_string(cnt) + ',';

        cnt = get_random_rotate();
        elem.Rotate_Right(cnt % 4);
        key = key + "R" + std::to_string(cnt);
    }

    for(auto &cube: Cubs)
    {
        target += cube.to_string();
    }

    return key;
}

void Text_Encryptor::decrypt(std::string &encrypted, std::string key)
{
    std::vector<Cube> Cubs = str_to_cube(encrypted);
    std::vector<std::string> keys = split(key, ':');
    encrypted.clear();
    decltype(keys)::size_type i = 0;

    for(auto &cube: Cubs)
    {
        decrypt_cube(cube, keys[i]);
        ++i;
        encrypted += cube.to_string();
    }
}

void Text_Encryptor::decrypt_cube(Cube &cube, const std::string &key)
{
    std::vector<std::string> sides = split(key, ',');
    for(int i = sides.size() -1; i >= 0; i--)
    {
        std::string substring = sides[i].substr(1);
        if(sides[i][0] == 'D')
        {
            cube.Rotate_Up(std::stoi(substring) % 4);
        }
        else if(sides[i][0] == 'U')
        {
            cube.Rotate_Down(std::stoi(substring) % 4);
        }
        else if(sides[i][0] == 'L')
        {
            cube.Rotate_Right(std::stoi(substring) % 4);
        }
        else if(sides[i][0] == 'R')
        {
            cube.Rotate_Left(std::stoi(substring) % 4);
        }
    }
}

int Text_Encryptor::get_random_rotate()
{
    std::random_device rd;
    std::mt19937 generator(rd());
    const int min = 1;
    const int max = 10000;
    std::uniform_int_distribution<int> distribution(min, max);

    int number;
    do
    {
        number = distribution(generator);
    }
    while (number % 4 == 0);

    return number;
}

std::vector<std::string> Text_Encryptor::split(const std::string& s, char delimiter)
{
    std::vector<std::string> tokens;
    std::stringstream ss(s);
    std::string token;

    while (std::getline(ss, token, delimiter)) 
    {
        tokens.push_back(token);
    }
    return tokens;
}

std::vector<Cube> Text_Encryptor::str_to_cube(const std::string& str)
{
    std::vector<Cube> Cubs(str.size() / 8 + (str.size() % 8 != 0));
    auto it1 = str.begin();
    auto it2 = str.begin() + 8;

    for (auto& elem : Cubs)
    {
        elem = Cube(it1, it2);
        it1 = it2;
        it2 = std::min(it2 + 8, str.end());
    }

    return Cubs;
}