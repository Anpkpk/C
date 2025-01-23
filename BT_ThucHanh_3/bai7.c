#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    
    int length = 0, max = 1;
    int i = 0, l = 0, r = 0;
    while (i < n - 1){
        for (int j = i; j < n; j++){
            if (a[j] == a[i]){
                length++;
            } 
            else {
                if (length >= max){
                    max = length;
                    l = i;
                    r = j - 1;
                    i = r + 1;
                    break;
                } else {
                    i++;
                    break;
                }
            }
        }
        length = 0;
        i++;
    }
    printf("%d %d %d", max, l + 1, r + 1);
}