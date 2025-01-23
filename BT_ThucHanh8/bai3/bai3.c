#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    FILE *f = fopen("data3.txt", "r");

    int max = 1e-9, min = 1e9;

    fscanf(f, "%d", &n);
    int a[n];
    for (int i = 0; i < n; i++){
        fscanf(f, "%d", &a[i]);
        if (a[i] >= max) max = a[i];
        else if (a[i] <= min) min = a[i];
    }
    printf("%d %d", min, max);

    fclose(f);
}