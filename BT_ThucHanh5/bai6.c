#include <stdio.h>
#include <stdlib.h>

void scanMatrix(int *a, int m, int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", a + i*n + j);
        }
    }
}
int main(){
    int m, n;
    scanf("%d%d", &m, &n);
    int *a = (int*)malloc(m*n*sizeof(int));
    scanMatrix((int*)a, m, n);
    int sum = 0;
    for (int i = 0; i < m; i++){
        sum += *(a + i*n + i);
    }
    printf("%d", sum);
    free(a);
}