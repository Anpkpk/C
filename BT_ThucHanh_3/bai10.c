#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    int lis_length[n];
    int maxLength = 0;
    for (int i = 0; i < n; i++){
        lis_length[i] = 1;
    }
    for (int i = 1; i < n; i++){
        for (int j = 0; j < i; j++){
            if (a[i] > a[j] && lis_length[i] < lis_length[j] + 1){
                lis_length[i] = lis_length[j] + 1;
            }
        }
    }
    for (int i = 0; i < n; i++){
        if (lis_length[i] >= maxLength){
            maxLength = lis_length[i];
        }
    }
    printf("%d", maxLength);
}
