#include <stdio.h>
#include <math.h>

int main(){
    float a, b, c, d, e, f;
    //    BC CA AB AD BD CD
    float M, N, P, Q;
    scanf("%f%f%f%f%f%f", &c, &b, &d, &a, &e, &f);
    M = a*a*d*d*(b*b + e*e + f*f + c*c - a*a - d*d);
    N = b*b*e*e*(a*a + d*d + c*c + f*f - b*b - e*e);
    P = c*c*f*f*(a*a + b*b + e*e + d*d - c*c - f*f);
    Q = pow(a*b*c, 2) + pow(a*e*f, 2) + pow(b*d*f, 2) + pow(c*d*e, 2);
    float V = sqrt(M + N + P - Q)/12;
    printf("%f", V);
}