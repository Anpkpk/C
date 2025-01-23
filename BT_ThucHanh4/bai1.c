#include <stdio.h>

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int arr[m][n];
    int max = -10e6, min = 10e6;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            scanf("%d", &arr[i][j]);
            if (arr[i][j] <= min){
                min = arr[i][j];
            }
            else if (arr[i][j] >= max){
                max = arr[i][j];
            }
        }
    }
    printf("%d %d", min, max);

}