#include <stdio.h>

void scanArray(int *a, int n){
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
}

void printArray(int *a, int n){
    for (int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
}
void merge(int *a, int *b, int *c, int* n, int* m){
    int i = 0;
    int j = 0;
    int index = 0;
    while (i < *n && j < *m){
        if (a[i] <= b[j]){
            c[index] = a[i];
            i++;
            index++;
        }
        else {
            c[index] = b[j];
            j++;
            index++;
        }
    }
    while (i < *n){
        c[index] = a[i];
        i++;
        index++;
    }
    while (j < *m){
        c[index] = b[j];
        j++;
        index++;
    }
}
int main(){
    int n;
    scanf("%d", &n);
    int a[n];
    scanArray(a, n);
    int m;
    scanf("%d", &m);
    int b[m];
    scanArray(b, m);
    int c[n + m];
    merge(a, b, c, &n, &m);
    printArray(c, m + n);
}