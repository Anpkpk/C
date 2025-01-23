#include <stdio.h>

int max(int a, int b){
    if (a > b) return a;
    return b;
}

int main(){
    int n, S; 
    scanf("%d%d", &n, &S);
    int w[n + 1], v[n + 1];
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &v[i]);
    int dp[n + 1][S + 1];

    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= S; j++){
            dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= S; j++){
            // Khong chon vat thu i vao tui
            dp[i][j] = dp[i - 1][j];
            
            // Co the dua do vat thu i vao trong tui
            if (j >= w[i]){
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }
    printf("%d", dp[n][S]);
}