// Bài 7
#include <stdio.h>
#include <stdlib.h>

void merge();
void mergerSort();

void mergeSort(int *array, int n){
    if (n <= 1) return;
    int middle = n/2;
    int leftSize = middle, rightSize = n - middle;
    int leftArray[leftSize], rightArray[rightSize];
    int j = 0, i = 0;
    for (i = 0; i < n; i++){
        if (i < middle) {
            leftArray[i] = array[i];
        }
        else {
            rightArray[j] = array[i];
            j++;
        }
    }
    mergeSort(leftArray, leftSize);
    mergeSort(rightArray, rightSize);
    merge(leftArray, leftSize, rightArray, rightSize, array);
}

void merge(int *leftArray, int leftSize, int *rightArray, int rightSize, int *array){
    int i = 0, l = 0, r = 0;
    while (l < leftSize && r < rightSize)
    {
        if (leftArray[l] < rightArray[r]){
            array[i] = leftArray[l];
            i++;
            l++;
        }
        else {
            array[i] = rightArray[r];
            i++;
            r++;
        }
    }
    while (l < leftSize){
        array[i] = leftArray[l];
        l++;
        i++;
    }
    while (r < rightSize){
        array[i] = rightArray[r];
        i++;
        r++;
    }
}

int *Sort(int n){
    int *A = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
    mergeSort(A, n);
    return A;
}
void printArray(int *a, int n){
    for (int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
}
int main(){
    int n;
    scanf("%d", &n);
    int *a = Sort(n);
    printArray(a, n);
    free(a);
}