// Bài 10
#include <stdio.h>
#include <stdlib.h>

int **scanMatrix(int m, int n){
    int **a = (int**)calloc(m, sizeof(int*));
    for (int i = 0; i < m; i++){
        a[i] = (int*)calloc(n, sizeof(int));
    }
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &a[i][j]);
        }
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

void freeMatrix(int **a, int n){
    for (int i = 0; i < n; i++){
        free(a[i]);
    }
    free(a);
}
int main(){
    int m, n;
    scanf("%d%d", &m, &n);
    int **A = scanMatrix(m, n);
    printMatrix(A, m, n);
    freeMatrix(A, n);
}