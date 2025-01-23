#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    int ox = 0, oy = 0;
    for (int i = 0; i < n; i++){
        switch (a[i]){
        case 0:
            ox++;
            break;
        case 2:
            ox--;
            break;
        case 1:
            oy++;
            break;
        case 3:
            oy--;
            break;
        }
    }
    printf("%d %d", ox, oy);
}