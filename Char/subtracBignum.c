#include <stdio.h>
#include <string.h>

void revers(int c[], int n){
    int l = 0, r = n - 1;
    while (l < r){
        int tmp = c[l];
        c[l] = c[r];
        c[r] = tmp;
        l++;
        r--;
    }
}

int main(){
    char x1[100], x2[100], x3[100];

    strcpy(x1, "987654321\0");
    strcpy(x2, "876543210\0");

    int n1 = strlen(x1), n2 = strlen(x2), n = 0;
    int s1[n1], s2[n1], sub[n1];

    for (int i = 0; i < n1; i++) s1[i] = x1[i] - '0';
    for (int i = 0; i < n2; i++) s2[i] = x2[i] - '0';   
    revers(s1, n1);
    revers(s2, n2);

    for (int i = n2; i < n1; i++) s2[i] = 0;

    int nho = 0, tmp;
    for (int i = 0; i < n1; i++){
        tmp = s1[i] - s2[i] - nho;
        if (tmp < 0){
            nho = 1;
            sub[n++] = tmp + 10;
        }
        else {
            sub[n++] = tmp;
            nho = 0;
        }
    }
    int check = 0, index = 0;
    for (int i = n - 1; i >= 0; i--){
        if (check == 0 && sub[i]){
            check = 1;
        }
        if (check) {
            x3[index++] = sub[i] + '0';
        }
    }
    x3[index] = '\0';
    if (check == 0) {
        strcpy(x3, "0\0");
    }
    puts(x3);
}