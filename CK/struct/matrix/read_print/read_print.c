#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int **m;
    int row;
    int col;
} matrix;

void scanMatrix(FILE *f, matrix *M){
    fscanf(f, "%d%d", &M->row, &M->col);
    M->m = (int**)malloc((M->row)*sizeof(int*));
    for (int i = 0; i < M->row; i++){
        M->m[i] = (int*)malloc((M->col)*sizeof(int));
    }
    for (int i = 0; i < M->row; i++){
        for (int j = 0; j < M->col; j++){
            fscanf(f, "%d", &M->m[i][j]);
        }
    }
}

void printMatrix(FILE *g, matrix *M){
    for (int i = 0; i < M->row; i++){
        for (int j = 0; j < M->col; j++){
            fprintf(g, "%d ", M->m[i][j]);
        }
        fprintf(g, "\n");
    }
}

void freeMatrix(matrix *M){
    for (int i = 0; i < M->row; i++){
        free(M->m[i]);
    }
    free(M->m);
}

int main(){
    FILE *f = fopen("data_input.txt", "r");
    FILE *g = fopen("data_output.txt", "w");

    matrix M;
    scanMatrix(f, &M);
    printMatrix(g, &M);

    freeMatrix(&M);
    fclose(f);
    fclose(g);
}