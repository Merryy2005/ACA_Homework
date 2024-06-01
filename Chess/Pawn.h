#ifndef PAWN_H
#define PAWN_H

#include "Figure.h"
#include "Board.h"

class Pawn : public Figure
{
    public:
        Pawn();
        Pawn(std::string, bool, char, int);
        Pawn(const Pawn&);
        bool isAttack(char , int , const Board&) const override;
        void printName() const override;
        ~Pawn();
        friend class Board;
};

#endif //PAWN_H