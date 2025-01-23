#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void del(char c[], int k, char s[][10], int *n){
    *n = 0;
    char *token = strtok(c, " ");
    while (token != NULL){
        strcpy(s[*n], token);
        (*n)++;
        token = strtok(NULL, " ");
    }
    int i = k - 1;
    while (i < (*n)){
        strcpy(s[i], s[i + 1]);
        i++;
    }
}

int main(){
    char c[100], s[20][10];
    fgets(c, 20, stdin);
    int k, n = 0;
    
    scanf("%d", &k);
    getchar();

    del(c, k, s, &n);
    for (int i = 0; i < n; i++){
        printf("%s ", s[i]);
    }
}