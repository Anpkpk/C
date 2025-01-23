#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char c[100];
    gets(c);
    int cnt[256] = {0};
    for (int i = 0; i < strlen(c); i++){
        cnt[c[i]]++;
    }
    int res = 0; 
    char kt;
    for (int i = 0; i < 256; i++){
        if (cnt[i] >= res){
            res = cnt[i];
            kt = (char)i;
        }
    }
    printf("%c", kt);
}