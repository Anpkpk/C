#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void splitString(char c[], int len, char s[][1000], int *n){
    int i = 0, j = 0;
    *n = 0;
    char tmp[1000];
    while (i < len){
        do {
            tmp[j] = c[i];
            ++j;
            ++i;
        } while (c[i - 1] != '!' && c[i - 1] != '?' && c[i - 1] != '.');
        tmp[j] = '\0';
        strcpy(s[*n], tmp);
        (*n)++;
        i++;
        j = 0;
    }
}

int main(){
    char c[1000], tmp[100];
    fgets(c, 1000, stdin);
    int len = strlen(c);
    int n = 0;
    char s[20][1000];

    splitString(c, len, s, &n);
    for (int i = 0; i < n; i++){
        printf("%s\n", s[i]);
    }
}