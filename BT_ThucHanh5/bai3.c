#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    int *a = malloc(n*sizeof(int));
    for (int i = 0; i < n; i++){
        scanf("%d", a + i);
    }
    int k, b;
    scanf("%d%d", &k, &b);
    // Delete a element
    // for (int i = k - 1; i < n - 1; i++){
    //     *(a + i) = *(a + i + 1);
    // }
    // n = n - 1;
    // Add a element
    n = n + 1;
    for (int i = n; i > k; i--){
        *(a + i) = *(a + i - 1);
    }
    *(a + k) = b;
    a = realloc(a, (n)*sizeof(int));
    for (int i = 0; i < n; i++){
        printf("%d ", *(a + i));
    }
    free(a);
}