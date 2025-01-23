#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int palindrome(char c[], int len){
    int i = 0, j = len - 1;
    while (i < j){
        if (c[i] != c[j]){
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

int main(){
    char c[100];
    fgets(c, 100, stdin);
    int ans = palindrome(c, strlen(c));
    if (ans) {
        printf("YES");
    }
    else {
        printf("NO");
    }
}