#include <iostream>

int main(){
    int size = 10;
    int* arr = new int[size];
    for(int i = 0 ; i < size ; i++){
        std::cin >> arr[i];
    }
    delete[] arr;
}