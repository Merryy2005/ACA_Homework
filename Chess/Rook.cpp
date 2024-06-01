#include "Rook.h"

Rook::Rook() : Figure("white", false, 'A', 1 , 5)
{
    m_name = "R";
}

Rook::Rook(std::string color , bool isActive , char col , int row) : 
            Figure(color , isActive , col , row , 5)
{
    m_name = "R";
}

Rook::Rook(const Rook& other) : Figure(other)
{
    m_name = "R";
}

bool Rook::isAttack(char col, int row , const Board& b) const
{
    int col1 = m_col - 'A';
    int row1 = m_row - 1;
    int col2 = col - 'A';
    int row2 = row - 1;
    if(col1 == col2 && row1 == row2)
    {
        return false;
    }
    if(col1 == col2)
    {
        for(int i = std::min(row1 , row2) ; i <= std::max(row1 , row2) ; i++)
        {
            if(!(i == row1) && !(i == row2) && (b.m_figures[i][col1] != nullptr && b.m_figures[i][col1] -> getColor() == "white"))
            {
                return false;
            }
        }
        return true;
    }
    if(row1 == row2)
    {
        for(int i = std::min(col1 , col2) ; i <= std::max(col1 , col2) ; i++)
        {
            if(!(i == col1) && !(i == col2) && (b.m_figures[row1][i] != nullptr && b.m_figures[row1][i] -> getColor() == "white"))
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

void Rook::printName() const
{
    std:: cout << "R";
}

Rook::~Rook()
{

}