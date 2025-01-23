#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int val[] = {1, 5, 10, 50, 100, 500, 1000};
char s[] = "IVXLCDM";

int pos(char c){
    for (int i = 0; i < 7; i++){
        if (c == s[i]) return i;
    }
}

int slove(char c[]){
    int n = strlen(c);
    int res = val[pos(c[n - 1])];

    for (int i = n - 1; i >= 0; i--){
        // Lấy vị trí 2 kí tự la mã liên tiếp
        int pos1 = pos(c[i]);
        int pos2 = pos(c[i - 1]);

        // Kiểm tra gí trị liên tiếp của kí tự La Mã
        // Trước nhỏ hơn sau thì trừ, Lớn hơn thì cộng
        if (val[pos1] <= val[pos2]) {
            res += val[pos2];
        }
        else res -= val[pos2];
    }
    return res;
}
int main(){
    char c[1000];
    scanf("%s", c);
    printf("%d", slove(c));
}