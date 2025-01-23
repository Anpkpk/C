#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char s1[100], s2[100];
    gets(s1);
    gets(s2);
    int cnt[256] = {0};
    for (int i = 0; i < 256; i++){
        cnt[s1[i]] = 1;
    }
    for (int i = 0; i < strlen(s2); i++){
        if (cnt[s2[i]] == 1) {
            cnt[s2[i]] = 2;
        }
    }
    for (int i = 0; i < 256; i++){
        if (cnt[i] == 2){
            printf("%c", (char)i);
        }
    }
}