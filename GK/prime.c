#include <stdio.h>

int prime(int n){
    if (n == 1 || n == 0) return 0;
    for (int i = 2; i < n/2; i++){
        if (n % i == 0) return 0;
    }
    return 1;
}

int checkPrime(int n){
    int check = 1;
    n = 3;
    while (check == 1){
        if (prime(n) && prime(n*n + 4) && prime(n*n + 6)){
            check = 0;
            return n;
        }
        else n++;
    }
    return check;
}

int main(){
    int n = 3;
    int answer = checkPrime(n);
    printf("%d\n", answer);
}