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

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"

class Game : public Board
{
    public:
        Game();
        Game(const Game&);
        bool isCheckmate() const;
        bool isCheckmateOneStep(bool) const;
        bool isCheckmateTwoStep() const;
        void analizeGame() const;
};

#endif //GAME_H