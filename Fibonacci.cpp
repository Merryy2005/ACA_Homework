#include <iostream>

int fibonacci(int n){
    if(n == 1){
        return 0;
    }
    if(n == 2){
        return 1;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

int fibonacci_optimized(int n){
    if(n == 1){
        return 0;
    }
    if(n == 2){
        return 1;
    }
    int a = 0 , b = 1;
    for(int i = 3 ; i <= n ; i++){
        b = a + b;
        a = b - a;
    }
    return b;
}

int main(){
    for(int i = 1 ; i <= 15 ; i++){
        std::cout << fibonacci(i) << " ";
    }
    std::cout << std::endl;
    for(int i = 1 ; i <= 15 ; i++){
        std::cout << fibonacci_optimized(i) << " ";
    }
    return 0;
}