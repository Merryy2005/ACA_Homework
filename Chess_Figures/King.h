#ifndef KING_H
#define KING_H

#include "Figure.h"

class King : public Figure
{
    public:
        King();
        King(std::string, bool, char, int);
        King(const King&);
        virtual void printName() const override;
        ~King();
};

#endif //KING_H