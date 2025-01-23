#include <stdio.h>
#include <math.h>

// Hàm in tấm thảm Sierpinski cấp n
void printSierpinski(FILE *g, int n) {
    int size = pow(3, n);
    char carpet[size][size];
    
    // Khởi tạo tấm thảm ban đầu với ký tự '*'
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            carpet[i][j] = '*';
        }
    }

    // Xóa các ô giữa để tạo ra hình thảm Sierpinski
    for(int step = 1; step <= n; step++) {
        int stepSize = pow(3, step);
        int gap = pow(3, n - step);

        for(int i = gap; i < size; i += 3 * gap) {
            for(int j = gap; j < size; j += 3 * gap) {
                for(int k = 0; k < gap; k++) {
                    for(int l = 0; l < gap; l++) {
                        carpet[i + k][j + l] = ' ';
                    }
                }
            }
        }
    }

    // In tấm thảm Sierpinski ra màn hình
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            fprintf(g, "%c ", carpet[i][j]);
        }
        fprintf(g, "\n");
    }
}

int main() {
    int n;
    FILE *g = fopen("outp10.txt", "w");
    printf("Nhap so cap cua tam tham Sierpinski: ");
    scanf("%d", &n);
    printSierpinski(g, n);
    return 0;
}
