#ifndef PAWN_H
#define PAWN_H

#include "Figure.h"

class Pawn : public Figure
{
    public:
        Pawn();
        Pawn(std::string, bool, char, int);
        Pawn(const Pawn&);
        virtual void printName() const override;
        ~Pawn();
};

#endif //PAWN_H