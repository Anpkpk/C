// Bài 8
#include <stdio.h>
#include <math.h>

// e mũ x đến phần dư đủ nhỏ 1 + x + x^2 + ... + x^n/n!
float fun(int x) {
    float sum = 1;
    int i = 1;
    float temp = x;
    while ( temp > 1e-10 ) {
        sum += temp;
        i++;
        temp = temp * x / i;
    }
    return sum;
}

// x^a với phần dư err ~ e^(a*ln(x))
float Maclaurin(float x, float a, float err){
    float alnx = a*log(x);
    float sum = 1;
    int i = 1;
    float temp = alnx;
    while (temp > err){
        sum += temp;
        i++;
        temp = temp * alnx / i;
    }
    return sum;
}

int main(){
    float x, a, err;
    scanf("%f%f%f", &x, &a, &err);
    printf("%f", Maclaurin(x, a, err));
}