#include <stdio.h>

int main(){
    int sum = 0;
    int x;
    do{
        scanf("%d", &x);
        sum += x;
    }
    while (x != 0);
    printf("%d", sum);
}