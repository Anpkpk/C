#include <stdio.h>

void merge(int *leftArray, int leftSize, int *rightArray, int righSize, int *array){
    int i = 0, l = 0, r = 0;
    while (l < leftSize && r < righSize){
        if (leftArray[l] <  rightArray[r]){
            array[i] = leftArray[l];
            i++;
            l++;
        }
        else {
            array[i] = rightArray[r];
            r++;
            i++;
        }
    } 
    while (l < leftSize){
        array[i] = leftArray[l];
        i++;
        l++;
    }
    while (r < righSize){
        array[i] = rightArray[r];
        i++;
        r++;
    }
}
void mergeSort(int *array, int n){
    if (n <= 1) return;
    int middle = n/2;
    int i = 0, j = 0;
    int leftArray[middle], rightArray[n - middle];
    for (i = 0; i < n; i++){
        if (i < middle){
            leftArray[i] = array[i];
        }
        else {
            rightArray[j] = array[i];
            j++;
        }
    }
    mergeSort(leftArray, middle);
    mergeSort(rightArray, n - middle);
    merge(leftArray, middle, rightArray, n - middle, array);
}


int main(){
    int a[7];
    for (int i = 0; i < 7; i++){
        scanf("%d", &a[i]);
    }
    mergeSort(a, 7);
    for (int i = 0; i < 7; i++){
        printf("%d ", a[i]);
    }
}