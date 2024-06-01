#include "Pawn.h"

Pawn::Pawn() : Figure("white", false, 'A', 2 , 1)
{
    
}

Pawn::Pawn(std::string color , bool isActive , char col , int row) : 
            Figure(color , isActive , col , row , 3)
{

}

Pawn::Pawn(const Pawn& other) : Figure(other)
{

}

void Pawn::printName() const
{
    std:: cout << "Name : Pawn ♙" << std::endl;
}

Pawn::~Pawn()
{

}