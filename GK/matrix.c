#include <stdio.h>

int main(){
    int m, n;
    scanf("%d%d", &m, &n);
    int a[m][n];

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &a[i][j]);
        }
    }
    int min = a[0][0], row = 0, col = 0;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (a[i][j] <= min){
                min = a[i][j];
                row = i;
                col = j;
            }
        }
    }

    printf("%d\n%d %d", min, row, col);
    
}