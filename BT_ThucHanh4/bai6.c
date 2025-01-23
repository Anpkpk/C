#include <stdio.h>
#include <stdlib.h>

int main(){
    int m, n;
    scanf("%d%d", &m, &n);
    float a[m][n];

    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            scanf("%f", &a[i][j]);
        }
    }
    scanf("\n");
    int i, j;
    float k;
    char c;
    scanf("%c", &c);
    scanf("\n");
    switch (c)
    {
    case 'S':
        scanf("%d%d", &i, &j);
        for (int col = 0; col < n; col++){
            float tmp = a[i][col];
            a[i][col] = a[j][col];
            a[j][col] = tmp;
        }
        break;
    case 'M':
        scanf("%d%f", &i, &k);
        for (int col = 0; col < n; col++){
            a[i][col] *= k;
        }
        break;
    case 'A':
        scanf("%d%f%d", &i, &k, &j);
        for (int col = 0; col < n; col++){
            a[i][col] += k*a[j][col];
        }
        break;

    default:
        break;
    }
    for (int row = 0; row < m; row++){
        for (int col = 0; col < n; col++){
            printf("%.2f ", a[row][col]);
        }
        printf("\n");
    }
}   
    
        
    
        