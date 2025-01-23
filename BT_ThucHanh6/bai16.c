// Bài 17
#include <stdio.h>
#include <stdlib.h>

int KC(int n, int rA, int rAb){
    if (rAb == rA) {
        if (n == rA) return 1;
        else return 2;
    }
    else return 0;
}
int main(){
    int n, rA, rAb;
    scanf("%d%d%d", &n, &rA, &rAb);
    printf("%d", KC(n, rA, rAb));
}