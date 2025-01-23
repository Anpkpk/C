#include <stdio.h>

int main(){
    int a, b, c, d, e;
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
    int cnt = 1;
    if (b == a) cnt++;
    if (c == a) cnt++;
    if (d == a) cnt++;
    if (c == b) cnt++;
    if (d == c) cnt++;
    if (e == d) cnt++;
    if (cnt == 4) {
        printf("FOUR OF HIGHT CARD!");
    }
    else{
        printf("HIGHT CARD");
    }
}