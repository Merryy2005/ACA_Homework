#include <iostream>
#include <cstdlib> 
#include <ctime>

void fill(int** arr ,const int size){
    for(int i = 0 ; i < size ; i++){
        for(int j = 0 ; j < size ; j++){
            arr[i][j] = rand();
        }
    }
    return;
}

void print(int** arr ,const int size){
    for(int i = 0 ; i < size ; i++){
        for(int j = 0 ; j < size ; j++){
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return;
}

int main(){
    srand(time(0));
    int size;
    std::cin >> size;
    int** arr = new int*[size];
    for(int i = 0 ; i < size ; i++){
        arr[i] = new int[size];
    }
    fill(arr , size);
    print(arr , size);
    for(int i = 0 ; i < size ; i++){
        delete[] arr[i];
        arr[i] = nullptr;
    }
    delete[] arr;
    arr = nullptr;  
    return 0;
}