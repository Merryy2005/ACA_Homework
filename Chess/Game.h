#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "Board.h"
#include "Figure.h"
#include "Pawn.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Queen.h"
#include "Rook.h"


class Game : public Board
{
    public:
        bool isAttack(int , int) const;
        int getBlackCol() const;
        int getBlackRow() const;
        bool isCheckmate() const;
};

#endif //GAME_H