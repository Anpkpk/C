#include <stdio.h>

int SNT(int n){
    int count = 1;
    if (n <= 0) return 0;
    if (n < 4) return 1;
    for (int i = 2; i <= n/2; i++){
        if (n % i == 0){
            return 0;
        } 
    }
    return 1;
}
int main(){
    int n;
    scanf("%d", &n);
    if (SNT(n)){
        printf("YES");
    } else printf("NO");
}