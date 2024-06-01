#include "Queen.h"

Queen::Queen() : Figure("white", false, 'D', 1 , 9)
{
    m_name = "Q";
}

Queen::Queen(std::string color , bool isActive , char col , int row) : 
            Figure(color , isActive , col , row , 9)
{
    m_name = "Q";
}

Queen::Queen(const Queen& other) : Figure(other)
{
    m_name = "Q";
}

bool Queen::isAttack(char col, int row , const Board& b) const
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

    if(row2 - row1 == col2 - col1) // aj ankyunagic
    {
        for(int i = std::min(row1 , row2), j = std::min(col1 , col2); i <= std::max(row1 , row2) &&
            j <= std::max(col1 , col2) ; i++ , j++)
        {
            if(!(i == row1 && j == col1) && !(i == row2 && j == col2) && (b.m_figures[i][j] != nullptr && b.m_figures[i][j] -> getColor() == "white"))
            {
                return false;
            }   
        }
        return true;
    }
    if(row2 - row1 == col1 - col2) // dzax ankyunagic
    {
        for(int i = std::min(row1 , row2) , j = std::max(col1 , col2) ; i <= std::max(row1 , row2) &&  
                j >= std::min(col1 , col2) ; i++ , j--)
        {
            if(!(i == row1 && j == col1) && !(i == row2 && j == col2) && (b.m_figures[i][j] != nullptr && b.m_figures[i][j] -> getColor() == "white"))
            {
                return false;
            }   
        }
        return true;
    }
    return false;
}

void Queen::printName() const
{
    std:: cout << "Q";
}

Queen::~Queen()
{

}