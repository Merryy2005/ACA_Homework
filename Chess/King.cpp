#include "King.h"

King::King() : Figure(Color::white, false, Column::E, Row::R1)
{
    m_name = Name::king;
}

King::King(Color color, bool isActive, Column col, Row row) : 
            Figure(color , isActive , col , row)
{
    m_name = Name::king;
}

King::King(const King& other) : Figure(other)
{
    m_name = Name::king;
}

bool King::isAttack(Column col, Row row , const Board& b) const
{
    int col1 = (int)m_col;
    int row1 = (int)m_row;
    int col2 = (int)col;
    int row2 = (int)row;
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

bool King::nextMove(const Board& b)
{
    int colInt = (int)m_col;
    int rowInt = (int)m_row;
    if(b.m_figures[rowInt][colInt] -> getColor() == Figure::Color::white)
    {
        for(int i = 0 ; i < 8 ; i++)
        {
            for(int j = 0 ; j < 8 ; j++)
            {
                    if(std::abs(rowInt - i) <= 1 && std::abs(colInt - j) <= 1)
                    {
                        for(int i1 = 0 ; i1 < 8 ; i1++)
                        {
                            for(int j1 = 0 ; j1 < 8 ; j1++)
                            {
                                if(!(i1 == rowInt && j1 == colInt) && std::abs(i1 - i) <= 1 && std::abs(j1 - j) <= 1 && b.m_figures[i1][j1] && b.m_figures[i1][j1]->getName() == Figure::Name::king)
                                {
                                    m_wasHere[i][j] = true;
                                    break;
                                }
                            }
                        }
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
    else
    {
        for(int i = 0 ; i < 8 ; i++)
        {
            for(int j = 0 ; j < 8 ; j++)
            {
                    if(std::abs(rowInt - i) <= 1 && std::abs(colInt - j) <= 1)
                    {
                        if(b.isAttack((Figure::Column)j,(Figure::Row)i))
                        {
                            m_wasHere[i][j] = true;
                        }
                        else if(!m_wasHere[i][j])
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
}

King::~King()
{
    
}