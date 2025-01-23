#include <stdio.h>
#include <stdlib.h>

typedef struct{
    float **m;
    int row;
    int col;
} matrix;

void creatMatrix(matrix *M){
    M->m = (float**)malloc((M->row)*sizeof(float*));
    for (int i = 0; i < M->row; i++){
        M->m[i] = (float*)malloc((M->col)*sizeof(float));
    }
}

void scanMatrix(FILE *f, matrix *M){
    fscanf(f, "%d%d", &M->row, &M->col);
    creatMatrix(M);
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

void freeMatrix(matrix *M){
    for (int i = 0; i < M->row; i++){
        free(M->m[i]);
    }
    free(M->m);
}

void gauss_jordan(matrix *M){
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
                float p = M->m[i][j]/M->m[j][j];
                for (int k = j; k < M->col; k++){
                    M->m[i][k] -= p*M->m[j][k];
                }
            }
        }
    }
}

void reverse(matrix *M){
    matrix tmp;
    tmp.row = M->row;
    tmp.col = (M->col)*2;
    creatMatrix(&tmp);

    for (int i = 0; i < tmp.row; i++){
        for (int j = 0; j < tmp.col; j++){
            if (j < M->col){
                tmp.m[i][j] = M->m[i][j];
            }
            else {
                if (j == i + M->col){
                    tmp.m[i][j] = 1;
                }
                else{
                    tmp.m[i][j] = 0;
                }
            }
        }
    }

    gauss_jordan(&tmp);

    for (int i = 0; i < M->row; i++){
        for (int j = 0; j < M->col; j++){
            M->m[i][j] = tmp.m[i][j + M->col];
        }
    }
    freeMatrix(&tmp);
}

int main(){
    FILE *f = fopen("data_input.txt", "r");
    FILE *g = fopen("data_output.txt", "w");

    matrix a;
    scanMatrix(f, &a);
    reverse(&a);

    printMatrix(g, &a);

    freeMatrix(&a);
    fclose(f);
    fclose(g);
}