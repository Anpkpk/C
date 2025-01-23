// Bài 12
#include <stdio.h>
#include <stdlib.h>

int **creatMatrix(int m, int n){
    int **a = (int**)malloc(m*sizeof(int*));
    for (int i = 0; i < m; i++){
        a[i] = (int*)calloc(n, sizeof(int));
    }
    return a;
}

void scanMatrix(int **a, int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &a[i][j]);
        }
    }
}

void printMatrix(int **a, int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapRow(int **a, int m, int n, int u, int v){
    for (int i = 0; i < n; i++){
        swap(&a[u - 1][i], &a[v - 1][i]);        
    }
}

void freeMatrix(int **a, int m){
    for (int i = 0; i < m; i++){
        free(a[i]);
    }
    free(a);
}

int main(){
    int m, n, u, v;
    scanf("%d%d", &m, &n);
    int **a = creatMatrix(m, n);
    scanMatrix(a, m, n);
    scanf("%d%d", &u, &v);
    swapRow(a, m, n, u, v);
    printMatrix(a, m, n);
    freeMatrix(a, m);
}