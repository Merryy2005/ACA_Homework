#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

class Array
{
    private:
        int* m_arr;
        int m_size;
    public:
        Array();
        Array(int);
        Array(Array&);
        int getSize() const;
        int& operator[](int);
        int operator[](int) const;
        friend std::ostream& operator<< (std::ostream& , const Array&);
        ~Array();
};

#endif //ARRAY_H