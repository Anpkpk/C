#include <stdio.h>

int main(){
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    int max = a, min = b;
    if (b >= max) max = b; 
    if (c >= max) max = c;
    if (d >= max) max = d;
    if (a <= min) min = a;
    if (c <= min) min = c;
    if (d <= min) min = d;
    printf("%d %d", min, max);
}