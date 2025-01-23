#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[25];
    int yearOfBirth;
    float score;
} student;

void scan(FILE *f, student *s, int n){
    for (int i = 0; i < n; i++){
        fscanf(f, "%25[^\n]", &s->name);
        fscanf(f, "%d", &s->yearOfBirth);
        fscanf(f, "%f%*c", &s->score);
    }
}

void print(FILE *g, student *s, int n){
    for (int i = 0; i < n; i++){
        fprintf(g, "%-25s%-9d%.2f\n", s->name, s->yearOfBirth, s->score);
    }
}

int main(){
    FILE *f = fopen("data_input.txt", "r");
    FILE *g = fopen("data_output.txt", "w");

    int n;
    fscanf(f, "%d", &n);

    student *s = (student*)malloc(n*sizeof(student));

    scan(f, s, n);
    print(g, s, n);

    free(s);
    fclose(f);
    fclose(g);
}