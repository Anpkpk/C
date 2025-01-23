#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print(int *a, int n){
    for (int i = 1; i <= n; i++){
        printf("%d", a[i]);
    }
    printf("\n");
}

void try(int *bool, int *a, int n, int k){
    for (int i = 1; i <= n; i++){
        if (!bool[i]){
            a[k] = i;
            bool[i] = 1;
            if (k == n){
                print(a, n);
            }
            else {
                try(bool, a, n, k + 1);
            }
            bool[i] = 0;
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);

    int *a = (int*)calloc(n, sizeof(int));
    int *bool = (int*)calloc(n, sizeof(int));

    try(bool, a, n, 1);

    free(a);
    free(bool);
}