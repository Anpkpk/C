#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int *a, int n){
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (*(a + i) > *(a + j)){
                swap((a + i), (a + j));
            }
        }
    }
}
int main(){
    int n;
    scanf("%d", &n);
    int *a = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++){
        scanf("%d", a + i);
    }
    sort((int*)a, n);
    for (int i = 0; i < n; i++){
        printf("%d ", *(a + i));
    }
    free(a);
}