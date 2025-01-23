#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int lis(char c[]){
    int lis[strlen(c)];
    for (int i = 0; i < strlen(c); i++){
        lis[i] = 1;
        for (int j = 0; j < i; j++){
            if (c[i] > c[j] && lis[i] < lis[j] + 1){
                lis[i] = lis[j] + 1;
            }
        }
    }
    int max = 0;
    for (int i = 0; i < strlen(c); i++){
        if (lis[i] > max) max = lis[i];
    }
    return 26 - max;
}
int main(){
    char c[1000];
    scanf("%s", c);
    printf("%d", lis(c));
}