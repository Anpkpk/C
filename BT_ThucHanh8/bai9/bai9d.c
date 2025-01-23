#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float **m;
    int row;
    int col;
} matrix;

float **createMatrix(int row, int col){
    float **A = (float**)malloc(row*sizeof(float*));
    for (int i = 0; i < row; i++){
        A[i] = (float*)calloc(col, sizeof(float));
    }
    return A;
}

void setMatrix(FILE *f, matrix *M){
    fscanf(f, "%d", &M->row);
    M->col = M->row;

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

void Gauss_Jordan(matrix *M){
    for (int j = 0; j < M->row; j++){
        for (int i = j + 1; i < M->row; i++){
            if (M->m[j][j] != 0){
                float p = M->m[i][j] / M->m[j][j];
                for (int k = j; k < M->col; k++){
                    M->m[i][k] -= p*M->m[j][k];
                }
            }
        }
    }

    for (int i = 0; i < M->row; i++){
        if (M->m[i][i] != 0){
            float p = M->m[i][i];
            for (int j = i; j < M->col; j++){
                M->m[i][j] /= p;
            }
        }
    }

    for (int j = M->row - 1; j >= 0; j--){
        for (int i = j - 1; i >= 0; i--){
            if (M->m[j][j] != 0){
                float p = M->m[i][j] / M->m[j][j];
                for (int k = j; k < M->col; k++){
                    M->m[i][k] -= p*(M->m[j][k]);
                }
            }
        }
    }
}
void inversMatrix(matrix *M, matrix *invers){
    invers->m = createMatrix(M->row, 2*(M->col));
    invers->row = M->row;
    invers->col = 2*(M->col);
    for (int i = 0; i < invers->row; i++){
        for (int j = 0; j < M->col; j++){
            invers->m[i][j] = M->m[i][j];
        }
    }

    for (int i = 0; i < invers->row; i++){
        for (int j = M->col; j < invers->col; j++){
            if (j == i + M->col){
                invers->m[i][j] = 1;
            }
            else invers->m[i][j] = 0;
        }
    }
    Gauss_Jordan(invers);
    for (int i = 0; i < invers->row; i++){
        for (int j = 0; j < M->col; j++){
            M->m[i][j] = invers->m[i][j + M->col];
        }
    }
}

void freeMatrix(matrix *M, int r){
    for (int i = 0; i < M->row; i++){
        free(M->m[i]);
    }
    free(M->m);
}
int main(){
    FILE *f = fopen("data9d.txt", "r");
    FILE *g = fopen("outp9d.txt", "w");

    matrix a;
    setMatrix(f, &a);

    matrix b;
    inversMatrix(&a, &b);
    
    getMatrix(g, &a);

    freeMatrix(&a, a.row);
    freeMatrix(&b, b.row);
    fclose(f);
    fclose(g);
}