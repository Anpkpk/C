#include <stdio.h>
#include <math.h>

int factory(int n){
    int kq = 1;
    if (n <= 1){
        return 1;
    } else return n*factory(n - 1);
}

int main(){
    double x;
    scanf("%lf", &x);
    // sai so == |x^n|/n!
    double kq = 0, saiso = 1;
    int i = 1;
    while (saiso > 1e-9)
    {
        kq += saiso;
        saiso = pow(x, i)/factory(i); 
        i++;
    }
    printf("%lf\n", kq);
    printf("%lf", exp(x));
}