// Bài 21
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
    if (a > b) return  a;
    return b;
}

int maxElement(int *L, int n){
    int Max = 1;
    for (int i = 0; i < n; i++){
        if (L[i] > Max) Max = L[i];
    }
    return Max;
}

int LIS(int n){
    int *a = (int*)calloc(n, sizeof(int));
    int L[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        L[i] = 1;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < i; j++){
            if (a[i] > a[j]){
                L[i] = max(L[i], L[j] + 1);
            }
        }
    }
    free(a);
    return maxElement(L, n);
}
int main(){
    int n;
    scanf("%d", &n);
    printf("%d", LIS(n));
}