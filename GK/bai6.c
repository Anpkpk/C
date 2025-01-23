#include <stdio.h>

int USCLN(int a, int b) {
    if (b == 0) 
        return a;
    return USCLN(b, a % b);
}
int BCNN(int a, int b){
    return (a*b)/USCLN(a, b);
}

int main(){
    int a = 1, b = 1;
    for (a = 1; a < 200; a++){
        for (b = 1; b < 200; b++){
            if (a - b == 90 && USCLN(a, b) == 15) {
                printf("%d %d", a, b);
                return 1;
            }
        }
    }
}