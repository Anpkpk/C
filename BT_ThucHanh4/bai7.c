#include <stdio.h>

int main(){
	int i,j,k,m,n;
	float p;
	printf("Nhap so hang m, so cot n:\n");
	scanf("%d %d", &m,&n);
	float a[m+1][n+1], b[n+1];
	
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			scanf("%f", &a[i][j]);
		}
	}
	
	for(j=1;j<m;j++){
		for(i=(j+1);i<=m;i++){
			// Xet tung hang i ben duoi hang k
			// Voi moi hang i
			// k=1 khu tu cot 1 -> n
			// k=2 khu tu cot 2 -> n
			if(a[j][j]!=0){
				p = a[i][j]/a[j][j];
				// Lay hang i tru di p lan hang k
				for(k=j;k<=n;k++){
					a[i][k] = a[i][k] - p*a[j][k];
				}
			}
		}
	}
	
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			printf("%.1f ", a[i][j]);
			if(j==n){
				printf("\n");
			}
		}
	}
	
	return 0;
}