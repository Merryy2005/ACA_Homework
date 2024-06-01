#include "Array.h"

int main()
{
    Array arr(10);
    std::cout << arr;
    arr[1] = 21;
    std::cout << arr;
    const Array arr1(12);
    std::cout << arr1;
    //arr1[1] = 8;  error
    return 0;
}