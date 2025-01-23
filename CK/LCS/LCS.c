// Day con chung dai nhat

#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
    if (a > b) return a;
    return b;
}

int LCS(int a[], int n, int b[], int m){
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
    FILE *f = fopen("data_input.txt", "r");
    FILE *g = fopen("data_output.txt", "w");

    int n, m;
    fscanf(f, "%d%d", &n, &m);
    int a[n], b[m];

    for (int i = 0; i < n; i++) fscanf(f, "%d", &a[i]);
    for (int i = 0; i < m; i++) fscanf(f, "%d", &b[i]);

    fprintf(g, "%d", LCS(a, n, b, m));

    fclose(f);
    fclose(g);
}