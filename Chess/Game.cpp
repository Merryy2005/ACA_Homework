#include "Game.h"

bool Game::isAttack(int col , int row) const
{
    bool check = false;
    for(int i = 0 ; i < m_row ; i++)
    {
        for(int j = 0 ; j < m_col ; j++)
        {
            if(m_figures[i][j] && m_figures[i][j]->getColor() == "black")
            {
                continue;
            }
            else if(m_figures[i][j])
            {
                check |= m_figures[i][j] -> isAttack(col + 'A' , row + 1 , *this);
            }
        }
    }
    return check;
}

int Game::getBlackCol() const
{
    for(int i = 0 ; i < m_row ; i++)
    {
        for(int j = 0 ; j < m_col ; j++)
        {
            if(m_figures[i][j] && m_figures[i][j]->getColor() == "black" && m_figures[i][j] -> getName() == "K")
            {
                return j;
            }
        }
    }
    return -1;
}

int Game::getBlackRow() const
{
    for(int i = 0 ; i < m_row ; i++)
    {
        for(int j = 0 ; j < m_col ; j++)
        {
            if(m_figures[i][j] && m_figures[i][j]->getColor() == "black" && m_figures[i][j] -> getName() == "K")
            {
                return i;
            }
        }
    }
    return -1;
}

bool Game::isCheckmate() const
{
    int col = getBlackCol();
    int row = getBlackRow();
    if(col == -1 || row == -1)
    {
        return false;
    }
    bool check = true;
    check &= isAttack(col ,row);
    if(col - 1 >= 0)
    {
        check &= isAttack(col-1 , row);
    }
    if(col - 1 >= 0 && row-1 >= 0)
    {
        check &= isAttack(col-1 , row-1);
    }
    if(col - 1 >= 0 && row+1 < 8)
    {
        check &= isAttack(col-1 , row+1);
    }
    if(row-1 >= 0)
    {
        check &= isAttack(col , row-1);
    }
    if(row+1 < 8)
    {
        check &= isAttack(col , row+1);
    }
    if(col + 1 < 8 && row-1 >= 0)
    {
        check &= isAttack(col+1 , row-1);
    }
    if(col + 1 < 8)
    {
        check &= isAttack(col+1 , row);
    }
    if(col + 1 < 8 && row+1 < 8)
    {
        check &= isAttack(col+1 , row+1);
    }
    return check;
}