#ifndef QUEEN_H
#define QUEEN_H

#include "Figure.h"

class Queen : public Figure
{
    public:
        Queen();
        Queen(std::string, bool, char, int);
        Queen(const Queen&);
        virtual void printName() const override;
        ~Queen();
};

#endif //QUEEN_H