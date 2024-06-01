#include "Rook.h"

Rook::Rook() : Figure("white", false, 'A', 1 , 5)
{
    
}

Rook::Rook(std::string color , bool isActive , char col , int row) : 
            Figure(color , isActive , col , row , 5)
{

}

Rook::Rook(const Rook& other) : Figure(other)
{

}

void Rook::printName() const
{
    std:: cout << "Name : Rook ♖" << std::endl;
}

Rook::~Rook()
{

}