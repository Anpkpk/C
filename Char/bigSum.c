#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void reveser(int c[], int len){
    int l = 0, r = len - 1;
    while (l < r){
        char tmp = c[l];
        c[l] = c[r];
        c[r] = tmp;
        l++; r--;
    }
}

void add(char a[], char b[]){
    int n1 = strlen(a), n2 = strlen(b), n = 0;
    int x1[n1], x2[n1], sum[n1 + 1];
    for (int i = 0; i < n1; i++){
        x1[i] = a[i] - '0';
    }
    for (int i = 0; i < n2; i++){
        x2[i] = b[i] - '0';
    }
    reveser(x1, n1);
    reveser(x2, n2);
    for (int i = n2; i < n1; i++){
        x2[i] = 0;
    }
    int nho = 0, tmp;
    for (int i = 0; i < n1; i++){
        tmp = x1[i] + x2[i] + nho;
        sum[n++] = tmp % 10;
        nho = tmp / 10;
    }
    if (nho) sum[n++] = nho;
    for (int i = n - 1; i >= 0; i--) printf("%d", sum[i]);
}

int main(){
    char a[1000], b[1000];
    scanf("%s", a);
    scanf("%s", b);
    if (strlen(a) >= strlen(b)) add(a, b);
    else add(b, a);
}