#include <iostream>
#include <list>

double median(const std::list<int>& list)
{
    double sum = 0;
    int size = 0;
    for(auto it = list.begin() ; it != list.end() ; ++it)
    {
        sum += *it;
        size++;
    }
    return (sum / size); 
}

void print(const std::list<int>& list)
{
    for(auto it = list.begin() ; it != list.end() ; ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::list<int> myList = {0, 10, 7, 2, 8, -2, 2, 6, 7, 9 , 4};
    print(myList);
    std::list<int>::iterator it = myList.begin();
    double med = median(myList);
    std::cout << "median = " << med << std::endl;
    while(it != myList.end())
    {
        if(*it < med)
        {
            it = myList.erase(it);   
        }
        else
        {
            ++it;
        }
    }
    print(myList);
    return 0;
}