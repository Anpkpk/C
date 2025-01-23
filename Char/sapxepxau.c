#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void sx(char a[][100], int n){
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (strcmp(a[j], a[i]) < 0) {
                char temp[100];
                strcpy(temp, a[j]);
                strcpy(a[j], a[i]);
                strcpy(a[i], temp);
            }
        }
    }
}

int main(){
    int t;
    scanf("%d", &t);
    getchar();
    char c[100];
    char a[10][100];
    int n = 0;
    while (t--){
        fgets(c, 50, stdin);
        char *token = strtok(c, " ");
        while (token != NULL){
            strcpy(a[n], token);
            ++n;
            token = strtok(NULL, " ");
        }
    }
    sx(a, n);
    for (int i = 0; i < n; i++){
        printf("%s ", a[i]);
    }
}