#include <stdio.h>

void print(int n){
    if (n == 1){
        printf("WILBUR IS THE ELDER BROTHER");
    } else {
        printf("ORVILLE IS THE ELDER BROTHER");
    }
}
int main(){
    int dd1, dd2, mm1, mm2, yy1, yy2;
    scanf("%d%d%d", &dd1, &mm1, &yy1);
    scanf("%d%d%d", &dd2, &mm2, &yy2);
    if (yy2 > yy1){
        print(2);
    } else if (yy2 < yy1){
        print(1);
    } else {
        if (mm1 > mm2) {
            print(1);
        } else if (mm1 < mm2){
            print(2);
        } else {
            if (dd1 > dd2){
                print(1);
            } else print(2);
        }
    }
}