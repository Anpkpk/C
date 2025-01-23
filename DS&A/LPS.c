#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b){
    if (a > b) return a;
    return b;
}

int main(){
    char *str;
    gets(str);
    fflush(stdin);
    char *s = str;
    int n = strlen(s);
    strcat(s, str);
    printf("\n%s", s);
    int **F = (int**)malloc((n+1)*sizeof(int*));
    for (int i = 0; i < n + 1; i++){
        F[i] = calloc(n+1, sizeof(int));
    }
    for (int i = 0; i < n+1; i++){
        F[i][i] = 1;
    }
    int ans = 1;
    for (int len = 2; len < n + 1; len++){
        for (int i = 1; i < n - len + 1; i++){
            int j = i + len - 1;
            if (len == 2 && s[i] == s[j]){
                F[i][j] = 1;
            }
            else {
                F[i][j] = F[i + 1][j - 1] && (s[i] == s[j]);
            }
            if (F[i][j] == 1){
                ans = max(ans, len);
            }
        }
    }
    printf("%d", ans);
    for (int i = 0; i < n+1; i++){
        free(F[i]);
    }
    free(F);
}
