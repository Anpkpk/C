#include <stdio.h>

void print(int a[9][9]){
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int check(int a[][9], int row, int col, int x){
    for (int i = 0; i < 9; i++){
        if (a[i][col] == x) return 0;
    }

    for (int j = 0; j < 9; j++){
        if (a[row][j] == x) return 0;
    }

    int i1 = row - row % 3;
    int j1 = col - col % 3;
    for (int i = i1; i < i1 + 3; i++){
        for (int j = j1; j1 + 3; j++){
            if (a[i][j] == x) return 0;
        }
    }
    return 1;
}

int backTrack(int a[][9], int row, int col){
    if (row == 8 && col == 9) return 1;
    if (col == 9) {
        row++;
        col = 0;
    }
    if (a[row][col] != 0) {
        return  backTrack(a, row, col + 1);
    }
    for (int j = 1; j <= 9; j++){
        if (check(a, row, col, j)){
            a[row][col] = j;
            if (backTrack(a, row, col + 1)){
                return 1;
            }
        }
        a[row][col] = 0;
    }
    return 0;
}

int main(){
    int a[9][9] = { 
						{ 3, 0, 6, 5, 0, 8, 4, 0, 0 },
						{ 5, 2, 0, 0, 0, 0, 0, 0, 0 },
						{ 0, 8, 7, 0, 0, 0, 0, 3, 1 },
						{ 0, 0, 3, 0, 1, 0, 0, 8, 0 },
						{ 9, 0, 0, 8, 6, 3, 0, 0, 5 },
						{ 0, 5, 0, 0, 9, 0, 6, 0, 0 },
						{ 1, 3, 0, 0, 0, 0, 2, 5, 0 },
						{ 0, 0, 0, 0, 0, 0, 0, 7, 4 },
						{ 0, 0, 5, 2, 0, 6, 3, 0, 0 } 
						};
	if(backTrack(a, 0, 0)){
		print(a);
	}
}