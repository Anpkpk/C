#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int year;
    float cuoiKy;
    float chuyenCan;
    float giuaKy;
    float avg;
    char name[100];
} sinhvien;

void scanFile(FILE *f, sinhvien *s, int n){
     for (int i = 0; i < n; i++){
        fscanf(f, "%25[^\n]", &(s + i)->name);
        fscanf(f, "%d", &(s + i)->year);
        fscanf(f, "%f", &(s + i)->chuyenCan);
        fscanf(f, "%f", &(s + i)->giuaKy);
        fscanf(f, "%f%*c", &(s + i)->cuoiKy);
    }
}

void printFile(FILE *g, sinhvien *s, int n){
     for (int i = 0; i < n; i++){
        fprintf(g, "%25s%-9d%-9.2f\n", (s + i)->name, (s + i)->year, (s + i)->avg);
    }
}

void sort(sinhvien *s, int n){
    for (int i = 0; i < n; i++){
        (s + i)->avg =  20*((s + i)->chuyenCan)/100 + 20*((s + i)->giuaKy)/100 + 60*((s + i)->cuoiKy)/100;
    }

    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if ((s + i)->avg >= (s + j)->avg){
                float tmp = (s + i)->avg;
                (s + i)->avg = (s + j)->avg;
                (s + j)->avg = tmp;
            }
        }
    }
}
int main(){
    FILE *f = fopen("data_input.txt", "r");
    FILE *g = fopen("data_output.txt", "w");

    int n;
    fscanf(f, "%d%*c", &n);
    sinhvien *s = (sinhvien*)malloc(n*sizeof(sinhvien));

    scanFile(f, s, n);
    sort(s, n);
    printFile(g, s, n);

    free(s);
    fclose(f);
    fclose(g);
}