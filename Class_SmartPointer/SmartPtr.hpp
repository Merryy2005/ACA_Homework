#ifndef SMARTPTR_H
#define SMARTPTR_H

template<typename T>
class SmartPtr
{
    private:
        T* m_ptr;
    public:
        SmartPtr();
        SmartPtr(T*);
        T& operator*();
        T* operator->();
        ~SmartPtr();
};

template<typename T>
SmartPtr<T>::SmartPtr() : m_ptr(nullptr)
{

}

template<typename T>
SmartPtr<T>::SmartPtr(T* ptr) : m_ptr(ptr)
{
    
}

template<typename T>
T& SmartPtr<T>::operator*()
{
    return *m_ptr;
}

template<typename T>
T* SmartPtr<T>::operator->()
{
    return m_ptr;
}

template<typename T>
SmartPtr<T>::~SmartPtr()
{
    delete m_ptr;
    m_ptr = nullptr;
}

#endif // SMARTPTR_H