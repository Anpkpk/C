#include <stdio.h>
#include <math.h>

int main(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    double x1, x2;
    if (a == 0 && b == 0){
        if (c != 0){
            printf("EQUATION HAS NO SOLUTIONS");
        } else {
            printf("EQUATION HAS INFINITELY MANY SOLUTIONS");
        }  
    } else if (a == 0){
        x1 = -(double)c/b;
        printf("%.5f", x1);
    } else {
        double delta = b*b - 4.0*a*c;
        if (delta < 0){
            printf("EQUATION HAS NO SOLUTIONS");
        } else if (delta == 0){
            x1 = -(double)b/2*a;
            printf("%.5f", x1);
        } else {
            x1 = (-b - sqrt(delta))/(2*a);
            x2 = (-b + sqrt(delta))/(2*a);
            printf("%.5f\n%.5f", x1, x2);
        }
    }
}