// bài 14
#include <stdio.h>
#include <stdlib.h>

float **createMatrix(int n){
    float **a = (float**)malloc(n*sizeof(float*));
    for (int i = 0; i < n; i++){
        a[i] = (float*)calloc(n, sizeof(float));
    }
    return a;
}

void scanMatrix(float **a, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            scanf("%f", &a[i][j]);
        }
    }
}

float DET(float **a, int n){
    float K = 1;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (a[j][i] != 0){
                float actor = a[i][i] / a[j][i];
                K *= actor;
                for (int k = i; k < n; k++){
                    a[j][k] = a[j][k] * actor - a[i][k];
                }
            }
        }
    }
    float det = 1;
    for (int i = 0; i < n; i++){
        det *= a[i][i];
    }
    return det/K;
}


void freeMatrix(float **a, int n){
    for (int i = 0; i < n; i++){
        free(a[i]);
    }
    free(a);
}

int main(){
    int n;
    scanf("%d", &n);
    float **a = createMatrix(n);
    scanMatrix(a, n);
    printf("%.2f", DET(a, n));
    freeMatrix(a, n);
}