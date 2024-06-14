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
    std::cout << "Enter a number between 1 and 10" << std::endl;
    int n;
    std::cin >> n;
    std::cout << n << " is " << nums[n] << std::endl;
    return 0;
}