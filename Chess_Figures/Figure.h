#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <string>

class Figure
{
    protected:
        std::string m_color;
        bool m_isActive;
        char m_col; // A-H
        int m_row; // 1-8
        int m_point;
    public:
        Figure();
        Figure(std::string, bool, char, int);
        Figure(std::string, bool, char, int , int);
        Figure(const Figure&);
        char getCol() const;
        int getRow() const;
        std::string getColor() const;
        bool getState() const;
        int getPoint() const;
        void setCol(char);
        void setRow(int);
        void printParameters() const;
        virtual void printName() const = 0;
        virtual ~Figure();
};

#endif //FIGURE_H