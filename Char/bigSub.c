#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void reverse(int c[], int len){
    int l = 0, r = len - 1;
    while (l < r){
        int tmp = c[l];
        c[l] = c[r];
        c[r] = tmp;
        l++; r--;
    }
}

void Sub(char a[], char b[]){
    int n1 = strlen(a), n2 = strlen(b), n = 0;
    int x1[n1], x2[n1], sub[n1 + 1];
    for (int i = 0; i < n1; i++) x1[i] = a[i] - '0';
    for (int i = 0; i < n2; i++) x2[i] = b[i] - '0';
    reverse(x1, n1); 
    reverse(x2, n2);
    for (int i = n2; i < n1; i++) x2[i] = 0;
    int nho = 0;
    int tmp;
    for (int i = 0; i < n1; i++){
        tmp = x1[i] - x2[i] - nho;
        if (tmp < 0){
            sub[n++] = 10 + tmp;
            nho = 1; 
        }
        else {
            sub[n++] = tmp;
            nho = 0;
        }
    }
    int ok = 0;
    for (int i = n - 1; i >= 0; i--){
        if (ok == 0 && sub[i]){
            ok = 1;
        }
        if (ok) printf("%d", sub[i]);
    }
    if (ok == 0) printf("0");
}

int main(){
    char a[1000], b[1000], sub[1000];
    scanf("%s%s", a, b);
    if (strlen(a) > strlen(b) || (strlen(a) == strlen(b) && strcmp(a, b) > 0)) Sub(a, b);
    else Sub(b, a);
}