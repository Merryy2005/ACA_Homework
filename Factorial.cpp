#include <iostream>

int factorial(int num){ //recursive
    if(num <= 1){
        return 1;
    }
    return num * factorial(num-1);
}

int factorial_optimized(int num){ //iterative
    int ans = 1;
    for(int i = 2 ; i <= num ; i++){
        ans *= i;
    }
    return ans;
}

int main(){
    for(int i = 0 ; i < 10 ; i++){
        std::cout << "factorial of " << i << " is " << factorial(i) << std::endl;
    }
    for(int i = 0 ; i < 10 ; i++){
        std::cout << "factorial of " << i << " is " << factorial_optimized(i) << std::endl;
    }
    return 0;
}