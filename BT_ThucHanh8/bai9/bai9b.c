#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int **m;
} matrix;

int **createMatrix(int m, int n){
    int **A = (int**)malloc(m*sizeof(int*));
    for (int i = 0; i < m; i++){
        A[i] = (int*)malloc(n*sizeof(int));
    }
    return A;
}

void fscanMatrix(FILE *f, matrix *M){
    fscanf(f, "%d%d", &M->row, &M->col);
    M->m = createMatrix(M->row, M->col);
    for (int i = 0; i < M->row; i++){
        for (int j = 0; j  < M->col; j++){
            fscanf(f, "%d", &M->m[i][j]);
        }
    }
}

void fprintMatrix(FILE *g, matrix *M){
    for (int i = 0; i < M->row; i++){
        for (int j = 0; j < M->col; j++){
            fprintf(g, "%d ", M->m[i][j]);
        }
        fprintf(g, "\n");
    }
}

void freeMatrix(matrix *M, int hang){
    for (int i = 0; i < hang; i++){
        free(M->m[i]);
    }
    free(M->m);
}

void multiMatrix(matrix *a, matrix *b, matrix *c, int *flag){
    if (a->col == b->row){
        c->row = a->row;
        c->col = b->col;
        c->m = createMatrix(c->row, c->col);
        *flag = 1;
        for (int i = 0; i < a->row; i++){
            for (int j = 0; j < b->col; j++){
                c->m[i][j] = 0;
                for (int k = 0; k < a->col; k++){
                    c->m[i][j] += a->m[i][k] * b->m[k][j];
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

    matrix a;
    matrix b;

    FILE *f = fopen("data9b.txt", "r");
    FILE *g = fopen("outp9b.txt", "w");
    
    fscanMatrix(f, &a);
    fscanMatrix(f, &b);

    int flag;
    matrix c;
    
    multiMatrix(&a, &b, &c, &flag);

    if (&c != NULL){
        fprintf(g, "%d\n", flag);
        fprintMatrix(g, &c);
        freeMatrix(&c, c.row);
    }
    else{
        fprintf(g, "%d", flag);
    }

    freeMatrix(&a, a.row);
    freeMatrix(&b, b.row);

    fclose(f);
    fclose(g);
}