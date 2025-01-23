#include <stdio.h>
#include <stdlib.h>

int **createMatrix(int m, int n){
    int **a = (int**)malloc(m*sizeof(int*));
    for (int i = 0; i < m; i++){
        a[i] = (int*)malloc(n*sizeof(int));
    }
    return a;
}

void scan(FILE *f , int **a, int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            fscanf(f, "%d", &a[i][j]);
        }
    }
}

void print(FILE *g, int **a, int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            fprintf(g, "%d ", a[i][j]);
        }
        fprintf(g, "\n");
    }
}

void mulMatrix(int **c, int **a, int **b, int m, int n, int p, int q){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < q; j++){
            c[i][j] = 0;
            for (int k = 0; k < n; k++){
                c[i][j] += a[i][k]*b[k][j];
            }
        }
    }
}

void freeMatrix(int **a, int m){
    for (int i = 0; i < m; i++){
        free(a[i]);
    }
    free(a);
}

int main(){
    int m, n, p, q;
     
    FILE *f = fopen("data5.txt", "r");
    FILE *g = fopen("outp5.txt", "w");

    fscanf(f, "%d%d", &m, &n);
    int **a = createMatrix(m, n);
    scan(f, a, m, n);

    fscanf(f, "%d%d", &p, &q);
    int **b = createMatrix(p, q);
    scan(f, b, p, q);

    if (n == p){
        int **c = createMatrix(m, q);
        mulMatrix(c, a, b, m, n, p, q);
        print(g, c, m, q);
        freeMatrix(c, m);
    }
    else {
        fprintf(g, "INVALID");
    }
    
    freeMatrix(a, m);
    freeMatrix(b, p);

    fclose(f);
    fclose(g);
}