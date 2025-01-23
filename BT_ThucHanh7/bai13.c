#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char s[][2] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
            // 1     4     5    9     10   40    50   90    100  400   500  900   1000

int val[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};

// Tìm vị trí tương ứng của các số La Mã
int findPos(int n){
    for (int i = 12; i >= 0; i--){
        if (n >= val[i]) return i;
    }
}

void slove(int n){
    char ans[100] = "";
    while (n != 0){
        // Thêm từng kí tự La Mã theo vị trí tương ứng trong mảng giá trị thường
        strcat(ans, s[findPos(n)]);
        n -= val[findPos(n)];
    }
    printf("%s", ans);
}

int main(){
    int n;
    scanf("%d", &n);
    slove(n);
}