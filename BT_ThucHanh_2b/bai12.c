#include <stdio.h>

int UCLN(float a, float b){
    if (b == 0) {
        return a;
    } 
    else return UCLN(b, (int)a % (int)b);
}
int BCNN(float a, float b){
    return (a * b)/UCLN(a, b);
}
int main(){
    int v1, v2, v3, v4, v5;
    scanf("%d%d%d%d%d", &v1, &v2, &v3, &v4, &v5);
    float t1, t2, t3, t4, t5;
    t1 = v1 / 9;
    t2 = v2 / 9;
    t3 = v3 / 9;
    t4 = v4 / 9;
    t5 = v5 / 9;
    float kq = BCNN(t1, BCNN(t2, BCNN(t3, BCNN(t4, t5))));
    printf("%d", kq);
}
