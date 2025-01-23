// Bài 15
#include <stdio.h>
#include <stdlib.h>

void scanMatrix(float **a, int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            scanf("%f", &a[i][j]);
        }
    }
}

void printMatrix(float **a, int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%.2f ", a[i][j]);
        }
        printf("\n");
    }
}

float **Gauss(float **a, int m, int n){
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (a[j][i] != 0){
                float actor = a[i][i] / a[j][i];
                for (int k = i; k < n; k++){
                    a[j][k] = a[j][k] * actor - a[i][k];
                }
            }
        }
    }
    return a;
}

int rank(float **a, int m, int n){
    int Rank = 0;
    a = Gauss(a, m, n);
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (a[i][j] != 0) {
                Rank++;
                break;
            }
        } 
    }
    return Rank;
}

float **createMatrix(int m, int n){
    float **a = (float**)malloc(m * sizeof(float*));
    for (int i = 0; i < m; i++){
        a[i] = (float*)calloc(n, sizeof(float));
    }
    return a;
}

void freeMatrix(float **a, int m){
    for (int i = 0; i < m; i++){
        free(a[i]);
    }
    free(a);
}

int main(){
    int m, n;
    scanf("%d%d", &m, &n);
    float **a = createMatrix(m, n);
    scanMatrix(a, m, n);
    printf("%d", rank(a, m, n));
    freeMatrix(a, m);
}