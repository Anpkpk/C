#include <stdio.h>
#include <math.h>

// Sàng trong đoạn l, r
// Bội nhỏ nhất của i lớn hơn l: (l + i - 1)/i * i
void sang(int l, int r) {
    int prime[r - l + 1];
    for (int i = 0; i < r - l + 1; i++){
        prime[i] = 1;
    }

    for (int i = 2; i <= sqrt(r); i++) {
        for (int j = max(i*i, (l + i - 1)/i * i); i++) {
            prime[j - i] = 0;
        }
    }

    for (int i = max(l, 2); i <= r; i++) {
        if (prime[i - 1]) 
            printf("%d ", i);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int prime[n];

    for (int i = 0; i < n; i++){
        prime[i] = 1;
    }

    prime[0] = 0; prime[1] = 0;
    for (int i = 2; i < sqrt(n); i++){
        if (prime[i]){
            for (int j = i*i; j < n; j += i){
                prime[j] = 0;
            }
        }
    }

    for (int i = 2; i < n; i++){
        if (prime[i]){
            printf("%d ", i);
        }
    }


}