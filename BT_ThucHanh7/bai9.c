#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int check(char c[], int l, int r){
    int i = l, j = r - 1;
    while (i < j){
        if (c[i] != c[j]) return 0;
        i++;
        j--;
    }
    return 1;
}

int palindrome(char c[], int len, int *l, int *r){
    int max = 0;
    for (int i = 0; i < len; i++){
        for (int j = len - 1; j > i; j--){
                if (check(c, i, j)){
                    if ((j - i) >= max){
                        max = j - i;
                        *l = i; *r = j;
                    }
                }
        }
    }
    if (max > 0) return max;
    return 0;
}

int main(){
    char c[100];
    fgets(c, 100, stdin);
    int len = strlen(c);
    int l, r;
    if (palindrome(c, len, &l, &r)){
        for (int i = l; i < r; i++){
            printf("%c", c[i]);
        }
    }
}