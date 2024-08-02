#include <iostream>
#include <fstream>

int main()
{
    std::ofstream file("output.txt");
    if (file.is_open())
    {
        std::cout.rdbuf(file.rdbuf());
        std::cout << "Something" << std::endl;
        file.close();
    }
    else
    {
        std::cerr << "Error opening file!" << std::endl;
    }
    return 0;
}
