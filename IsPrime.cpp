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

int main(){
    for(int i = 1 ; i <= 20 ; i++){
        if(is_prime(i)){
            std::cout << i << " is a prime number" << std::endl;
        }
        else{
            std::cout << i << " is not a prime number" << std::endl;
        }
    }
    return 0;
}