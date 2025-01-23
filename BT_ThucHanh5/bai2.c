#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, m;
    scanf("%d%d", &m, &n);
    int *a = malloc(m*n*sizeof(int));
    if (a == NULL) exit(1);
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", a + i*n +j);
        }
    }
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%d ", *(a + i*n + j));
        }
        printf("\n");
    }
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%d ", *(a + i*n + j));
        }
        printf("\n");
    }
    free(a);
}