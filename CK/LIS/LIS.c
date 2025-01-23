// Day con tang dai nhat

#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
    if (a > b) return a;
    return b;
}

int maxElement(int a[], int n){
    int Max = 1;
    for (int i = 0; i < n; i++){
        if (Max < a[i]) Max = a[i];
    }
    return Max;
} 

int LIS(int a[], int n){
    int l[n];
    for (int i = 0; i < n; i++) l[i] = 1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < i; j++){
            if (a[i] > a[j]){
                l[i] = max(l[i], l[j] + 1);
            }
        }
    }
    return maxElement(l, n);
}

int main(){
    FILE *f = fopen("data_input.txt", "r");
    FILE *g = fopen("data_output.txt", "w");

    int n;
    fscanf(f, "%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) fscanf(f, "%d", &a[i]);
    
    fprintf(g, "%d", LIS(a, n));
    
    fclose(f);
    fclose(g);
}