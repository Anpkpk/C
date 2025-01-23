#include <stdio.h>

int calculate_pascal_value(int i, int j){
    if (j == 0 || j == i){
        return 1;
    } 
    else return calculate_pascal_value(i - 1, j - 1) + calculate_pascal_value(i - 1, j);
}

void pascal_triagle(int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= i; j++){
            printf("%d ", calculate_pascal_value(i, j));
        }
        printf("\n");
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int a[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (j == 0 || j == i){
                a[i][j] = 1;
            }
            else if (j < i){
                a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
            }
            else{
                a[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= i; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    //pascal_triagle(n);
}