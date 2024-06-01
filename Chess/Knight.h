#ifndef KNIGHT_H
#define KNIGHT_H

#include "Figure.h"
#include "Board.h"

class Knight : public Figure
{
    public:
        Knight();
        Knight(std::string, bool, char, int);
        Knight(const Knight&);
        bool isAttack(char , int , const Board&) const override;
        void printName() const override;
        ~Knight();
        friend class Board;
};

#endif //KNIGHT_H