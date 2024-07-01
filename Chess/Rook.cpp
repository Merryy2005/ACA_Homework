#include "Rook.h"

Rook::Rook() : Figure(Color::white, false, Column::A, Row::R1)
{
    m_name = Name::rook;
}

Rook::Rook(Color color, bool isActive, Column col, Row row) :
            Figure(color , isActive , col , row)
{
     m_name = Name::rook;
}

Rook::Rook(const Rook& other) : Figure(other)
{
     m_name = Name::rook;
}

bool Rook::isAttack(Column col, Row row , const Board& b) const
{
    int col1 = (int)m_col;
    int row1 = (int)m_row;
    int col2 = (int)col;
    int row2 = (int)row;
    if(col1 == col2 && row1 == row2)
    {
        return false;
    }
    if(col1 == col2)
    {
        for(int i = std::min(row1 , row2) ; i <= std::max(row1 , row2) ; i++)
        {
            if(!(i == row1) && !(i == row2) && (b.m_figures[i][col1] != nullptr && b.m_figures[i][col1] -> getColor() == Color::white))
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
            if(!(i == col1) && !(i == col2) && (b.m_figures[row1][i] != nullptr && b.m_figures[row1][i] -> getColor() == Color::white))
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool Rook::nextMove(const Board& b)
{
    int colInt = (int)m_col;
    int rowInt = (int)m_row;
    for(int i = colInt + 1 ; i < 8 ; i++)
    {
        if(b.m_figures[rowInt][i])
        {
            break;
        }
        if(!m_wasHere[rowInt][i])
        {
            m_wasHere[rowInt][i] = true;
            m_col1 = (Figure::Column)i;
            m_row1 = (Figure::Row)rowInt;
            return true;
        }
    }
    for(int i = colInt - 1 ; i >= 0 ; i--)
    {
        if(b.m_figures[rowInt][i])
        {
            break;
        }
        if(!m_wasHere[rowInt][i])
        {
            m_wasHere[rowInt][i] = true;
            m_col1 = (Figure::Column)i;
            m_row1 = (Figure::Row)rowInt;
            return true;
        }
    }
    for(int j = rowInt + 1; j < 8 ; j++)
    {
        if(b.m_figures[j][colInt])
        {
            break;
        }
        if(!m_wasHere[j][colInt])
        {
            m_wasHere[j][colInt] = true;
            m_col1 = (Figure::Column)colInt;
            m_row1 = (Figure::Row)j;
            return true;
        }
    }
    for(int j = rowInt - 1; j >= 0 ; j--)
    {
        if(b.m_figures[j][colInt])
        {
            break;
        }
        if(!m_wasHere[j][colInt])
        {
            m_wasHere[j][colInt]= true;
            m_col1 = (Figure::Column)colInt;
            m_row1 = (Figure::Row)j;
            return true;
        }
    }
    return false;
}

Rook::~Rook()
{

}