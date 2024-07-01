#ifndef QUEEN_H
#define QUEEN_H

#include "Figure.h"
#include "Board.h"

class Queen : public Figure
{
    public:
        Queen();
        Queen(Color, bool, Column, Row);
        Queen(const Queen&);
        bool isAttack(Column , Row , const Board&) const override;
        bool nextMove(const Board&) override;
        ~Queen();
        friend class Board;
};

#endif //QUEEN_H