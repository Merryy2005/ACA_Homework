#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <string>
#include <algorithm>

#define BLUE "\033[34m"
#define RESET "\033[0m"

class Board;

class Figure
{
    public:
        enum class Column
        {
            A, B, C, D, E, F, G, H
        };
        enum class Row
        {
            R1, R2, R3, R4, R5, R6, R7, R8 
        };
        enum class Color
        {
            black, white
        };
        enum class Name
        {
            king,
            queen,
            bishop,
            knight,
            rook,
            pawn
        };
    protected:
        Color m_color;
        bool m_isActive;
        Column m_col;
        Row m_row;
        Column m_col1;
        Row m_row1;
        bool m_create;
        Name m_name;
        bool** m_wasHere;
        bool** m_wasHere1;
    public:
        Figure();
        Figure(Color, bool, Column, Row);
        Figure(const Figure&);
        virtual bool isCreated() const;
        Name getName() const;
        Column getCol() const;
        Row getRow() const;
        Color getColor() const;
        bool getState() const;
        void setCol(Column);
        void setRow(Row);
        void printParameters() const;
        virtual void printName() const;
        virtual bool isAttack(Column, Row, const Board&) const = 0;
        virtual bool nextMove(const Board&) = 0;
        virtual ~Figure();
        friend class Board;
        friend class Game;
};

#endif // FIGURE_H
