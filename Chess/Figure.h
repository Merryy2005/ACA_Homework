#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <string>
#include <algorithm>
#include "Board.h"

class Board;

class Figure
{
    protected:
        std::string m_color;
        bool m_isActive;
        char m_col; // A-H
        int m_row; // 1-8
        int m_point;
        bool m_create;
        std::string m_name;
    public:
        Figure();
        Figure(std::string, bool, char, int);
        Figure(std::string, bool, char, int , int);
        Figure(const Figure&);
        virtual bool isCreated() const;
        std::string getName() const;
        char getCol() const;
        int getRow() const;
        std::string getColor() const;
        bool getState() const;
        int getPoint() const;
        void setCol(char);
        void setRow(int);
        void printParameters() const;
        virtual bool isAttack(char , int , const Board&) const = 0;
        virtual void printName() const = 0;
        virtual ~Figure();
        friend class Board;
};

#endif //FIGURE_H