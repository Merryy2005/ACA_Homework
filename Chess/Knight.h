#ifndef KNIGHT_H
#define KNIGHT_H

#include "Figure.h"
#include "Board.h"

class Knight : public Figure
{
    public:
        Knight();
        Knight(Color, bool, Column, Row);
        Knight(const Knight&);
        bool isAttack(Column , Row , const Board&) const override;
        bool nextMove(const Board&) override;
        ~Knight();
        friend class Board;
};

#endif //KNIGHT_H