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
        King(std::string, bool, char, int);
        King(const King&);
        bool isAttack(char , int , const Board&) const override;
        void printName() const override;
        ~King();
        friend class Board;

};

#endif //KING_H