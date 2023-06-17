#ifndef CUBE_H
#define CUBE_H

#include <array>
#include <string>

class Cube
{
    private:
    std::array<std::array<char, 4>, 2> m_cube;

    public:
    Cube()
    :m_cube{}
    {}

    Cube(const std::string &text);

    Cube(std::string::const_iterator it1, std::string::const_iterator it2);
    void Rotate_Left(size_t count);
    void Rotate_Right(size_t count);
    void Rotate_Up(size_t count);
    void Rotate_Down(size_t count);
    std::string to_string() const;
};

#endif