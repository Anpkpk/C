#include <stdio.h>
#include <stdlib.h>

void scanMatrix(int *a, int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", a + i*n + j);
        }
    }
}
void printMatrix(int *a, int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%d ", *(a + i*n + j));
        }
        printf("\n");
    }
}

int main(){
    int m, n, p, q;
    scanf("%d%d", &m, &n);
    int *a = (int*)malloc(m*n*sizeof(int));
    scanMatrix(a, m, n);
    scanf("%d%d", &p, &q);
    int *b = (int*)malloc(p*q*sizeof(int));
    scanMatrix(b, p, q);
    if (n == p){
        int *c = calloc(m*q, sizeof(int));
        for (int i = 0; i < m; i++){
            for (int j = 0; j < q; j++){
                for (int k = 0; k < n; k++){
                    *(c + i*q + j) += *(a + i*n + k) * *(b + k*q + j);
                }
            }
        }
        printMatrix(c, m, q);
        free(c);
    }
    else {
        printf("INVALID");
    }
    free(a);
    free(b);
}