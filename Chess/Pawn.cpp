#include "Pawn.h"

Pawn::Pawn() : Figure(Color::white, false, Column::A, Row::R2)
{
    m_name = Name::pawn;
}

Pawn::Pawn(Color color, bool isActive, Column col, Row row) :  
            Figure(color , isActive , col , row)
{
    m_name = Name::pawn;
}

Pawn::Pawn(const Pawn& other) : Figure(other)
{
    m_name = Name::pawn;
}

bool Pawn::isAttack(Column col, Row row , const Board& b) const
{
    int col1 = (int)m_col;
    int row1 = (int)m_row;
    int col2 = (int)col;
    int row2 = (int)row;
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

bool Pawn::nextMove(const Board& b)
{
    int colInt = (int)m_col;
    int rowInt = (int)m_row;
    rowInt++;
    if(colInt - 1 >= 0)
    { 
        if(!m_wasHere[rowInt][colInt-1])
        {
            m_wasHere[rowInt][colInt-1] = true;
            m_col1 = (Figure::Column)(colInt - 1);
            m_row1 = (Figure::Row)rowInt;
            return true;
        }
    }
    if(colInt + 1 < 8)
    {
        if(!m_wasHere[rowInt][colInt+1])
        {
            m_wasHere[rowInt][colInt+1] = true;
            m_col1 = (Figure::Column)(colInt + 1);
            m_row1 = (Figure::Row)rowInt;
            return true;
        }
    }
    return false;
}

Pawn::~Pawn()
{

}