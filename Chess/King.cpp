#include "King.h"

King::King() : Figure("white", false, 'E', 1)
{
    m_name = "K";
}

King::King(std::string color , bool isActive , char col , int row) : 
            Figure(color , isActive , col , row)
{
    m_name = "K";
}

King::King(const King& other) : Figure(other)
{
    m_name = "K";
}

bool King::isAttack(char col, int row , const Board& b) const
{
    int col1 = m_col - 'A';
    int row1 = m_row - 1;
    int col2 = col - 'A';
    int row2 = row - 1;
    if(col1 == col2 && row1 == row2)
    {
        return false;
    }
    if(abs(row1 - row2) <= 1 && abs(col1 - col2) <= 1)
    {
        return true;
    }
    return false;
}

void King::printName() const
{
    if(m_color == "black")
    {
        std::cout << BLUE << "K" << RESET;
    }
    else{
        std:: cout << "K";
    }
}

King::~King()
{

}