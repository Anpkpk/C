#include <stdio.h>
#include <stdlib.h>

void print(FILE *g, int *a, int n){
    for (int i = 1; i <= n; i++){
        fprintf(g, "%d", a[i]);
    }
    fprintf(g, "\n");
}

void try(FILE *g, int *bool, int *a, int n, int k){
    for (int i = 1; i <= n; i++){
        if (!bool[i]){
            a[k] = i;
            bool[i] = 1;
            if (k == n){
                print(g, a, n);
            }
            else {
                try(g, bool, a, n, k + 1);
            }
            bool[i] = 0;
        }
    }
}

int main(){
    FILE *f = fopen("data_input.txt", "r");
    FILE *g = fopen("data_output.txt", "w");

    int n;
    fscanf(f, "%d", &n);

    int *a = (int*)calloc(n, sizeof(int));
    int *bool = (int*)calloc(n, sizeof(int));

    try(g, bool, a, n, 1);

    free(a);
    free(bool);
    fclose(f);
    fclose(g);
}