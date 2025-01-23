#include <stdio.h>

int max(int a, int b){
    if (a > b) return a;
    return b;
}

int main(){
    int n, m;
    scanf("%d%d", &m, &n);
    int a[m], b[n];

    int lcs[m + 1][n + 1];
    for (int i = 0; i < m; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);

    for (int i = 0; i <= m; i++){
        for (int j = 0; j <= n; j++){
            if (i == 0 || j == 0){
                lcs[i][j] = 0;
            }
            else {
                if (a[i - 1] == b[j - 1]){
                    lcs[i][j] = lcs[i - 1][j - 1] + 1;
                }
                else {
                    lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
                }
            }
        }
    }
    printf("%d", lcs[m][n]);
}