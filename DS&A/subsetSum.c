#include <stdio.h>

int main(){
    int n, s;
    scanf("%d%d", &n, &s);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int dp[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        dp[i] = 0;
    }
    dp[0] = 1;
    for (int i = 0; i < n; i++){
        for (int j = s; j >= a[i]; j--){
            if (dp[j - a[i]] == 1){
                dp[j] = 1;
            }
        }
    }
    if (dp[s] == 1) printf("1");
    else printf("0");
}
