#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int **a;
} matrix;

int **createMatrix(int m, int n){
    int **A = (int**)malloc(m*sizeof(int*));
    for (int i = 0; i < m; i++){
        A[i] = (int*)malloc(n*sizeof(int));
    }
    return A;
}

void fscanMatrix(FILE *f, matrix *M, int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            fscanf(f, "%d", &M->a[i][j]);
        }
    }
}

void fprintMatrix(FILE *g, matrix *M, int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            fprintf(g, "%d ", M->a[i][j]);
        }
        fprintf(g, "\n");
    }
}

void freeMatrix(matrix *M, int m){
    for (int i = 0; i < m; i++){
        free(M->a[i]);
    }
    free(M->a);
}

int main(){
    FILE *f = fopen("data9a.txt", "r");
    FILE *g = fopen("outp9a.txt", "w");

    matrix M;
    fscanf(f, "%d%d", &M.row, &M.col);
    M.a = createMatrix(M.row, M.col);

    fscanMatrix(f, &M, M.row, M.col);
    fprintMatrix(g, &M, M.row, M.col);
    
    freeMatrix(&M, M.row);
    fclose(f);
    fclose(g);
}