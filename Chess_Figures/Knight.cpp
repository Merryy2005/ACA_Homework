#include "Knight.h"

Knight::Knight() : Figure("white", false, 'B', 1 , 3)
{
    
}

Knight::Knight(std::string color , bool isActive , char col , int row) : 
            Figure(color , isActive , col , row , 3)
{

}

Knight::Knight(const Knight& other) : Figure(other)
{

}

void Knight::printName() const
{
    std:: cout << "Name : Knight ♘" << std::endl;
}

Knight::~Knight()
{

}