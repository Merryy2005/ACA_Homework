#ifndef ROOK_H
#define ROOK_H

#include "Figure.h"
#include "Board.h"

class Rook : public Figure
{
    public:
        Rook();
        Rook(std::string, bool, char, int);
        Rook(const Rook&);
        bool isAttack(char , int , const Board&) const override;
        void printName() const override;
        ~Rook();
        friend class Board;
};

#endif //ROOK_H