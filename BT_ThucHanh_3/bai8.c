#include <stdio.h>

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int a[n];
    int sum[m];

    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    int l, r;
    for (int i = 0; i < m; i++){
        scanf("%d%d", &l, &r);
        int sumOf = 0;
        for (int j = l; j <= r; j++){
            sumOf += a[j - 1];
        }
        sum[i] = sumOf;
    }
    for (int i = 0; i < m; i++){
        printf("%d\n", sum[i]);
    }
}