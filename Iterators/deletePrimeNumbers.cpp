#include <iostream>
#include <vector>

bool is_prime(int num){
    if(num <= 1){
        return false;   
    }
    for(int i = 2 ; i * i <= num ; i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}

void print(const std::vector<int>& vec)
{
    for(auto it = vec.begin() ; it != vec.end() ; ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> myVec = {0, 10, 7, 2, 8, 23, 25, 26, 37, 28 , 29};
    print(myVec);
    std::vector<int>::iterator it = myVec.begin();
    while(it != myVec.end())
    {
        if(is_prime(*it))
        {
            it = myVec.erase(it);   
        }
        else
        {
            ++it;
        }
    }
    print(myVec);
    return 0;
}