#include <stdio.h>

void scanMatrix(int *a, int m, int n){
    int i, j;
    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            scanf("%d", a + i*n + j);
        }
    }
}
int main(){
    int m, n, q, i, j, k, l;
    scanf("%d%d%d", &m, &n, &q);
    int a[m][n];
    scanMatrix((int*)a, m, n);
    int index;
    int b[q][4], sum[q];
    for (int i = 0; i < q; i++){
        for (int j = 0; j < 4; j++){
            scanf("%d", &b[j][j]);
        }
    }
    for (int index = 0; index < q; index++){
        sum[index] = 0;
        for (int x = b[index][0]; x <= b[index][2]; x++){
            for (int y = b[index][1]; y <= b[index][3]; y++){
                sum[index] += a[x][y];
            }
        }
    }
    for (int i = 0; i < q; i++){
        printf("%d\n", sum[i]);
    }
}