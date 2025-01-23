// Bài 17
#include <stdio.h>
#include <stdlib.h>

void scanMatrix(float **a, int n, int m){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			scanf("%f", &a[i][j]);
		}
	}
}

void printMatrix(float **a, int n, int m){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			printf("%.2f ", a[i][j]);
		}
		printf("\n");
	}
}

float **createMatrix(int n, int m){
	float **a = (float**)malloc(m*sizeof(float*));
	for (int i = 0; i < m; i++){
		a[i] = (float*)calloc(n, sizeof(float));
	}
	return a;
}

float **extended(float **a, int n, int m){
	float **b = (float**)malloc(n*sizeof(float*));
	for (int i = 0; i < n; i++){
		b[i] = (float*)malloc(m*sizeof(float));
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (j < n){
				b[i][j] = a[i][j];
			}
			else {
				if (j == n + i){
					b[i][j] = 1.0;
				}
				else {
					b[i][j] = 0.0;
				}
			}
		}
	}
	return b;
}

void Gauss_Jordan(float **a, int n, int m){
	for (int j = 0; j < n; j++){
		for (int i = j + 1; i < n; i++){
			if (a[i][j] != 0){
				float factor = a[j][j] / a[i][j];
				for (int k = 0; k < m; k++){
					if (a[i][k] == 0 && a[j][k] == 0) continue;
					a[i][k] = a[i][k]*factor - a[j][k];
				}
			}
		}
	}
	for (int i = 0; i < n; i++){
		if (a[i][i] != 0){
			float factor = a[i][i];
			for (int j = i; j < m; j++){
				a[i][j] /= factor;
			}
		}	
	}
	
	for (int j = n - 1; j >= 0; j--){
		for (int i = j - 1; i >= 0; i--){
			if (a[i][i] != 0 && a[i][j] != 0){
				float factor = a[i][j];
				for (int k = 0; k < m; k++){
					a[i][k] = a[i][k] - factor*a[j][k];
				}
			}
		}
	}	
}

float **reverse(float **a, int n, int *flag){
	a = extended(a, n, 2*n);
	Gauss_Jordan(a, n, 2*n);
	float **A = createMatrix(n, n);
	for (int i = 0; i < n; i++){
		for (int j = n; j < 2*n; j++){
			A[i][j - n] = a[i][j];
		}
	} 
	return A;
}

void freeMatrix(float **a, int n){
	for (int i = 0; i < n; i++){
		free(a[i]);
	}
	free(a);
}

int main(){
	int n, flag = 0;
	scanf("%d", &n);
	float **a = createMatrix(n, n);
	scanMatrix(a, n, n);
	float **b = reverse(a, n, &flag);
	printf("%d\n", flag);
	printMatrix(b, n, n);
	freeMatrix(b, n);
	freeMatrix(a, n);
}
