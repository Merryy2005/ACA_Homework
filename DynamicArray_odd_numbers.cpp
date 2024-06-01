#include <iostream>
#include <cstdlib> 
#include <ctime>

int* Create(const int* arr , const int size ,const int size1){
    int* arr1 = new int[size1];
    int ind = 0;
    for(int i = 0 ; i < size ; i++){
        if(arr[i] % 2){
            arr1[ind++] = arr[i];
        }
    }
    return arr1;
}

void Print(const int* arr , const int size){
    for(int i = 0 ; i < size ; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return;
}

int main(){
    srand(time(0));
    int size;
    int size1 = 0;
    std::cin >> size;
    int* arr = new int[size];
    for(int i = 0 ; i < size ; i++){
        arr[i] = rand();
        size1 += arr[i] % 2;
    }
    int* arr1 = Create(arr , size ,size1);
    Print(arr , size);
    Print(arr1 , size1);  
    delete[] arr;
    delete[] arr1;
    return 0;
}