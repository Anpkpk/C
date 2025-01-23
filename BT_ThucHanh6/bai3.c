// Bai 3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int a, b;
    scanf("%d%d", &a, &b);
    srand(time(NULL));
    int value = rand() % (b - a + 1) + a;
    printf("%d", value);
}