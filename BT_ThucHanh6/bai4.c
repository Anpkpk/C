// Bai 4
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float *equation(float a, float b, float c){
    float *answer = (float*)malloc(3*sizeof(float));
    if (a == 0 && b == 0 && c == 0) {
        answer[0] = 3;
    }
    else if (a == 0 && b == 0 && c != 0 ) {
        answer[0] = 0;
        answer[1] = 0;
        answer[2] = 0;
    }
    else if (a == 0 && b != 0 && c != 0){
        answer[0] = 1;
        answer[1] = -c/b;
        answer[2] = -c/b;
    }
    else {
        float delta = b*b - 4*a*c;
        if (delta < 0){
            answer[0] = 0;
        }
        else if (delta == 0){
            answer[0] = 1;
            answer[1] = -b/(2*a);
            answer[2] = -b/(2*a);
        }
        else {
            answer[0] = 2;
            answer[1] = (-b - sqrt(delta))/(2*a);
            answer[2] = (-b + sqrt(delta))/(2*a);
        }
    }
    return answer;
}
int main(){
    float a, b, c;
    scanf("%f%f%f", &a, &b, &c);
    float *output;
    output = equation(a, b, c);
    for (int i = 0; i < 3; i++){
        if (i == 0){
            printf("%.0f ", output[i]);
        }
        else 
            printf("%f ", output[i]);
    }
    free(output);
}