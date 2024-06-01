#include "Zoo.h"

Zoo* Zoo::s_ptr = nullptr;

Zoo::Zoo(int size) : m_size(size) , m_animals(new Animal*[size])
{
    for(int i = 0 ; i < m_size ; i++)
    {
        if(i % 5 == 0)
        {
            m_animals[i] = new Bear(1 , 10);
        }
        if(i % 5 == 1)
        {
            m_animals[i] = new Elephant(3 , 105.5);        
        }
        if(i % 5 == 2)
        {
            m_animals[i] = new Giraffe(6 , 70);
        }
        if(i % 5 == 3)
        {
            m_animals[i] = new Lion(5 , 100.7);
        }
        if(i % 5 == 4)
        {
            m_animals[i] = new Tiger(8 , 101.1);
        }
    }
}

Zoo::~Zoo()
{
    
}

Zoo* Zoo::getZoo(int size)
{
    if(Zoo::s_ptr == nullptr)
    {
        Zoo::s_ptr = new Zoo(size);
    }
    return Zoo::s_ptr;
}

void Zoo::printZoo() const
{
    for(int i = 0 ; i < m_size ; i++)
    {
        m_animals[i]->print();
        std::cout << "-----------" << std::endl;
    }
}

void Zoo::deleteZoo()
{
    for(int i = 0 ; i < s_ptr -> m_size ; i++)
    {
        delete s_ptr -> m_animals[i];
    }
    delete[] s_ptr -> m_animals;
    s_ptr -> m_animals = nullptr;
    delete s_ptr;
    s_ptr = nullptr;
}


