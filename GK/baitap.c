#include <stdio.h>

int main(){
    for (int i = 1; i < 999; i++){
        if (i % 3 == 2 && i % 5 == 3) {
            printf("%d\n", i);
            return 1;
        }
    }
}