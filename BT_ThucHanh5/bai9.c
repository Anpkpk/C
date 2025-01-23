#include <stdio.h>
#include <stdlib.h>

int main(){
    int m;
    int **a;
    scanf("%d", &m);
    int n[m];
    a = (int**)malloc(m*sizeof(int*));
    for (int i = 0; i < m; i++){
        scanf("%d", &n[i]);
        a[i] = (int*)malloc(n[i]*sizeof(int));
    }
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n[i]; j++){
            scanf("%d", &a[i][j]);
        }
    }
    int row;
    scanf("%d", &row);
    for (int i = row - 1; i < m - 1; i++){
        a[i] = a[i + 1];
        n[i] = n[i + 1];
    }

    printf("After:\n");
    for (int i = 0; i  < m - 1; i++){
        for (int j = 0; j < n[i]; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < m; i++){
        free(a[i]);
    }
    free(a);
}