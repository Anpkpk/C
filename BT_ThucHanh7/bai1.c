#include <stdio.h>
#include <string.h>
#include <ctype.h>

void to_lower(char c[], int len){
    for (int i = 0; i < len; i++){
        c[i] = tolower(c[i]);
    }
}

void times(char c[], int *count){
    int cnt[256] = {0};
    for (int i = 0; i < strlen(c); i++){
        cnt[c[i]]++;
    }
    for (int i = 0; i < 256; i++){
        if (cnt[i] != 0){
            (*count)++;
        }
    }
    printf("%d\n", *count);
    for (int i = 0; i < 256; i++){
        if (cnt[i] != 0){
            printf("%c %d\n", (char)i, cnt[i]);
        }
    }
}

int main(){
    char c[100];
    gets(c);
    to_lower(c, strlen(c));
    int count = 0;
    times(c, &count);    
}