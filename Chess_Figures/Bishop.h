#ifndef BISHOP_H
#define BISHOP_H

#include "Figure.h"

class Bishop : public Figure
{
    public:
        Bishop();
        Bishop(std::string, bool, char, int);
        Bishop(const Bishop&);
        virtual void printName() const override;
        ~Bishop();
};

#endif //BISHOP_H