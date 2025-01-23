// Bài 11
#include <stdio.h>
#include <stdlib.h>

int **creatMatrix(int m, int n){
    int **a = (int**)malloc(m*sizeof(int*));
    for (int i = 0; i < m; i++){
        a[i] = (int*)calloc(n, sizeof(int));
    }
    return a;
}

void printMatrix(int **a, int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void scanMatrix(int **a, int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &a[i][j]);
        }
    }
}

int **multiMatrix(int **a, int m, int n, int **b, int p, int q, int *flag){
    if (n == p) {
        *flag = 1;
        int **c = creatMatrix(m, q);
        for (int i = 0; i < m; i++){
            for (int j = 0; j < q; j++){
                for (int k = 0; k < n; k++){
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return c;
    }
    else {
        *flag = 0;
    }
    return NULL;
}

void freeMatrix(int **a, int m){
    for (int i = 0; i < m; i++){
        free(a[i]);
    }
    free(a);
}

int main(){
    int m, n, p, q, flag;
    scanf("%d%d", &m, &n);
    int **a = creatMatrix(m, n);
    scanMatrix(a, m, n);
    scanf("%d%d", &p, &q);
    int **b = creatMatrix(p, q);
    scanMatrix(b, p, q);
    int **c = multiMatrix(a, m, n, b, p, q, &flag);
    printf("%d\n", flag);
    printMatrix(c, m, q);
    freeMatrix(a, m);
    freeMatrix(b, p);
    freeMatrix(c, m);
}