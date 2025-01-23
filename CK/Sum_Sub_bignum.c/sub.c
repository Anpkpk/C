#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void revers(int a[], int n){
    int l = 0, r = n - 1;
    while (l < r){
        int tmp = a[l];
        a[l] = a[r];
        a[r] = tmp;
        l++; 
        r--;
    }
}

void subBignum(char x1[], char x2[], char sub[]){
    int n1 = strlen(x1), n2 = strlen(x2), n = 0;
    int num1[n1], num2[n1], s[n1 + 1];

    for (int i = 0; i < n1; i++) num1[i] = x1[i] - '0';
    for (int i = 0; i < n2; i++) num2[i] = x2[i] - '0';

    revers(num1, n1);
    revers(num2, n2);

    for (int i = n2; i < n1; i++) num2[i] = 0;

    int nho = 0;
    int tmp;
    for (int i = 0; i < n1; i++){
        tmp = num1[i] - num2[i] - nho;
        if (tmp < 0){
            s[n++] = 10 + tmp;
            nho = 1;
        }
        else {
            s[n++] = tmp;
            nho = 0;
        }
    }

    int ok = 0;
    revers(s, n);
    int len = 0;
    for (int i = 0; i < n; i++){
        if (ok == 0 && s[i]){
            ok = 1;
        }
        if (ok) sub[i] = s[len++] + '0';
    }
    
    if (ok == 0) sub = "0\0";
    else {
        sub[len++] = '\0';
    }
}

int main(){
    FILE *f = fopen("data_input.txt", "r");
    FILE *g = fopen("data_output.txt", "w");

    char x1[100], x2[100], sub[100];

    fscanf(f, "%s", x1);
    fscanf(f, "%s", x2);

    subBignum(x1, x2, sub);
    fprintf(g, "%s", sub);

    fclose(f);
    fclose(g);
}