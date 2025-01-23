#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char num[1000];
    char d;
    int *a;
} bignum;

void setBignum(FILE *f, bignum *a){
    fscanf(f, "%s", a->num);
}

void getBignum(FILE *g, bignum *a){
    for (int i = 0; i < strlen(a->num); i++)
        fprintf(g, "%c", a->num[i]);
}

void getNumInBignum(bignum *a, int n){
    for (int i = 0; i < n; i++){
        a->a[i] = a->num[i] - '0';
    }
}

int compBignum(bignum *a, bignum *b){
    if (strlen(a->num) > strlen(b->num)) return 1;
    if (strlen(a->num) < strlen(b->num)) return -1;
    if (strcmp(a->num, b->num) < 0) return -1;
    else return 1;
}

void getComp(FILE *g, bignum *a, bignum *b){
    fprintf(g, "%d\n", compBignum(a, b));
}

void revers(bignum *a){
    int l = 0;
    int r = strlen(a->num) - 1;
    while (l < r){
        int tmp = a->a[l];
        a->a[l] = a->a[r];
        a->a[r] = tmp;
        l++;
        r--;
    }
    for (int i = 0; i < strlen(a->num); i++){
        a->num[i] = a->a[i] + '0';
    }
}

void sumBignum(bignum *x1, bignum *x2, bignum *sum){
    int n1 = strlen(x1->num);
    int n2 = strlen(x2->num);
    int n = 0;

    x1->a = (int*)malloc(n1*sizeof(int));
    x2->a = (int*)malloc(n1*sizeof(int));

    getNumInBignum(x1, n1);
    getNumInBignum(x2, n1);

    revers(x1);
    revers(x2);

    for (int i = n2; i < n1; i++) x2->a[i] = 0;

    int nho = 0, tmp;
    sum->a = (int*)malloc((n1 + 1)*sizeof(int));

    for (int i = 0; i < n1; i++){
        tmp = x1->a[i] + x2->a[i] + nho;
        sum->a[n++] = tmp % 10;
        nho = tmp/10;
    }

    if (nho) sum->a[n++] = nho;
    sum->num[n] = '\0';
    revers(sum);
    for (int i = 0; i < n; i++){
        sum->num[i] = sum->a[i] + '0';
    }
    
    free(x1->a);
    free(x2->a);
}

int main(){
    FILE *f = fopen("data10a.txt", "r");
    FILE *g = fopen("outp10a.txt", "w");

    bignum a;
    bignum b;
    bignum sum;

    setBignum(f, &a);
    setBignum(f, &b);

    // getBignum(g, &a);
    // getNumInBignum(g, &a);
    // getComp(g, &a, &b);
    sumBignum(&b, &a, &sum);
    revers(&sum);
    getBignum(g, &sum);
    
    free(sum.a);
    fclose(f);
    fclose(g);
}