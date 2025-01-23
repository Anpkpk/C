#include <stdio.h>
#include <string.h>

int main(){
    char c[100];
    gets(c);
    char *token = strtok(c, " ");
    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }
}