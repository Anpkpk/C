#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} point;

void scan(FILE *f, point *p, int n){
    for (int i = 0; i < n; i++){
        fscanf(f, "%f%f", &(p + i)->x, &(p + i)->y);
    }
}

float length(point *a, point *b){
    return sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2));
}

float perimeter(point *p, int n){
    float per = 0;
    for (int i = 0; i < n - 1; i++){
        per += length((p + i), (p + i + 1));
    }
    per += length((p + 0), (p + n - 1));
    return per;
}

int main(){
    FILE *f = fopen("data_input.txt", "r");
    FILE *g = fopen("data_output.txt", "w");

    int n;
    fscanf(f, "%d", &n);

    point *p = (point*)malloc(n*sizeof(point));

    scan(f, p, n);
    fprintf(g, "%f", perimeter(p, n));

    free(p);
    fclose(f);
    fclose(g);
}