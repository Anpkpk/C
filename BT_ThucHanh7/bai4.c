#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void del(char c[], int k, int *len){
    for (int i = k; i < *len - 1; i++){
        c[i] = c[i + 1];
    }
    c[(*len) - 1] = '\0';
    (*len)--;
}

void standard(char *c, int *len){
    while (c[0] == ' '){
        del(c, 0, len);
    }
    for (int i = 1; i < *len - 1; i++){
        while (c[i] == ' ' && c[i + 1] == ' '){
            del(c, i, len);
        }
    }
    for (int i = (*len) - 1; i >= 0; i--){
        if (c[i] == ' '){
            c[i] = '\0';
            (*len)--;
        }
        else break;
    }
}

int main(){
    char c[100];
    fgets(c, 99, stdin);
    int len = strlen(c);
    standard(c, &len);
    
    FILE *g = fopen("outp4.txt", "w");
    fprintf(g, "%s%s", c, "11");
    fclose(g);
}