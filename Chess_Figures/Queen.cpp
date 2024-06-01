#include "Queen.h"

Queen::Queen() : Figure("white", false, 'D', 1 , 9)
{
    
}

Queen::Queen(std::string color , bool isActive , char col , int row) : 
            Figure(color , isActive , col , row , 9)
{

}

Queen::Queen(const Queen& other) : Figure(other)
{

}

void Queen::printName() const
{
    std:: cout << "Name : Queen ♕" << std::endl;
}

Queen::~Queen()
{

}