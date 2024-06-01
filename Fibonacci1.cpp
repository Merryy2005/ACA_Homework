#include <iostream>

int dp[40] = {0 , 0 , 1};

int fib(int n){
    if(n == 1){
        return 0;
    }
    if(n == 2){
        return 1;
    }
    if(!dp[n]){
        dp[n] = fib(n-1) + fib(n-2);
    }
    return dp[n];
}

int main(){
    for(int i = 1 ; i <= 15 ; i++){
        std::cout << fib(i) << " ";
    }
    std::cout << std::endl;
}