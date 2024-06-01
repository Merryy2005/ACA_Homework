#include "Knight.h"

Knight::Knight() : Figure("white", false, 'B', 1 , 3)
{
    m_name = "N";
}

Knight::Knight(std::string color , bool isActive , char col , int row) : 
            Figure(color , isActive , col , row , 3)
{
    m_name = "N";
}

Knight::Knight(const Knight& other) : Figure(other)
{
    m_name = "N";
}

bool Knight::isAttack(char col, int row, const Board& b) const
{
    int col1 = m_col - 'A';
    int row1 = m_row - 1;
    int col2 = col - 'A';
    int row2 = row - 1;
    if(col1 == col2 && row1 == row2)
    {
        return false;
    }
    if(abs(col1 - col2) == 2 && abs(row1 - row2) == 1)
    {
        return true;
    }
    if(abs(col1 - col2) == 1 && abs(row1 - row2) == 2)
    {
        return true;
    }
    return false;
}

void Knight::printName() const
{
    std:: cout << "N";
}

Knight::~Knight()
{

}