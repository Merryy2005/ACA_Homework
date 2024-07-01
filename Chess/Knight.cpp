#include "Knight.h"

Knight::Knight() : Figure(Color::white, false, Column::B, Row::R1)
{
    m_name = Name::knight;
}

Knight::Knight(Color color, bool isActive, Column col, Row row) :  
            Figure(color , isActive , col , row)
{
    m_name = Name::knight;
}

Knight::Knight(const Knight& other) : Figure(other)
{
    m_name = Name::knight;
}

bool Knight::isAttack(Column col, Row row , const Board& b) const
{
    int col1 = (int)m_col;
    int row1 = (int)m_row;
    int col2 = (int)col;
    int row2 = (int)row;
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

bool Knight::nextMove(const Board& b)
{
    int colInt = (int)m_col;
    int rowInt = (int)m_row;
    for(int i = 0 ; i < 8 ; i++)
    {
        for(int j = 0 ; j < 8 ; j++)
        {
            if(abs(rowInt - i) == 2 && abs(colInt - j) == 1)
            {
                if(!m_wasHere[i][j])
                {
                    m_wasHere[i][j] = true;
                    m_col1 = (Figure::Column)j;
                    m_row1 = (Figure::Row)i;
                    return true;
                }
            }
            if(abs(rowInt - i) == 1 && abs(colInt - j) == 2)
            {
                if(!m_wasHere[i][j])
                {
                    m_wasHere[i][j] = true;
                    m_col1 = (Figure::Column)j;
                    m_row1 = (Figure::Row)i;
                    return true;
                }
            }
        }
    }
    return false;
}

Knight::~Knight()
{

}