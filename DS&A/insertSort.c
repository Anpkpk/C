#include <stdio.h>

int main(){
    int n, key;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    int i;
    
    for (int j = 1; j < n; j++){
        key = a[j];
        i = j - 1;
        while (i >= 0 && a[i] > key){
            a[i + 1] = a[i];
            i--;
            a[i + 1] = key;
        }
    }
    for (int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
}