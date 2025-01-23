#include <stdio.h>
#include <math.h>

int main(){
    int n;
    float m;
    int k;
    scanf("%d%f%d", &n, &m, &k);
    float kq = n;
    for (int i = 1; i <= k; i++){
        kq += kq * (m/100);
    }
    int answer = round(kq);
    printf("%d", answer);
}
