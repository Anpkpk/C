// Bài 5
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float length(float x1, float y1, float x2, float y2){
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}
float triAgle(float x1, float y1, float x2, float y2, float x3, float y3){
    float d1 = length(x1, y1, x2, y2);
    float d2 = length(x1, y1, x3, y3);
    float d3 = length(x2, y2, x3, y3);
    float p = (d1 + d2 + d3)/2;
    return sqrt(p*(p - d1)*(p- d2)*(p- d3));
}

float **polygon(int n){
    float **a = (float**)malloc(n*sizeof(float*));
    for (int i = 0; i < n; i++){
        a[i] = (float*)malloc(2*sizeof(float));
    }
    for (int i = 0; i < n; i++){
        scanf("%f%f", &a[i][0], &a[i][1]);
    }
    return a;
}
float Area(float **a, int n){
    int i = 1, j = 2;
    float area = 0;
    while (j < n)
    {
        area += triAgle(a[0][0], a[0][1], a[i][0], a[i][1], a[j][0], a[j][1]);
        i++;
        j++;
    }
    return area;
}
int main(){
    int n;
    scanf("%d", &n);
    float **A;
    A = polygon(n);
    printf("%f", Area(A, n));
    for (int i = 0; i < n; i++){
        free(A[i]);
    }
    free(A);
}