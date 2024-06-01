#ifndef ROOK_H
#define ROOK_H

#include "Figure.h"

class Rook : public Figure
{
    public:
        Rook();
        Rook(std::string, bool, char, int);
        Rook(const Rook&);
        virtual void printName() const override;
        ~Rook();
};

#endif //ROOK_H