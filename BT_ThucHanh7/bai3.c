#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char *Fibonacci(int n, char *f0, char *f1, char *f2){
    strcpy(f0, "A");
    strcpy(f1, "B");
    if (n == 0) return f0;
    if (n == 1) return f1;
    while (n >= 2) {
        strcpy(f2, f1);
        strcat(f2, f0);

        strcpy(f0, f1);
        strcpy(f1, f2);
        n--;
    }
    
    return f2;   
}
int main(){
    int n;
    char f0[100] = "", f1[100] = "", f2[100] = "";
    scanf("%d", &n);
    printf("%s", Fibonacci(n, f0, f1, f2));
}