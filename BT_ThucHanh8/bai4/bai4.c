#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;

    FILE *f = fopen("data4.txt", "r");
    FILE *g = fopen("outp4.txt", "w");

    fscanf(f, "%d", &n);

    int a[n];
    for (int i = 0; i < n; i++){
        fscanf(f, "%d", &a[i]);
    }

    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (a[i] > a[j]){
                int tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
    
    for (int i = 0; i < n; i++){
        fprintf(g, "%d ", a[i]);
    }

    fclose(f);
    fclose(g);
}