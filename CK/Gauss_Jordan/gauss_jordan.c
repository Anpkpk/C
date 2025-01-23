#include <stdio.h>
#include <stdlib.h>

float **createMatrix(int m, int n){
    float **a = (float**)malloc(m*sizeof(float*));
    for (int i = 0; i <m; i++){
        a[i] = (float*)malloc(n*sizeof(float));
    }
    return a;
}

void scanMatrix(FILE *f, float **a, int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            fscanf(f, "%f", &a[i][j]);
        }
    }
}

void printMatrix(FILE *g, float **a, int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            fprintf(g, "%.2f ", a[i][j]);
        }
        fprintf(g, "\n");
    }
}

void freeMatrix(float **a, int m){
    for (int i = 0; i < m; i++){
        free(a[i]);
    }
    free(a);
}
void gauss_jordan(float **a, int m, int n){
    // Gauss
    for (int j = 0; j < m; j++){
        for (int i = j + 1; i < m; i++){
            if (a[j][j] != 0){
                float fact = a[i][j]/a[j][j];
                for (int k = j; k < n; k++){
                    a[i][k] -= fact*a[j][k];
                }
            }
        }
    }
    // Duong cheo -> 1
    for (int i = 0; i < m; i++){
        if (a[i][i] != 0){
            float fact = a[i][i];
            for (int j = i; j < n; j++){
                a[i][j] /= fact;
            }
        }
    }

    // Jordan
    for (int j = m - 1; j >= 0; j--){
        for (int i = j - 1; i >= 0; i--){
            if (a[j][j] != 0){
                float fact = a[i][j] / a[j][j];
                for (int k = j; k < n; k++){
                    a[i][k] -= fact*a[j][k];
                }
            }
        }
    }
}

int main(){
    FILE *f = fopen("matrix_input.txt", "r");
    FILE *g = fopen("Matrix_output.txt", "w");

    int m, n;
    fscanf(f, "%d%d", &m, &n);

    float **a = createMatrix(m, n);
    scanMatrix(f, a, m, n);
    gauss_jordan(a, m, n);
    printMatrix(g, a, m, n);

    freeMatrix(a, m);
    fclose(f);
    fclose(g);
}