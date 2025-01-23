// Bài 20
#include <stdio.h>

int poww(int x, int n){
    if (n == 0) return 1;
    if (n % 2 == 0) return poww(x, n/2) * poww(x, n/2);
    if (n % 2 != 0) return poww(x, (n - 1)/2) * poww(x, (n - 1)/2) * x;
}
int main(){
    int n, x;
    scanf("%d%d", &x, &n);
    printf("%d", poww(x, n));
}