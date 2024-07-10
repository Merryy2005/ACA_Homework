#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "Matrix.h"
#include "Figure.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Rook.h"
#include "Knight.h"
#include "Pawn.h"

// 0 - black , 1 - white

#define RESET   "\033[0m"
#define CYAN    "\033[36m"

class Figure;
class King;
class Queen;
class Bishop;
class Rook;
class Knight;
class Pawn;

class Board : public Matrix
{
    protected:
        Figure*** m_figures;
    public:
        Board();
        Board(const Board&);
        Board& operator=(const Board&); 
        bool isNeighbour(Figure::Column, Figure::Row, Figure::Column, Figure::Row) const;
        bool registerFigure(Figure*);
        void printBoard();
        Figure::Column getBlackCol() const;
        Figure::Row getBlackRow() const;
        bool isAttack(Figure::Column , Figure::Row) const;
        ~Board();
        friend class King;
        friend class Queen;
        friend class Bishop;
        friend class Rook;
        friend class Pawn;
        friend class Knight;
};

#endif //BOARD_H