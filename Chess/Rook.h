#ifndef ROOK_H
#define ROOK_H

#include "Figure.h"
#include "Board.h"

class Rook : public Figure
{
    public:
        Rook();
        Rook(Color, bool, Column, Row);
        Rook(const Rook&);
        bool isAttack(Column , Row , const Board&) const override;
        ~Rook();
        bool nextMove(const Board&) override;
        friend class Board;
};

#endif //ROOK_H