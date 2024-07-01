#ifndef BISHOP_H
#define BISHOP_H

#include "Figure.h"
#include "Board.h"

class Bishop : public Figure
{
    public:
        Bishop();
        Bishop(Color, bool, Column, Row);
        Bishop(const Bishop&);
        bool isAttack(Column , Row , const Board&) const override;
        bool nextMove(const Board&) override;
        ~Bishop();
        friend class Board;
};

#endif //BISHOP_H