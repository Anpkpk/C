// Bài 2
#include <stdio.h>
#include <stdlib.h>

int **scanMatrix(int n){
    int **A;
    A = (int**)malloc(n*sizeof(int*));
    for (int i = 0; i < n; i++){
        *(A + i)= (int*)malloc(3*sizeof(int));
        for (int j = 0; j < 3; j++){
            scanf("%d", *(A + i) + j);
        }
    }
    return A;
}

float avg(int *a){
    float Avg = 0;
    Avg = 0.2*a[0] + 0.2*a[1] + 0.6*a[2];
    return Avg;
}
void printArray(float *b, int n){
    for (int i = 0; i < n; i++){
        printf("%.2f\n", *(b + i));
    }
}
int main(){
    int n;
    scanf("%d", &n);
    int **a = scanMatrix(n);
    float *b = (float*)calloc(n, sizeof(float));
    for (int i = 0; i < n; i++){
            *(b + i) = avg(*(a + i));
    }
    printArray(b, n);
    for (int i = 0; i < n; i++){
        free(a[i]);
    }
    free(a);
    free(b);
}