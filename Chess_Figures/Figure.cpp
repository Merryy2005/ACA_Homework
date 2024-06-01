#include "Figure.h"

Figure::Figure() : m_color("white") , m_isActive(false) , m_col('A') , m_row(1) , m_point(0)
{

}

Figure::Figure(std::string color , bool isActive , char col , int row) : 
               m_color(color) , m_isActive(isActive) , m_col(col) , m_row(row) , m_point(0)
{

}

Figure::Figure(std::string color , bool isActive , char col , int row , int point) : 
               m_color(color) , m_isActive(isActive) , m_col(col) , m_row(row) , m_point(point)
{

}

Figure::Figure(const Figure& other) : 
               m_color(other.m_color) , m_isActive(other.m_isActive) , m_col(other.m_col) , m_row(other.m_row)
{

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
    m_col = col;
}

void Figure::setRow(int row)
{
    m_row = row;
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