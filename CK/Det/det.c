#include <stdio.h>
#include <stdlib.h>

float **createMatrix(int m, int n){
    float **a = (float**)malloc(m*sizeof(float*));
    for (int i = 0; i < m; i++){
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

void freeMatrix(float **a, int m){
    for (int i = 0; i < m; i++){
        free(a[i]);
    }
    free(a);
}

float det(float **a, int m, int n){
    float tmp = 1;
    float Det = 1;
     for (int j = 0; j < m; j++){
        for (int i = j + 1; i < m; i++){
            if (a[j][j] != 0){
                float fact = a[i][j]/a[j][j];
                tmp *= fact;
                for (int k = j; k < n; k++){
                    a[i][k] -= fact*a[j][k];
                }
            }
        }
    }

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%.2f ", a[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < m; i++){
        Det *= a[i][i];
    }
    return Det;
}
int main(){
    FILE *f = fopen("matrix_input.txt", "r");
    FILE *g = fopen("matrix_output.txt", "w");

    int m, n;
    fscanf(f, "%d%d", &m, &n);

    float **a = createMatrix(m, n);
    scanMatrix(f, a, m, n);
    
    fprintf(g, "%.2f", det(a, m, n));

    freeMatrix(a, m);
    fclose(f);
    fclose(g);
}