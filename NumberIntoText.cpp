#include <iostream>
#include <string>
#include <map>

int main()
{
    std::map<int, std::string> nums;
    nums[1] = "one";
    nums[2] = "two";
    nums[3] = "three";
    nums[4] = "four";
    nums[5] = "five";
    nums[6] = "six";
    nums[7] = "seven";
    nums[8] = "eight";
    nums[9] = "nine";
    nums[10] = "ten";
    int n = 0;
    while(n == 0)
    {
        std::cout << "Enter a number between 1 and 10" << std::endl;
        std::cin >> n;
        if(n <= 0 || n > 10)
        {
            n = 0;
            std::cout << "Wrong number, try again" << std::endl;
        }
        else
        {
            std::cout << n << " is " << nums[n] << std::endl;
        }
    }
    return 0;
}