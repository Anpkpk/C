#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int lis[n];
    for (int i = 0; i < n; i++){
        lis[i] = 1;
        for (int j = 0; j < i; j++){
            if (a[i] > a[j] && lis[i] < lis[j] + 1){
                lis[i] = lis[j] + 1;
            }
        }
    }

    int max = lis[0];
    for (int i = 0; i < n; i++){
        if (lis[i] > max) max = lis[i];
    }
    printf("%d", max);
}