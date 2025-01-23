#include <stdio.h>

int main(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (a <= 0 || b <= 0|| c <= 0){
        printf("NO");
    } else if (a + b > c && a + c > b && c + b > a){
        printf("YES");
        if (a == b || a == c || b == c){
            printf("\ncan");
        } else if (a == b == c){
            printf("\ndeu");
        } else if (a*a + b*b == c*c){
            printf("\nvuong");
        } else {
            printf("\nthuong");
        }
    }
}