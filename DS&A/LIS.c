// day con tang dai nhat
// L[i] : L[j]
// L[i] = max(L[i], L[j] + 1) : a[i] > a[j]
#include <stdio.h>

int max(int a, int b){
    if (a > b) return a;
    return b;
}

int max_element(int *L, int n){
    int Max = 1;
    for (int i = 0; i < n; i++){
        if (L[i] > Max){
            Max = L[i];
        }
    }
    return Max;
}

int main(){
    int n;
    scanf("%d", &n);
    int a[n], L[n];
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
    
    printf("%d", Max);
}