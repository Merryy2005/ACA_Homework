#include "Bishop.h"


Bishop::Bishop() : Figure(Color::white, false, Column::C, Row::R1)
{
    m_name = Name::bishop;
}

Bishop::Bishop(Color color, bool isActive, Column col, Row row) : 
            Figure(color , isActive , col , row)
{
    m_name = Name::bishop;
}

Bishop::Bishop(const Bishop& other) : Figure(other)
{
    m_name = Name::bishop;
}

bool Bishop::isAttack(Column col, Row row , const Board& b) const
{
    int col1 = (int)m_col;
    int row1 = (int)m_row;
    int col2 = (int)col;
    int row2 = (int)row;
    if(col1 == col2 && row1 == row2)
    {
        return false;
    }
    if(row2 - row1 == col2 - col1) // right diagonal
    {
        for(int i = std::min(row1 , row2), j = std::min(col1 , col2); i <= std::max(row1 , row2) &&
            j <= std::max(col1 , col2) ; i++ , j++)
        {
            if(!(i == row1 && j == col1) && !(i == row2 && j == col2) && (b.m_figures[i][j] != nullptr && b.m_figures[i][j] -> getColor() == Color::white))
            {
                return false;
            }   
        }
        return true;
    }
    if(row2 - row1 == col1 - col2) // left diagonal
    {
        for(int i = std::min(row1 , row2) , j = std::max(col1 , col2) ; i <= std::max(row1 , row2) &&  
                j >= std::min(col1 , col2) ; i++ , j--)
        {
            if(!(i == row1 && j == col1) && !(i == row2 && j == col2) && (b.m_figures[i][j] != nullptr && b.m_figures[i][j] -> getColor() == Color::white))
            {
                return false;
            }   
        }
        return true;
    }
    return false;
}

bool Bishop::nextMove(const Board& b)
{
    int colInt = (int)m_col;
    int rowInt = (int)m_row;
    for(int i = rowInt + 1 , j = colInt + 1; i < 8 && j < 8 ; i++ , j++)
    {
        if(b.m_figures[i][j])
        {
            break;
        }
        if(!m_wasHere[i][j])
        {
            m_wasHere[i][j] = true;
            m_col1 = (Figure::Column)j;
            m_row1 = (Figure::Row)i;
            return true;
        }
    }
    for(int i = rowInt + 1 , j = colInt - 1; i < 8 && j >= 0 ; i++ , j--)
    {
        if(b.m_figures[i][j])
        {
            break;
        }
        if(!m_wasHere[i][j])
        {
            m_wasHere[i][j] = true;
            m_col1 = (Figure::Column)j;
            m_row1 = (Figure::Row)i;
            return true;
        }
    }
    for(int i = rowInt - 1 , j = colInt + 1; i >= 0 && j < 8 ; i-- , j++)
    {
        if(b.m_figures[i][j])
        {
            break;
        }
        if(!m_wasHere[i][j])
        {
            m_wasHere[i][j] = true;
            m_col1 = (Figure::Column)j;
            m_row1 = (Figure::Row)i;
            return true;
        }
    }
    for(int i = rowInt - 1 , j = colInt - 1; i >= 0 && j >= 0 ; i-- , j--)
    {
        if(b.m_figures[i][j])
        {
            break;
        }
        if(!m_wasHere[i][j])
        {
            m_wasHere[i][j] = true;
            m_col1 = (Figure::Column)j;
            m_row1 = (Figure::Row)i;
            return true;
        }
    }
    return false;
}

Bishop::~Bishop()
{

}