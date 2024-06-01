#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "Matrix.h"
#include "Figure.h"

// 0 - black , 1 - white

#define RESET   "\033[0m"
#define CYAN    "\033[36m"

class Figure;

class Board : public Matrix
{
    protected:
        Figure*** m_figures;
    public:
        Board();
        bool isNeighbour(int , int , int , int) const;
        bool registerFigure(Figure*);
        void printBoard();
        ~Board();
        friend class King;
        friend class Queen;
        friend class Bishop;
        friend class Rook;
        friend class Pawn;
        friend class Knight;
};

#endif //BOARD_H