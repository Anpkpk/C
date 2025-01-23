#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} point;

float length(point *A, point *B){
    return sqrt(pow(A->x - B->x, 2) + pow(A->y - B->y, 2)); 
}
int main(){
    int n;
    scanf("%d", &n);

    point *A = (point*)malloc(n*sizeof(point));
    float cercum = 0;

    for (int i = 0; i < n; i++){
        scanf("%f%f", &(A + i)->x, &(A + i)->y);
    }

    for (int i = 0; i < n - 1; i++){
        cercum += length((A + i), (A + i + 1));
    }
    cercum += length((A + 0), (A + n - 1));
    printf("%.4f", cercum);
    free(A);
}