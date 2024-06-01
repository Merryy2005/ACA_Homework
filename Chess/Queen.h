#ifndef QUEEN_H
#define QUEEN_H

#include "Figure.h"
#include "Board.h"

class Queen : public Figure
{
    public:
        Queen();
        Queen(std::string, bool, char, int);
        Queen(const Queen&);
        bool isAttack(char , int , const Board&) const override;
        void printName() const override;
        ~Queen();
        friend class Board;
};

#endif //QUEEN_H