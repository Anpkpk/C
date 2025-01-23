#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void sort(char a[][100], int n){
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (strcmp(a[j], a[i]) < 0){
                char tmp[100];
                strcpy(tmp, a[j]);
                strcpy(a[j], a[i]);
                strcpy(a[i], tmp);
            }
        }
    }
}

int main(){
    char c[100], a[10][100];
    int n = 0, t;
    scanf("%d", &t);
    getchar();
    while (t--){
        fgets(c, 100, stdin);
        strcpy(a[n], c);
        ++n;
    }
    sort(a, n);
    for (int i = 0; i < n; i++){
        printf("%s", a[i]);
    }
}