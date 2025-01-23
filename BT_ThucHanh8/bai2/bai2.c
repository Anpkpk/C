#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    float point;
    int year;
    char name[100];
} student;

void scanFile(FILE *f, student *s, int n){
    for (int i = 0; i < n; i++){
        fscanf(f, "%25[^\n]", (s + i)->name);
        fscanf(f, "%d", &(s + i)->year);
        fscanf(f, "%f%*c", &(s + i)->point);
    }
}

void printFile(FILE *file, student *s, int n){
    FILE *A = fopen("data_student_A.txt", "w");
    FILE *B = fopen("data_student_B.txt", "w");
    FILE *C = fopen("data_student_C.txt", "w");
    FILE *D = fopen("data_student_D.txt", "w");
    FILE *F = fopen("data_student_F.txt", "w");
    for (int i = 0; i < n; i++){
        float point = (s + i)->point;
        if (point >= 8.5) {
            fprintf(A, "%-25s%-9d%.2f\n", (s + i)->name, (s+ i)->year, (s + i)->point);
        }
        else if (point >= 7.0){
            fprintf(B, "%-25s%-9d%.2f\n", (s + i)->name, (s+ i)->year, (s + i)->point);
        }
        else if (point >= 5.5){
            fprintf(C, "%-25s%-9d%.2f\n", (s + i)->name, (s+ i)->year, (s + i)->point);
        }
        else if (point >= 4.0){
            fprintf(D, "%-25s%-9d%.2f\n", (s + i)->name, (s+ i)->year, (s + i)->point);
        }
        else {
            fprintf(F, "%-25s%-9d%.2f\n", (s + i)->name, (s+ i)->year, (s + i)->point);
        }
    }
    fclose(A);
    fclose(B);
    fclose(C);
    fclose(D);
    fclose(F);
}

int main(){
    int n;

    FILE *f = fopen("data_input.txt", "r");

    fscanf(f, "%d%*c", &n);
    student *s = (student*)malloc(n*sizeof(student));

    scanFile(f, s, n);
    printFile(f, s, n);
    
    fclose(f);
}
    