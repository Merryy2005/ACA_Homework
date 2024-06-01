#include "Board.h"

Board::Board() : Matrix(8,8)
{
    m_figures = new Figure**[m_row];
    for(int i = 0 ; i < m_row ; i++)
    {
        m_figures[i] = new Figure*[m_col];
    }
    for(int i = 0 ; i < m_row ; i++)
    {
        for(int j = 0 ; j < m_col ; j++)
        {
            m_ptr[i][j] = (i+j) % 2; // black and white
            m_figures[i][j] = nullptr;
        }
    }
}

bool Board::isNeighbour(int col1 , int row1 , int col2 , int row2) const
{
    if(col1 == col2 && row1 == row2)
    {
        return false;
    }
    if ((abs(col1 - col2) <= 1) && (abs(row1 - row2) <= 1)) {
        return true;
    }
    return false;
}

bool Board::registerFigure(Figure* f)
{
    bool bRes = false;
    if(!(f -> isCreated()))
    {
        return bRes;
    }
    int col = f->getCol() - 'A';
    int row = f->getRow() - 1;
    for(int i = 0 ; i < m_row ; i++)
    {
        for(int j = 0 ; j < m_col ; j++)
        {
            if(m_figures[row][col] == f)
            {
                std::cout << "Already registered" << std::endl;
                return bRes;
            }
        }
    }
    if(f -> getName() == "K")
    {
        for(int i = 0 ; i < m_row ; i++)
        {
            for(int j = 0 ; j < m_col ; j++)
            {
                if(isNeighbour(col , row , j , i) && (m_figures[i][j] && m_figures[i][j] -> getName() == "K"))
                {
                    std::cout << "Kings are neighbours" << std::endl;
                    return bRes;
                }
            }
        }
    }
    if(m_figures[row][col] == nullptr)
    {
        m_figures[row][col] = f;
        bRes = true;
    }
    else
    {
        std::cout << "Already there is a figure" << std::endl;
    }
    return bRes;
}

void Board::printBoard()
{
    for(int i = m_row-1 ; i >= 0 ; i--)
    {
        std::cout << CYAN << (i+1) << RESET;
        for(int j = 0 ; j < m_col ; j++)
        {
            if(m_figures[i][j])
            {
                m_figures[i][j]->printName();
            }
            else{
                std::cout << ".";
            }
        }
        std::cout << std::endl;
    }
    std::cout << " ";
    for(int j = 0 ; j < m_col ; j++)
    {
        std::cout << CYAN << (char)('A' + j) << RESET;
    }
    std::cout << std::endl;
    std::cout << std::endl;
    return;
}

Board::~Board() 
{
    for(int i = 0 ; i < m_row ; i++)
    {
        delete[] m_figures[i];
        m_figures[i] = nullptr;
    }
    delete[] m_figures;
    m_figures = nullptr;

}