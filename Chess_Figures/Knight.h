#ifndef KNIGHT_H
#define KNIGHT_H

#include "Figure.h"

class Knight : public Figure
{
    public:
        Knight();
        Knight(std::string, bool, char, int);
        Knight(const Knight&);
        virtual void printName() const override;
        ~Knight();
};

#endif //KNIGHT_H