#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    int *a = (int*)malloc(n*sizeof(int));
    if (a == NULL) exit(1);
    for (int i = 0; i < n; i++){
        scanf("%d", (a + i));
    }
    for (int i = 0; i < n; i++){
        printf("%d ", *(a + i));
    }
    printf("\n");
    for (int i = 0; i < n; i++){
        printf("%d ", a + i);
    }
    free(a);
}