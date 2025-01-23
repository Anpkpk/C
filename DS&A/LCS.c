#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
    if (a > b) return a;
    return b;
}

int LCS(int n, int m){
    int a[n], b[m];
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; i++){
        scanf("%d", &b[i]);
    }
    int L[n + 1][m + 1];
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= m; j++){
            if (i == 0 || j == 0){
                L[i][j] = 0;
            }
            else {
                if (a[i - 1] == b[j - 1]){
                    L[i][j] = L[i - 1][j - 1] + 1;
                }
                else{
                    L[i][j] = max(L[i - 1][j], L[i][j - 1]);
                }
            }
        }
    }
    return L[n][m];
}
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%d", LCS(n, m));
}