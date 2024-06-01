#include "Bishop.h"

Bishop::Bishop() : Figure("white", false, 'C', 1 , 3)
{
    
}

Bishop::Bishop(std::string color , bool isActive , char col , int row) : 
            Figure(color , isActive , col , row , 3)
{

}

Bishop::Bishop(const Bishop& other) : Figure(other)
{

}

void Bishop::printName() const
{
    std:: cout << "Name : Bishop ♗" << std::endl;
}

Bishop::~Bishop()
{

}