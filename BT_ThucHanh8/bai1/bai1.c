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

void printFile(FILE *g, student *s, int n){
    for (int i = 0; i < n; i++){
        fprintf(g, "%-25s%-9d%.2f\n", (s + i)->name, (s+ i)->year, (s + i)->point);
    }
}
int main(){
    int n;

    FILE *f = fopen("data_input.txt", "r");
    FILE *g = fopen("data_output.txt", "w");

    fscanf(f, "%d%*c", &n);
    fprintf(g, "%d\n", n);
    student *s = (student*)malloc(n * sizeof(student));

    scanFile(f, s, n);
    printFile(g, s, n);  
    fclose(f); fclose(g);
    free(s);
}