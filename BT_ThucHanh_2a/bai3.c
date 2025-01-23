#include <stdio.h>
#include <math.h>

int main(){
    int x;
    scanf("%d", &x);
    float delta = (-1 + sqrt(1 + 8*x))/2;
    if (round(delta) == delta){
        printf("YES");
    } else {
        printf("NO");
    }
}