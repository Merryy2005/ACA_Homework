#include "Figure.h"

Figure::Figure() : m_color("white") , m_isActive(false) , m_col('A') , m_row(1) , m_point(0) , m_create(true) , m_name("")
{

}

Figure::Figure(std::string color , bool isActive , char col , int row) : 
               m_color(color) , m_isActive(isActive) , m_col(col) , m_row(row) , m_point(0) , m_create(true) , m_name("")
{
    if(m_color != "white" && m_color != "black")
    {
        m_create = false;
        std::cout << "Couldn't create figure , wrong color" << std::endl;
    }
    if(!(m_col >= 'A' && m_col <= 'H'))
    {
        m_create = false;
        std::cout << "Couldn't create figure , wrong column" << std::endl;
    }
    if(!(m_row >= 1 && m_row <= 8))
    {
        m_create = false;
        std::cout << "Couldn't create figure , wrong row" << std::endl;
    }
}

Figure::Figure(std::string color , bool isActive , char col , int row , int point) : 
               m_color(color) , m_isActive(isActive) , m_col(col) , m_row(row) , m_point(point) , m_create(true) , m_name("")
{
    if(m_color != "white" && m_color != "black")
    {
        m_create = false;
        std::cout << "Couldn't create figure , wrong color" << std::endl;
    }
    if(!(m_col >= 'A' && m_col <= 'H'))
    {
        m_create = false;
        std::cout << "Couldn't create figure , wrong column" << std::endl;
    }
    if(!(m_row >= 1 && m_row <= 8))
    {
        m_create = false;
        std::cout << "Couldn't create figure , wrong row" << std::endl;
    }
}

Figure::Figure(const Figure& other) : 
               m_color(other.m_color) , m_isActive(other.m_isActive) , m_col(other.m_col) , 
               m_row(other.m_row) , m_create(other.m_create) , m_name(other.m_name)
{

}

bool Figure::isCreated() const
{
    return m_create;
}

std::string Figure::getName() const
{
    return m_name;
}

char Figure::getCol() const
{
    return m_col;
}

int Figure::getRow() const
{
    return m_row;
}

std::string Figure::getColor() const
{
    return m_color;
}

bool Figure::getState() const
{
    return m_isActive;
}

int Figure::getPoint() const
{
    return m_point;
}


void Figure::setCol(char col)
{
    if(col >= 'A' && col <= 'H')
    {
        m_col = col;
    }
    else
    {
        std::cout << "Wrong column , try again" << std::endl;
    }
}

void Figure::setRow(int row)
{
    if(row >= 1 && row <= 8)
    {
        m_row = row;
    }
    else
    {
        std::cout << "Wrong row , try again" << std::endl;
    }
}

void Figure::printParameters() const
{
    printName();
    std::cout << "Color : " << m_color << std::endl;
    std::cout << "Point : " << m_point << std::endl;
    std:: cout << "Status : " << (m_isActive ? "Active" : "Not Active") << std::endl;
    std::cout << "Position : " << m_col << m_row << std::endl;
}

Figure::~Figure()
{

}