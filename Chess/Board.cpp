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
            if((i+j) % 2 == 0)
            {
                m_ptr[i][j] = Color::black;
            }
            else
            {
                m_ptr[i][j] = Color::white;
            }
            m_figures[i][j] = nullptr;
        }
    }
}

Board::Board(const Board& other) : Matrix(8,8)
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
            if((i+j) % 2 == 0)
            {
                m_ptr[i][j] = Color::black;
            }
            else
            {
                m_ptr[i][j] = Color::white;
            }
            if(other.m_figures[i][j] == nullptr)
            {
                m_figures[i][j] = nullptr;
            }
            else
            {
                switch(other.m_figures[i][j]->m_name)
                {
                    case Figure::Name::king:
                        m_figures[i][j] = new King(*((King*)(other.m_figures[i][j])));
                        break;
                    case Figure::Name::queen:
                        m_figures[i][j] = new Queen(*((Queen*)(other.m_figures[i][j])));
                        break;
                    case Figure::Name::bishop:
                        m_figures[i][j] = new Bishop(*((Bishop*)(other.m_figures[i][j])));
                        break;
                    case Figure::Name::rook:
                        m_figures[i][j] = new Rook(*((Rook*)(other.m_figures[i][j])));
                        break;
                    case Figure::Name::knight:
                        m_figures[i][j] = new Knight(*((Knight*)(other.m_figures[i][j])));
                        break;
                    case Figure::Name::pawn:
                        m_figures[i][j] = new Pawn(*((Pawn*)(other.m_figures[i][j])));
                        break;
                }
            }
        }
    }
}

Board& Board::operator=(const Board& other)
{
    if (this != &other)
    {
        Matrix::operator=(other);
        for (int i = 0; i < m_row; ++i)
        {
            delete[] m_figures[i];
        }
        delete[] m_figures;
        m_row = other.m_row;
        m_col = other.m_col;
        m_figures = new Figure**[m_row];
        for (int i = 0; i < m_row; ++i)
        {
            m_figures[i] = new Figure*[m_col];
            for (int j = 0; j < m_col; ++j)
            {
                if (other.m_figures[i][j] == nullptr)
                {
                    m_figures[i][j] = nullptr;
                }
                else
                {
                    switch(other.m_figures[i][j]->m_name)
                    {
                        case Figure::Name::king:
                            m_figures[i][j] = new King(*((King*)(other.m_figures[i][j])));
                            break;
                        case Figure::Name::queen:
                            m_figures[i][j] = new Queen(*((Queen*)(other.m_figures[i][j])));
                            break;
                        case Figure::Name::bishop:
                            m_figures[i][j] = new Bishop(*((Bishop*)(other.m_figures[i][j])));
                            break;
                        case Figure::Name::rook:
                            m_figures[i][j] = new Rook(*((Rook*)(other.m_figures[i][j])));
                            break;
                        case Figure::Name::knight:
                            m_figures[i][j] = new Knight(*((Knight*)(other.m_figures[i][j])));
                            break;
                        case Figure::Name::pawn:
                            m_figures[i][j] = new Pawn(*((Pawn*)(other.m_figures[i][j])));
                            break;
                    }
                }
            }
        }
    }
    return *this;
}

bool Board::isNeighbour(Figure::Column col1, Figure::Row row1, Figure::Column col2, Figure::Row row2) const
{
    if(col1 == col2 && row1 == row2)
    {
        return false;
    }
    if ((abs((int)col1 - (int)col2) <= 1) && (abs((int)row1 - (int)row2) <= 1)) {
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
    Figure::Column col = f->getCol();
    Figure::Row row = f->getRow();
    for(int i = 0 ; i < m_row ; i++)
    {
        for(int j = 0 ; j < m_col ; j++)
        {
            if(m_figures[(int)row][(int)col] == f)
            {
                std::cout << "Already registered" << std::endl;
                return bRes;
            }
        }
    }
    if(f -> getName() == Figure::Name::king)
    {
        for(int i = 0 ; i < m_row ; i++)
        {
            for(int j = 0 ; j < m_col ; j++)
            {
                if(isNeighbour(col , row , (Figure::Column)j , (Figure::Row)i) && (m_figures[i][j] && m_figures[i][j] -> getName() == Figure::Name::king))
                {
                    std::cout << "Kings are neighbours" << std::endl;
                    return bRes;
                }
            }
        }
    }
    if(f -> getName() == Figure::Name::pawn && row == Figure::Row::R1)
    {
        std::cout << "Pawn can't be on the first row" << std::endl;
        return bRes;
    }
    if(m_figures[(int)row][(int)col] == nullptr)
    {
        m_figures[(int)row][(int)col] = f;
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
            else
            {
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

Figure::Column Board::getBlackCol() const
{
    for(int i = 0 ; i < m_row ; i++)
    {
        for(int j = 0 ; j < m_col ; j++)
        {
            if(m_figures[i][j] && m_figures[i][j]->getColor() == Figure::Color::black && m_figures[i][j] -> getName() == Figure::Name::king)
            {
                return (Figure::Column)j;
            }
        }
    }
    std::cout <<"No black king found on the board." << std::endl;
    return Figure::Column::A;
}

Figure::Row Board::getBlackRow() const
{
    for(int i = 0 ; i < m_row ; i++)
    {
        for(int j = 0 ; j < m_col ; j++)
        {
            if(m_figures[i][j] && m_figures[i][j]->getColor() == Figure::Color::black && m_figures[i][j] -> getName() == Figure::Name::king)
            {
                return (Figure::Row)i;
            }
        }
    }
    std::cout <<"No black king found on the board." << std::endl;
    return Figure::Row::R1;
}

bool Board::isAttack(Figure::Column col , Figure::Row row) const
{
    bool check = false;
    for(int i = 0 ; i < m_row ; i++)
    {
        for(int j = 0 ; j < m_col ; j++)
        {
            if(m_figures[i][j] && m_figures[i][j]->getColor() == Figure::Color::black)
            {
                continue;
            }
            else if(m_figures[i][j])
            {
                check |= m_figures[i][j] -> isAttack(col , row , *this);
            }
        }
    }
    return check;
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