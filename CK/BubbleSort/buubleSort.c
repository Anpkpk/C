#include <stdio.h>
#include <stdlib.h>

void buubleSort(int a[], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (a[j] > a[j + 1]){
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

int main(){
    FILE *f = fopen("data_input.txt", "r");
    FILE *g = fopen("data_output.txt", "w");

    int n;
    fscanf(f, "%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) fscanf(f, "%d", &a[i]);

    buubleSort(a, n);

    for (int i = 0; i < n; i++) fprintf(g, "%d ", a[i]);
    fclose(f);
    fclose(g);
}