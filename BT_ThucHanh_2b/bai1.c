#include <stdio.h>

int main(){
    char c = 'z';
    for (int i = 65 + 32; i <= c; i++){
        printf("%c ", i);
    }
}