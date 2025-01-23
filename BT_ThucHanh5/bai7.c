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
    int m, n;
    scanf("%d%d", &m, &n);
    int *a = (int*)malloc(n*m*sizeof(int));
    if (a == NULL) exit(1);
    scanMatrix((int*)a, m, n);
    int *b = (int*)malloc(n*m*sizeof(int));
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            *(b + j*m +i) = *(a + i*n + j);
        }
    }
    printMatrix((int*)b, n, m);
    free(a);
    free(b);
}