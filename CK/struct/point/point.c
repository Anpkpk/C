#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} point;

float length(point a, point b){
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

int main(){
    FILE *f = fopen("data_input.txt", "r");
    FILE *g = fopen("data_output.txt", "w");

    point A, B;

    fscanf(f, "%f%f%f%f", &A.x, &A.y, &B.x, &B.y);

    fprintf(g, "%f", length(A, B));

    fclose(f);
    fclose(g);
}