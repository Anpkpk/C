#include <stdio.h>
#include <math.h>

int main() // sinx = x - x^3/3! + x^5/5! + ... + (-1)^(m - 1)x^(2m - 1)/(2m - 1)!
{
    double x;
    scanf("%lf", &x);
    double ms = 1, ts = x, gia_tri = 0, dau = (-1);
    double m = 1;
    double du = x;
    while(du>pow(10,-9))
    {
        dau = dau*(-1);
        gia_tri = gia_tri + dau*ts/ms;
        ts = ts*x*x;
        ms = ms*(m+1)*(m+2);
        m+=2;
        du=ts/ms;

    }
    printf("%lf\n", gia_tri);
    printf("\n");
    printf("%lf", sin(x));
}