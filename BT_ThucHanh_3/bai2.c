#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    // int a[n];
    // a[0] = 0; a[1] = 1; a[2] = 1;
    // for (int i = 3; i <= n; i++){
    //     a[i] = a[i - 1] + a[i - 2];
    // }
    // printf("%d", a[n]);
    int f0 = 0, f1 = 1, i = 1, fn;
    while (i < n){
        fn = f0 + f1;
        i++;
        f0 = f1;
        f1 = fn;
    } 
    printf("%d", fn);
}