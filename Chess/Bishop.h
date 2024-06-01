#ifndef BISHOP_H
#define BISHOP_H

#include "Figure.h"
#include "Board.h"

class Bishop : public Figure
{
    public:
        Bishop();
        Bishop(std::string, bool, char, int);
        Bishop(const Bishop&);
        bool isAttack(char , int , const Board&) const override;
        void printName() const override;
        ~Bishop();
        friend class Board;
};

#endif //BISHOP_H