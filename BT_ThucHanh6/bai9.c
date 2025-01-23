// Bài 9
#include <stdio.h>
#include <stdlib.h>

float legendre(float n, float x){
    if (n == 0) return 1;
    if (n == 1) return x;
    else return (2*n - 1)/(n) * x * legendre(n - 1, x) - ((n - 1)/n) * legendre(n - 2, x); 

}
int main(){
    float n, x;
    scanf("%f%f", &n, &x);
    float answer = legendre(n, x);
    printf("%f", answer);
}