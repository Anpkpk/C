#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void revers(char c[]){
    int l = 0, r = strlen(c) - 1;
    while (l < r) {
        char tmp = c[l];
        c[l] = c[r];
        c[r] = tmp;
        l++;
        r--;
    }
}

void multBignum(char x1[], char x2[], char mul[]){
    int n1 = strlen(x1), n2 = strlen(x2);

    revers(x1);
    revers(x2);

    for (int i = 0; i < n1 + n2; i++){
        mul[i] = '0';
    }
     
    for (int i2 = 0; i2 < n2; i2++){
        int nho = 0;
        int i1;
        for (i1 = 0; i1 < n1; i1++){
            int tmp = (x1[i1] - '0') * (x2[i2] - '0') + nho + (mul[i1 + i2] - '0');
            nho = tmp / 10;
            mul[i1 + i2] = tmp % 10 + '0';
        }
        if (nho) mul[i1 + i2] = nho + '0';
    }
    if (mul[n1 + n2 - 1] != '0') mul[n1 + n2] = '\0';
    else
        mul[n1 + n2 - 1] = '\0';
    revers(mul);   
}
int main(){
    char x1[100], x2[100], mul[201];

    strcpy(x1, "1234\0");
    strcpy(x2, "1234\0");

    multBignum(x1, x2, mul);
    puts(mul);
}