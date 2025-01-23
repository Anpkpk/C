#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int a[n + 1];
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    int k, index;
    scanf("%d%d", &index, &k);
    //Chen phan tu:
    // for (int i = n; i >= index - 1; i--){
    //     a[i] = a[i -1];
    // }
    // a[index - 1] = k;
    // for (int i = 0; i < n + 1; i++){
    //     printf("%d ", a[i]);
    // }
    //Xoa phan tu thu index
    for (int i = index - 1; i < n; i++){
        a[i] = a[i + 1];
    }
    n -= 1;
    for (int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
}