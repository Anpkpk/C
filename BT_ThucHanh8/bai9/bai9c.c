#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    float **m;
} matrix;

float **createMatrix(int row, int col){
    float **A = (float**)malloc(row*sizeof(float*));
    for (int i = 0; i < row; i++){
        A[i] = (float*)malloc(col*sizeof(float));
    }
    return A;
}

void setMatrix(FILE *f, matrix *M){
    fscanf(f, "%d%d", &M->row, &M->col);
    M->m = createMatrix(M->row, M->col);
    for (int i = 0; i < M->row; i++){
        for (int j = 0; j < M->col; j++){
            fscanf(f, "%f", &M->m[i][j]);
        }
    }     
}

void getMatrix(FILE *g, matrix *M){
    for (int i = 0; i < M->row; i++){
        for (int j = 0; j < M->col; j++){
            fprintf(g, "%.2f ", M->m[i][j]);
        }
        fprintf(g, "\n");
    }  
}

void Gauss(matrix *M){
    for (int j = 0; j < M->row; j++){
        for (int i = j + 1; i < M->row; i++){
            if (M->m[j][j] != 0){
                float fact = M->m[i][j] / M->m[j][j];
                for (int k = j; k < M->col; k++){
                    M->m[i][k] -= fact*M->m[j][k];
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
    matrix M;

    FILE *f = fopen("data9c.txt", "r");
    FILE *g = fopen("outp9c.txt", "w");

    setMatrix(f, &M);
    Gauss(&M);
    getMatrix(g, &M);

    freeMatrix(&M);
    fclose(f);
    fclose(g);
}