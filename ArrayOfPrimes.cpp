#include <iostream>

bool is_prime(int num){
    if(num == 1){
        return 0;   
    }
    for(int i = 2 ; i * i <= num ; i++){
        if(num % i == 0){
            return 0;
        }
    }
    return 1;
}

int* create(int** arr , const int n , const int m , const int count){
    int* primes = nullptr;
    try{
        primes = (int*)malloc(count * sizeof(int));
        if(primes == nullptr){
            throw "Not enough memory";
        }
    }
    catch(const char* s){
        std::cout << s << std::endl;
        return nullptr;
    }
    int k = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(is_prime(arr[i][j])){
                primes[k++] = arr[i][j];
            }
        }
    }
    return primes;
}

void print(int* arr , const int n){
    for(int i = 0 ; i < n ; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return;
}

int main(){
    int n , m;
    std::cin >> n >> m;
    int** arr = nullptr;
    try{ 
        arr = (int**)malloc(n * sizeof(int*));
        if(arr == nullptr){
            throw "Not enough memory";
        }
        for(int i = 0 ; i < n ; i++){
            arr[i] = (int*)malloc(m*sizeof(int));
            if(arr[i] == nullptr){
                throw "Not enough memory";
            }
        }
    }
    catch(const char* s){
        std::cout << s << std::endl;
        return 1;
    }
    int count = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            std::cin >> arr[i][j];
            count += is_prime(arr[i][j]);
        }
    }
    int* primes = create(arr , n , m , count);
    if(primes == nullptr){
        return 1;
    }
    print(primes , count);
    for(int i = 0 ; i < n ; i++){
        free(arr[i]);
        arr[i] = nullptr;
    }
    free(arr);
    free(primes);
    arr = nullptr;
    primes = nullptr;
    return 0;
}