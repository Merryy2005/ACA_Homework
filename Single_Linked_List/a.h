#ifndef A_H
#define A_H

#include <string>
#include <iostream>
////// forward declare magic:

namespace A{ class window; }    
void f(A::window rhs);

//////

namespace A {
    class window {
        private:
            int a;
            friend void ::f(window);
    };
}

void f(A::window rhs) {
    std::cout << rhs.a << std::endl;
}

#endif