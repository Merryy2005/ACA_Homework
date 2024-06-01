#include <iostream>

void* operator new(size_t size){
    std::cout << "Hello World" << std::endl;
    void* ptr = nullptr;
    try{
        ptr = malloc(size);
        if(ptr == NULL){
            throw "Not enough memory";
        }
    }
    catch(const char* s){
        std::cout << s << std::endl;
    }
    return ptr;
}

int main(){
    char* ptr = new char('d');
    std::cout << *ptr << std::endl;
    int* a = new int(4);
    std::cout << *a << std::endl;
    delete ptr;
    delete a;
}