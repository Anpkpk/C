#include <stdio.h>
#include <string.h>
#include <ctype.h>

void sortString(char c[][1000], int n){
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (strcmp(c[j], c[i]) < 0){
                char tmp[100];
                strcpy(tmp, c[i]);
                strcpy(c[i], c[j]);
                strcpy(c[j], tmp);
            }
        }
    }
}
int main(){
    char c[1000];
    char s[20][1000];
    fgets(c, 100, stdin);
    int n = 0;
    char *token = strtok(c, " ");
    while (token != NULL){
        strcpy(s[n], token);
        token = strtok(NULL, " ");
        n++;
    }
    sortString(s, n);
    int cnt = 1, max = 0, index;
    for (int i = 0; i < n; i++){
        cnt = 1;
        for (int j = i + 1; j < n; j++){
            if (strcmp(s[i], s[j]) == 0){
                ++cnt;
            }
            if (cnt > max){
                max = cnt;
                index = j;
            }
        }
    }
    printf("%s %d", s[index], max);
}