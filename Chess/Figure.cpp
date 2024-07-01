#include "Figure.h"

Figure::Figure() : m_color(Color::white) , m_isActive(false) , m_col(Column::A) , m_row(Row::R1), m_col1(m_col) , m_row1(m_row) , m_create(true) , m_name(Name::king) , m_wasHere(new bool*[8])
{
    for(int i = 0 ; i < 8 ; i++)
    {
        m_wasHere[i] = new bool[8];
    }
    for(int i = 0 ; i < 8 ; i++)
    {
        for(int j = 0 ; j < 8 ; j++)
        {
            m_wasHere[i][j] = false;
        }
    }
    m_wasHere[(int)m_row][(int)m_col] = true;
}

Figure::Figure(Color color , bool isActive , Column col , Row row) : 
               m_color(color) , m_isActive(isActive) , m_col(col) , m_row(row) , m_col1(m_col) , m_row1(m_row) , m_create(true) , m_name(Name::king) , m_wasHere(new bool*[8])
{
    for(int i = 0 ; i < 8 ; i++)
    {
        m_wasHere[i] = new bool[8];
    }
    for(int i = 0 ; i < 8 ; i++)
    {
        for(int j = 0 ; j < 8 ; j++)
        {
            m_wasHere[i][j] = false;
        }
    }
    m_wasHere[(int)m_row][(int)m_col] = true;
}

Figure::Figure(const Figure& other) : 
               m_color(other.m_color) , m_isActive(other.m_isActive) , m_col(other.m_col) , 
               m_row(other.m_row) , m_col1(other.m_col1) , m_row1(other.m_row1) , m_create(other.m_create) , m_name(other.m_name) , m_wasHere(new bool*[8])
{
    for(int i = 0 ; i < 8 ; i++)
    {
        m_wasHere[i] = new bool[8];
    }
    for(int i = 0 ; i < 8 ; i++)
    {
        for(int j = 0 ; j < 8 ; j++)
        {
            m_wasHere[i][j] = other.m_wasHere[i][j];
        }
    }
}

bool Figure::isCreated() const
{
    return m_create;
}

Figure::Name Figure::getName() const
{
    return m_name;
}

Figure::Column Figure::getCol() const
{
    return m_col;
}

Figure::Row Figure::getRow() const
{
    return m_row;
}

Figure::Color Figure::getColor() const
{
    return m_color;
}

bool Figure::getState() const
{
    return m_isActive;
}

void Figure::setCol(Column col)
{
    m_col = col;
}

void Figure::setRow(Row row)
{
    m_row = row;
}

void Figure::printParameters() const 
{
    printName();
    std::cout << "Color: " << (m_color == Color::white ? "white" : "black") << std::endl;
    std::cout << "Status: " << (m_isActive ? "Active" : "Not Active") << std::endl;
    std::cout << "Position: " << char('A' + (int)m_col) << " " << (int)m_row + 1 << std::endl;
}

void Figure::printName() const
{
    switch (m_name)
    {
        case Name::king:
            std::cout << (m_color == Color::white ? "K" : BLUE "K" RESET);
            break;
        case Name::queen:
            std::cout << (m_color == Color::white ? "Q" : BLUE "Q" RESET);
            break;
        case Name::bishop:
            std::cout << (m_color == Color::white ? "B" : BLUE "B" RESET);
            break;
        case Name::knight:
            std::cout << (m_color == Color::white ? "N" : BLUE "N" RESET);
            break;
        case Name::rook:
            std::cout << (m_color == Color::white ? "R" : BLUE "R" RESET);
            break;
        case Name::pawn:
            std::cout << (m_color == Color::white ? "P" : BLUE "P" RESET);
            break;
        default:
            break;
    }
}


Figure::~Figure()
{
    for(int i = 0 ; i < 8 ; i++)
    {
        delete[] m_wasHere[i];
    }
    delete[] m_wasHere;
    m_wasHere = nullptr;
    // for(int i = 0 ; i < 8 ; i++)
    // {
    //     delete[] m_wasHere1[i];
    // }
    // delete[] m_wasHere1;
    // m_wasHere1 = nullptr;
}