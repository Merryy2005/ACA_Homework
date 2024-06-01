#include "Bishop.h"


Bishop::Bishop() : Figure("white", false, 'C', 1 , 3)
{
    m_name = "B";
}

Bishop::Bishop(std::string color , bool isActive , char col , int row) : 
            Figure(color , isActive , col , row , 3)
{
    m_name = "B";
}

Bishop::Bishop(const Bishop& other) : Figure(other)
{
    m_name = "B";
}

bool Bishop::isAttack(char col, int row , const Board& b) const
{
    int col1 = m_col - 'A';
    int row1 = m_row - 1;
    int col2 = col - 'A';
    int row2 = row - 1;
    if(col1 == col2 && row1 == row2)
    {
        return false;
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

void Bishop::printName() const
{
    std:: cout << "B";
}

Bishop::~Bishop()
{

}