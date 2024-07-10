#ifndef KING_H
#define KING_H

#include "Figure.h"
#include "Board.h"

#define RESET   "\033[0m"
#define BLUE    "\033[34m"

class King : public Figure
{
    public:
        King();
        King(Color, bool, Column, Row);
        King(const King&);
        bool isAttack(Column , Row , const Board&) const override;
        bool nextMove(const Board&) override;
        ~King();
        friend class Board;
};

#endif //KING_H