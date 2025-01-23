#include <stdio.h>
#include <string.h>

typedef struct {
    int a[1000];
    char num[1000];
    char sign;
} bignum;

void revers(bignum *a){
    int l = 0, r = strlen(a->num) - 1;
    while (l < r){
        char tmp = a->num[l];
        a->num[l] = a->num[r];
        a->num[r] = tmp;
        
        int temp = a->a[l];
        a->a[l] = a->a[r];
        a->a[r] = temp;
        l++;
        r--;
    }
}

void setBignum(FILE *f, bignum *a){
    fscanf(f, "%s", &a->num);
    for (int i = 0; i < strlen(a->num); i++){
        a->a[i] = a->num[i] - '0';
    }
}

void multBignum(bignum *x1, bignum *x2, bignum *mul){
    int n1 = strlen(x1->num), n2 = strlen(x2->num);

    for (int i = 0; i < n1 + n2; i++) {
        mul->num[i] = '0';
        mul->a[i] = 0;
    }
    revers(x1);
    revers(x2);

    for (int i2 = 0; i2 < n2; i2++){
        int i1;
        int nho = 0;
        for (i1 = 0; i1 < n1; i1++){
            int tmp = x1->a[i1] * x2->a[i2] + nho + mul->a[i1 + i2];
            nho = tmp / 10;
            mul->num[i1 + i2] = tmp % 10 + '0';
            mul->a[i1 + i2] = tmp % 10;
        }
        if (nho) {
            mul->a[i1 + i2] = nho;
            mul->num[i1 + i2] = nho + '0';
        }
    }
    if (mul->num[n1 + n2 - 1] != '0') {
        mul->num[n1 + n2] = '\0';
    }
    else 
        mul->num[n1 + n2 - 1] = '\0';
    revers(mul);
}

void subBignum(bignum *x1, bignum *x2, bignum *sub){
    int n1 = strlen(x1->num), n2 = strlen(x2->num);
    int n = 0;

    revers(x1);
    revers(x2);

    for (int i = n2; i < n1; i++) x2->a[i] = 0;

    int tmp, nho = 0;
    for (int i = 0; i < n1; i++){
        tmp = x1->a[i] - x2->a[i] - nho;
        if (tmp < 0){
            sub->a[n++] = tmp + 10;
            nho = 1;
        }
        else {
            sub->a[n++] = tmp;
        }
    }
    
    int check = 0, index = 0;
    for (int i = n - 1; i >= 0; i--){
        if (check == 0 && sub->a[i]){
            check = 1;
        }
        if (check) {
            sub->num[index++] = sub->a[i] + '0';
        }
    }
    sub->num[index] = '\0';
}

void getBignum(FILE *g, bignum *a){
    fprintf(g, "%s\n", a->num);
}

void divBignum(bignum *x1, bignum *x2, bignum *div){
    
}

int main(){
    bignum x1;
    bignum x2;
    bignum mul;
    bignum sub;
    bignum div;

    FILE *f = fopen("data10e.txt", "r");
    FILE *g = fopen("outp10e.txt", "w");

    setBignum(f, &x1);
    setBignum(f, &x2);

    // multBignum(&x1, &x2, &mul);
    // getBignum(g, &mul);

    // subBignum(&x1, &x2, &sub);
    // getBignum(g, &sub);
    
    divBignum(&x1, &x2);

    fclose(f);
    fclose(g);
}