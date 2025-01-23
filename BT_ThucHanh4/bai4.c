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
    if (m == p && n == q){
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                a[i][j] += b[i][j];
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }

    }
    else printf("INVALID");
}