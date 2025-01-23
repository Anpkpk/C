#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *Prime(int n){
    int *prime = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++){
        prime[i] = 1;
    }

    prime[0] = 0; 
    prime[1] = 0;

    for (int i = 2; i < sqrt(n); i++){
        if (prime[i]){
            for (int j = i*i; j < n; j += i){
                prime[j] = 0;
            }
        }
    }
    return prime;
}

int sopt(int n){
    if (n == 0) return 1;
    int so = 0;
    while (n != 0){
        so++;
        n /= 10;
    }
    return so;
}

int main(){
    int n;
    scanf("%d", &n);

    int *prime = Prime(n);

    FILE *f = fopen("outp6.txt", "w");

    int cnt = sopt(n);
    
    for (int i = 0; i < n; i++){
        int temp = sopt(i);
        while (temp < cnt){
            fprintf(f, " ");
            temp++;
        }
        if (prime[i]){
            if (sopt(i) == 1)
                fprintf(f, "%d ", i);
            else {
                fprintf(f, "%2d ", i);
            }
        }
        else{
            int tmp = i;
            if (tmp == 0) tmp = 1;
            while (tmp != 0){
                fprintf(f, "_");
                tmp /= 10;
            }
            fprintf(f, " ");
        }
        if ((i + 1)%10 == 0){
            fprintf(f, "\n");
        }
    }

    free(prime);
    fclose(f);
}