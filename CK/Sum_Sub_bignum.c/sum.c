#include <stdio.h>
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

void sumBignum(char x1[], char x2[], char sum[]){
    int n1 = strlen(x1), n2 = strlen(x2), n = 0;
    int num1[n1], num2[n1], s[n1 + 1];

    for (int i = 0; i < n1; i++) num1[i] = x1[i] - '0';
    for (int i = 0; i < n2; i++) num2[i] = x2[i] - '0';

    revers(num1, n1);
    revers(num2, n2);

    for (int i = n2; i < n1; i++) num2[i] = 0;

    int nho = 0, tmp;
    for (int i = 0; i < n1; i++){
        tmp = num1[i] + num2[i] + nho;
        nho = tmp/10;
        s[n++] = (tmp % 10);
    }

    if (nho) s[n++] = nho;
    else n--;
    revers(s, n);
    for (int i = 0; i < n; i++) sum[i] = s[i] + '0';
    sum[n + 1] = '\0';
}


int main(){
    FILE *f = fopen("data_input.txt", "r");
    FILE *g = fopen("data_output.txt", "w");

    char x1[100], x2[100], sum[100] = "";

    fscanf(f, "%s", x1);
    fscanf(f, "%s", x2);

    sumBignum(x1, x2, sum);
    fprintf(g, "%s", sum);

    fclose(f);
    fclose(g);
}
