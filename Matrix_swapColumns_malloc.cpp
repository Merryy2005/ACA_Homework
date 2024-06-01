#include <iostream>
#include <cstdlib> 
#include <ctime>


void swap(int* a , int* b){
    int c = *b;
    *b = *a;
    *a = c;
    return;
}

void swapColumns(int** arr , const int size, int x , int y){
    for(int i = 0 ; i < size ; i++){
        swap(&arr[i][x] , &arr[i][y]);
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
    int x , y;
    std::cin >> x >> y;
    int** arr = nullptr;
    try{
        arr = (int**)malloc(size*sizeof(int*));
        if(arr == NULL){
            throw "Not enough memory";
        }
        for(int i = 0 ; i < size ; i++){
            arr[i] = (int*)malloc(size*sizeof(int));
            if(arr[i] == NULL){
                throw "Not enough memory";
            }
        }
    }
    catch(const char* s){
        std::cout << s << std::endl;
        return 1;
    }
    for(int i = 0 ; i < size ; i++){
        for(int j = 0 ; j < size ; j++){
            arr[i][j] = rand() % 101;
        }
    }
    std::cout << "Initial Array" << std::endl;
    print(arr , size);
    swapColumns(arr , size , x , y);
    std::cout << "Swapped Array" << std::endl;
    print(arr , size);
    for(int i = 0 ; i < size ; i++){
        free(arr[i]);
        arr[i] = nullptr;
    }
    free(arr);
    arr = nullptr; 
    return 0;
}