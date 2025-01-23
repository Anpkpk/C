#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void string(char c[], char s[][100], int *n){
    *n = 0;
    char *token = strtok(c, " ");
    while (token != NULL){
        strcpy(s[*n], token);
        (*n)++;
        token = strtok(NULL, " ");
    }
}

int main(){
    char c[100];
    int n;
    fgets(c, 100, stdin);
    char s[100][100];
    string(c, s, &n);
    for (int i = 0; i < n; i++){
        puts(s[i]);
    }
}