#include <stdio.h>
#include <math.h>


int main(){
    double x;
    scanf("%lf", &x);
    double du = x, kq = 0, ts = 1, ms = 1, d = 1;
    int m = 1;
    // sinx = x - x^3/3! + x^5/5! + ... + (-1)^(m - 1)x^(2m - 1)/(2m - 1)!
    // e^x = 1 + x + x^2/2! +...+ x^n/n!
    // cosx = 1 - x^2/2! +...+(-1)^2nx^2n/(2n)!

    while (du > 10e-9) {
        kq += ts/ms;
        ts *= x;
        ++m;
        ms *= m;
        du = ts/ms;
    }
    // while ((du) > 10e-9){
    //     kq += d*ts/ms;
    //     ts *= x*x;
    //     ms *= (m + 1)*(m + 2);
    //     du = ts/ms;
    //     m += 2;
    //     d *= -1;
    // }
    printf("%lf\n", kq);
    printf("%lf", exp(x));
}