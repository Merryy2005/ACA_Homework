#include "Pawn.h"

Pawn::Pawn() : Figure("white", false, 'A', 2 , 1)
{
    m_name = "P";
}

Pawn::Pawn(std::string color , bool isActive , char col , int row) : 
            Figure(color , isActive , col , row , 3)
{
    if(m_color == "white" && row == 1)
    {
        m_create = false;
        std::cout << "White pawn can't be here" << std::endl;
    }
    if(m_color == "black" && row == 8)
    {
        m_create = false;
        std::cout << "Black pawn can't be here" << std::endl;
    }
    m_name = "P";
}

Pawn::Pawn(const Pawn& other) : Figure(other)
{
    m_name = "P";
}

bool Pawn::isAttack(char col, int row , const Board& b) const
{
    int col1 = m_col - 'A';
    int row1 = m_row - 1;
    int col2 = col - 'A';
    int row2 = row - 1;
    if(col1 == col2 && row1 == row2)
    {
        return false;
    }
    if(row2 - row1 == 1 && abs(col1 - col2) == 1)
    {
        return true;
    }
    return false;
}

void Pawn::printName() const
{
    std:: cout << "P";
}

Pawn::~Pawn()
{

}