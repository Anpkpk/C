#include <stdio.h>

void scanMatrix(int *a, int m, int n){
    int i, j;
    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            scanf("%d", a + i*n + j);
        }
    }
}
int maxPair(int a, int b){
    if (a >= b) return a;
    return b;
}
int maxTrip(int a, int b, int c){
    if (a >= b && a >= c){
        return a;
    }
    else if (b >= a && b >= c) {
        return b;
    }
    else return c;
}
int main(){
    int m, n, i, j;
    scanf("%d%d", &m, &n);
    int a[m][n];
    scanMatrix((int*)a, m, n);
    int dp[m][n];
    for (i = 0; i < m; i++){
        dp[i][0] = a[i][0];
    }
    for (j = 1; j < n; j++){
        for (i = 0; i < m; i++){
            if (i >= 1 && i <= m - 2){
                dp[i][j] = a[i][j] + maxTrip(dp[i][j-1], dp[i - 1][j-1], dp[i + 1][j-1]);
            }
            else if (i < 1){
                dp[i][j] = a[i][j] + maxPair(dp[i][j-1], dp[i + 1][j-1]);
            }
            else if (i > m - 2){
                dp[i][j] = a[i][j] + maxPair(dp[i][j-1], dp[i - 1][j-1]);               
            }
        }
    }
    int max = dp[0][n - 1];
    for (i = 1; i < m; i++){
        if (dp[i][n - 1] >= max){
            max = dp[i][n - 1];
        }
    }
    printf("\n%d", max);
}