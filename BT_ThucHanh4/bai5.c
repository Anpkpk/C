#include <stdio.h>

int main(){
    int m, n, p, q;
    scanf("%d%d", &m, &n);
    int a[m][n];
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &a[i][j]);
        }
    }
    scanf("%d%d", &p, &q);
    int b[p][q];
    for (int i = 0; i < p; i++){
        for (int j = 0; j < q; j++){
            scanf("%d", &b[i][j]);
        }
    }
    int c[m][q];
    for (int i = 0; i < m; i++){
        for (int j = 0; j < q; j++){
            c[i][j] = 0;
            for (int k = 0; k < n; k++){
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    for (int i = 0; i < m; i++){
        for (int j = 0; j < q; j++){
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}