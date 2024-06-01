#include "King.h"

King::King() : Figure("white", false, 'E', 1)
{

}

King::King(std::string color , bool isActive , char col , int row) : 
            Figure(color , isActive , col , row)
{

}

King::King(const King& other) : Figure(other)
{

}

void King::printName() const
{
    std:: cout << "Name : King ♔" << std::endl;
}

King::~King()
{

}