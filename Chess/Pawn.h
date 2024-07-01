#ifndef PAWN_H
#define PAWN_H

#include "Figure.h"
#include "Board.h"

class Pawn : public Figure
{
    public:
        Pawn();
        Pawn(Color, bool, Column, Row);
        Pawn(const Pawn&);
        bool isAttack(Column , Row , const Board&) const override;
        bool nextMove(const Board&) override;
        ~Pawn();
        friend class Board;
};

#endif //PAWN_H