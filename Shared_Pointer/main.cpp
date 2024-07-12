#include <iostream>
#include "Shared_Pointer.hpp"

int main() 
{
    SharedPtr<int> sp1(new int(10));
    std::cout << *sp1 << " " << sp1.use_count() << std::endl;
    SharedPtr<int> sp2 = sp1; 
    std::cout << *sp2 << " " << sp2.use_count() << std::endl;
    std::cout << sp1.use_count() << std::endl;
    return 0;
}
