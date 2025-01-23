#include <stdio.h>
#include <stdlib.h>

int **createMatrix(int m, int n){
    int **a = (int**)malloc(m*sizeof(int*));
    for (int i = 0; i < m; i++){
        a[i] = (int*)malloc(n*sizeof(int));
    }
    return a;
}

void scanMatrix(FILE *f, int **a, int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            fscanf(f, "%d", &a[i][j]);
        }
    }
}

void printMatrix(FILE *g, int **a, int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            fprintf(g, "%d ", a[i][j]);
        }
        fprintf(g, "\n");
    }
}

void freeMatrix(int **a, int m){
    for (int i = 0; i < m; i++){
        free(a[i]);
    }
    free(a);
}

int **multMatrx(int **a, int m, int n, int **b, int p, int q){
    if (n != p) return NULL;
    int **c = createMatrix(m, q);

    for (int i = 0; i < m; i++){
        for (int j = 0; j < q; j++){
            c[i][j] = 0;
            for (int k = 0; k < n; k++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

int main(){
    FILE *f = fopen("mult_in.txt", "r");
    FILE *g = fopen("mult_out.txt", "w");

    int m, n, p, q;
    fscanf(f, "%d%d", &m, &n);
    int **a = createMatrix(m, n);
    scanMatrix(f, a, m, n);

    fscanf(f, "%d%d", &p, &q);
    int **b = createMatrix(p, q);
    scanMatrix(f, b, p, q);

    int **c = multMatrx(a, m, n, b, p, q);
    if (c != NULL) {
        fprintf(g, "1\n");
        printMatrix(g, c, m, q);
    }
    else {
        fprintf(g, "0");
    }

    freeMatrix(a, m);
    freeMatrix(b, p);
    freeMatrix(c, m);
    fclose(f);
    fclose(g);
}