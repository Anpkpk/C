#include <stdio.h>

int main() {
    int n, space;
 
    scanf("%d", &n);

    space = n - 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= space; j++) {
            printf(" ");
        }
        space--;

        for (int j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }

    space = n - 1;

    for (int i = 1; i <= n / 2 + 1 ; i++) {
        printf(" ");
    }
    printf("| | |");
    return 0;
}