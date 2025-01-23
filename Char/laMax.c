#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char s[] = "IVXLCDM";
int val[] = {1, 5, 10, 50, 100, 500, 1000};

int pos(char c){
    for (int i = 0; i < 7; i++){
        if (c == s[i]) return i;
    }
}

int slove(char c[]){
    int n = strlen(c);
    int res = val[pos(c[n - 1])];
    for (int i  = n - 1; i >= 0; i--){
        int pos1 = pos(c[i]);
        int pos2 = pos(c[i - 1]);
        if (val[pos1] <= val[pos2]){
            res += val[pos2];
        }
        else res -= val[pos2];
    }
    return res;
}

int main(){
    char c[1000];
    scanf("%s", c);
    printf("%d", slove(c));
}