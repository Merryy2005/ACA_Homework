#ifndef SHARED_PTR
#define SHARED_PTR

#include <iostream>

template <typename T>
class SharedPtr {
    private:
        T* m_ptr;                   
        int* m_count;       
public:
    SharedPtr();
    SharedPtr(T*);
    SharedPtr(const SharedPtr&);
    SharedPtr& operator=(const SharedPtr&);
    T* get() const;
    int use_count() const;
    T& operator*() const;
    T* operator->() const;
    ~SharedPtr();
private:
    void release();
};

template<typename T>
SharedPtr<T>::SharedPtr() : m_ptr(nullptr) , m_count(new int(1))
{

}

template<typename T>
SharedPtr<T>::SharedPtr(T* ptr) : m_ptr(ptr) , m_count(new int(1))
{

}

template<typename T>
SharedPtr<T>::SharedPtr(const SharedPtr& other) : m_ptr(other.m_ptr) , m_count(other.m_count)
{
    (*m_count)++;
}

template<typename T>
SharedPtr<T>& SharedPtr<T>::operator=(const SharedPtr& other)
{
    if (this != &other) 
    {
        release(); 
        m_ptr = other.m_ptr;
        m_count = other.m_count;
        (*m_count)++;
    }
    return *this;
}

template<typename T>
T* SharedPtr<T>::get() const
{
    return m_ptr;
}

template<typename T>
int SharedPtr<T>::use_count() const
{
    return *m_count;
}

template<typename T>
T& SharedPtr<T>::operator*() const
{
    return *m_ptr;
}

template<typename T>
T* SharedPtr<T>::operator->() const
{
    return m_ptr;
}

template<typename T>
SharedPtr<T>::~SharedPtr()
{
    release();
}

template<typename T>
void SharedPtr<T>::release()
{
    --(*m_count);
    if (*(m_count) == 0) 
    {
            delete m_ptr;         
            delete m_count;   
            m_ptr = nullptr;
            m_count = nullptr;
    }
}

#endif // SHARED_PTR