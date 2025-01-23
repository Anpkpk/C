#include <stdio.h>
#include <string.h>
#include <ctype.h>

void inveser(int c[], int len){
    int l = 0, r = len - 1;
    while (l < r)
    {
        int tmp = c[l];
        c[l] = c[r];
        c[r] = tmp;
        r--; l++;
    }
}

void add(char a[], char b[]){
    // Tạo 3 mảng chứa giá trị từng số hạng và kết quả
    int n1 = strlen(a), n2 = strlen(b), n = 0;
    int x1[n1], x2[n1], sum[n1 + 1];

    // Tạo các giá từng giá trị cho 2 mảng số hạng
    for (int i = 0; i < n1; i++) x1[i] = a[i] - '0';
    for (int i = 0; i < n2; i++) x2[i] = b[i] - '0'; 

    // Đảo ngược 2 mảng số hạng
    inveser(x1, n1); 
    inveser(x2, n2);

    // Tạo giá trị 0 cho các phần tử thiếu của mảng nhỏ hơn
    for (int i = n2; i < n1; i++) x2[i] = 0;

    // Cộng theo phép cộng thông thường
    int nho = 0;
    int tmp;
    for (int i = 0; i < n1; i++){
        tmp = x1[i] + x2[i] + nho;
        sum[n++] = tmp % 10;
        nho = tmp / 10;
    }
    // Kiểm tra số dư cuối cùng
    if (nho) sum[n++] = nho;
    
    // In
    for (int i = n - 1; i >= 0; i--) printf("%d", sum[i]);
}
int main(){
    char a[1000], b[1000];
    scanf("%s%s", a, b);
    if (strlen(a) >= strlen(b)) add(a, b);
    else add(b, a);
}