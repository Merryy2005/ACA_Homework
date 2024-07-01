#include "Queen.h"

Queen::Queen() : Figure(Color::white, false, Column::D, Row::R1)
{
    m_name = Name::queen;
}

Queen::Queen(Color color, bool isActive, Column col, Row row) : 
            Figure(color , isActive , col , row)
{
    m_name = Name::queen;
}

Queen::Queen(const Queen& other) : Figure(other)
{
    m_name = Name::queen;
}

bool Queen::isAttack(Column col, Row row , const Board& b) const
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

bool Queen::nextMove(const Board& b)
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

Queen::~Queen()
{

}