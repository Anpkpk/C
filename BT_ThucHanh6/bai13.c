// Bài 13
#include <stdio.h>
#include <stdlib.h>

int **creatMatrix(int m, int n){
    int **a = (int**)malloc(m*sizeof(int*));
    for (int i = 0; i < m; i++){
        a[i] = calloc(n, sizeof(int));
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

int **extended(int **a, int **b, int m, int n, int p){
    int **c = realloc(a, (m)*sizeof(int*));
    for (int i = 0; i < m; i++){
        c[i] = realloc(a[i], (n + p)*sizeof(int));
    }
    for (int i = 0; i < m; i++){
        for (int j = n; j < n + p; j++){
            c[i][j] = b[i][j - n];
        }
    }
    return c;
}

void freeMatrix(int **a, int m){
    for (int i = 0; i < m; i++){
        free(a[i]);
    }
    free(a);
}

int main(){
    int m, n, p;
    scanf("%d%d%d", &m, &n, &p);
    int **a = creatMatrix(m, n);
    scanMatrix(a, m, n);
    int **b = creatMatrix(m, p);
    scanMatrix(b, m, p);
    int **c = extended(a, b, m, n, p);
    printMatrix(c, m, n + p);
    freeMatrix(a, m);
    freeMatrix(b, m);
    freeMatrix(c, m);
}