// Bài 1
#include <stdio.h>
#include <stdlib.h>

int *scanArray(int n){
    int *A;
    A = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++){
        scanf("%d", A + i);
    }
    return A;
}
int max(int *a, int n){
    int Max = a[0];
    for (int i = 0; i < n; i++){
        if (*(a + i) >= Max){
            Max = *(a + i);
        }
    }
    return Max;
}
int main(){
    int n;
    scanf("%d", &n);
    int *a = scanArray(n);
    printf("%d", max(a, n));
    free(a);
}