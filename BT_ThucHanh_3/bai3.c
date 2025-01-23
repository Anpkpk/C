#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int a[n], b[n], c[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    int i1 = 0, i2 = 0;
    for (int i = 0; i < n; i++){
        if (a[i] >= 0){
            b[i1] = a[i];
            i1++;
        } else {
            c[i2] = a[i];
            i2++;
        }
    }
    for (int i = 0; i < i1; i++){
        printf("%d ", b[i]);
    }
    printf("\n");
    for (int i = 0; i < i2; i++){
        printf("%d ", c[i]);
    }
}