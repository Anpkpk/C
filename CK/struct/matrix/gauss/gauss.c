#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float **m;
    int row;
    int col;
} matrix;

void createMatrix(matrix *M){
    M->m = (float**)malloc((M->row)*sizeof(float*));
    for (int i = 0; i < M->row; i++){
        M->m[i] = (float*)malloc((M->col)*sizeof(float));
    }
}

void scanMatrix(FILE *f, matrix *M){
    fscanf(f, "%d%d", &M->row, &M->col);
    createMatrix(M);
    for (int i = 0; i < M->row; i++){
        for (int j = 0; j < M->col; j++){
            fscanf(f, "%f", &M->m[i][j]);
        }
    }
}

void printMatrix(FILE *g, matrix *M){
    for (int i = 0; i < M->row; i++){
        for (int j = 0; j < M->col; j++){
            fprintf(g, "%.2f ", M->m[i][j]);
        }
        fprintf(g, "\n");
    }
}

void gauss(matrix *M){
    for (int j = 0; j < M->row; j++){
        for (int i = j + 1; i < M->row; i++){
            if (M->m[j][j] != 0){
                float p = M->m[i][j]/M->m[j][j];
                for (int k = j; k < M->col; k++){
                    M->m[i][k] -= p*M->m[j][k];
                }
            }
        }
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

    matrix a;
    
    scanMatrix(f, &a);
    gauss(&a);

    printMatrix(g, &a);

    freeMatrix(&a);
    fclose(f);
    fclose(g);
}