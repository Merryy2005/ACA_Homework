#include <iostream>
#include <cstdlib> 
#include <ctime>

void swap(int** a , int** b){
    int* c = *b;
    *b = *a;
    *a = c;
    return;
}

void swapRows(int** arr , int x , int y){
    swap(&arr[x] , &arr[y]);
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
    int x , y;
    std::cin >> x >> y;
    int** arr = new int*[size];
    for(int i = 0 ; i < size ; i++){
        arr[i] = new int[size];
    }
    for(int i = 0 ; i < size ; i++){
        for(int j = 0 ; j < size ; j++){
            arr[i][j] = rand() % 101;
        }
    }
    std::cout << "Initial Array" << std::endl;
    print(arr , size);
    swapRows(arr , x , y);
    std::cout << "Swapped Array" << std::endl;
    print(arr , size);
    for(int i = 0 ; i < size ; i++){
        delete[] arr[i];
        arr[i] = nullptr;
    }
    delete[] arr;
    arr = nullptr; 
    return 0;
}