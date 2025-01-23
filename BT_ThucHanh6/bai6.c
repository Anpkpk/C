// Bài 6
#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b){
    if (b == 0) return a;
    else 
        return gcd(b, a % b);
}

int GCD(int n){
    int *A = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    int Gcd = A[0];
    for (int i = 1; i < n; i++){
        Gcd = gcd(Gcd, A[i]);
    }
    free(A);
    return Gcd;
}
int main(){
    int n;
    scanf("%d", &n);
    printf("%d", GCD(n));
}