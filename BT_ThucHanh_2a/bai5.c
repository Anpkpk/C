#include<stdio.h>

int main(){
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    int max = a, smax = b;
    if (b > max) max = b;
    if (c > max) max = c;
    if (d > max) max = d;
    if (b > smax && b < max){
        smax = b;
    }
    if (c > smax && c < max){
        smax = c;
    }
    if (d > smax && d < max){
        smax = d;
    }
    printf("%d", smax);
}