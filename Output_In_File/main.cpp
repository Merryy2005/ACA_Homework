#include <iostream>
#include <fstream>

int main()
{
    std::ofstream file("output.txt");
    if (file.is_open())
    {
        std::streambuf* oldBuf = std::cout.rdbuf(file.rdbuf());
        std::cout << "Something" << std::endl;
        std::cout.rdbuf(oldBuf);
        file.close();
    }
    else
    {
        std::cerr << "Error opening file!" << std::endl;
    }
    return 0;
}
