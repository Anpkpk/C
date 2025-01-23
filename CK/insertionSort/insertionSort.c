#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *a, int n){
    int i, j, key;
    for (i = 1; i < n; i++){
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key){
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

int main(){
    FILE *f = fopen("data_input.txt", "r");
    FILE *g = fopen("data_output.txt", "w");

    int n;
    fscanf(f, "%d", &n);
    int *a = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++){
        fscanf(f, "%d", &a[i]);
    }
    insertionSort(a, n);
    for (int i = 0; i < n; i++){
        fprintf(g, "%d ", a[i]);
    }

    free(a);
    fclose(f);
    fclose(g);
}