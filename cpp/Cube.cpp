#include "Cube.h"

#include <string>
#include <algorithm>

Cube::Cube(const std::string &text)
:m_cube{}
{   
    int k = 0;
    for(int i = 0; i < 2; ++i)
    {
        for(int j = 0; j < 4; ++j, ++k)
        {
            m_cube[i][j] = text[k];
        }
    }
}

Cube::Cube(std::string::const_iterator it1, std::string::const_iterator it2)
:m_cube{}
{
    for(int i = 0; i < 2; ++i)
    {
        for(int j = 0; j < 4 && it1 != it2; ++j, ++it1)
        {
            m_cube[i][j] = *it1;
        }
    }
}
void Cube::Rotate_Left(size_t count)
{
    count = count % 4;
    if(!count)
        return;
    std::rotate(m_cube[0].begin(),m_cube[0].begin() + count, m_cube[0].end());
    std::rotate(m_cube[1].begin(),m_cube[1].begin() + count, m_cube[1].end());

}

void Cube::Rotate_Right(size_t count)
{
    count = count % 4;
    if(!count)
        return;
    Rotate_Left(4 - count);
}
void Cube::Rotate_Up(size_t count)
{
    count = count % 4;
    while(count)
    {
        std::swap(m_cube[0][0], m_cube[1][0]);
        std::swap(m_cube[0][0], m_cube[1][3]);
        std::swap(m_cube[0][0], m_cube[0][3]);
        std::swap(m_cube[0][1], m_cube[1][1]);
        std::swap(m_cube[0][1], m_cube[1][2]);
        std::swap(m_cube[0][1], m_cube[0][2]);
        --count;
    }

}
void Cube::Rotate_Down(size_t count)
{
    count = count % 4;
    if(!count)
        return;
    Rotate_Up(4 - count);
}

std::string Cube::to_string() const
{
    return std::string(m_cube[0].begin(), m_cube[0].end())
        + std::string(m_cube[1].begin(), m_cube[1].end());
}