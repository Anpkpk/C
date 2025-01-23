#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    int *a = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++){
        scanf("%d", a + i);
    }
    a = (int*)realloc(a, 2*n*sizeof(int));
    int j = n - 1;
    for (int i = 2*n - 1; i > 0; i = i - 2){
        *(a + i) = *(a + j);
        *(a + i - 1) = *(a + j);
        j--;
    }
    for (int i = 0; i < 2*n; i++){
        printf("%d ", *(a + i));
    }
    free(a);
}