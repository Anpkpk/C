#include <stdio.h>
#include <stdlib.h>

typedef struct
{   
    int **m;
    int row;
    int col;
} matrix;

void createMatrix(matrix *M){
    M->m = (int**)malloc((M->row)*sizeof(int*));
    for (int i = 0; i < M->row; i++){
        M->m[i] = (int*)malloc((M->col)*sizeof(int));
    }
}

void scanMatrix(FILE *f, matrix *M){
    fscanf(f, "%d%d", &M->row, &M->col);
    createMatrix(M);
    for (int i = 0; i < M->row; i++){
        for (int j = 0; j < M->col; j++){
            fscanf(f, "%d", &M->m[i][j]);
        }
    }
}

void printMatrix(FILE *g, matrix *M, int *flag){
    fprintf(g, "%d\n", *flag);
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

void multMatrix(matrix *a, matrix *b, matrix *c, int *flag){
    if (a->col == b->row){
        *flag = 1;
        c->row = a->row;
        c->col = b->col;
        createMatrix(c);
        for (int i = 0; i < a->row; i++){
            for (int j = 0; j < b->col; j++){
                c->m[i][j] = 0;
                for (int k = 0; k < a->col; k++){
                    c->m[i][j] += a->m[i][k]*b->m[k][j];
                }
            }
        }
    }
    else {
        *flag = 0;
        c = NULL;
    }
}

int main(){
    FILE *f = fopen("data_input.txt", "r");
    FILE *g = fopen("data_output.txt", "w");

    matrix a, b, c;
    int flag;
    scanMatrix(f, &a);
    scanMatrix(f, &b);

    multMatrix(&a, &b, &c, &flag);
    printMatrix(g, &c, &flag);

    freeMatrix(&a);
    freeMatrix(&b);
    freeMatrix(&c);
    fclose(f);
    fclose(g);
}