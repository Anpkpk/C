#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int **box;
} sudoku;


void createSudoku(sudoku *board){
    board->box = (int**)malloc(9*sizeof(int*));
    for (int i = 0; i < 9; i++){
        board->box[i] = (int*)malloc(9*sizeof(int));
    }
}

void scanSudoku(FILE *f, sudoku *board){
    createSudoku(board);
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            fscanf(f, "%d", &board->box[i][j]);
        }
    }
}

int sloveSudoku(sudoku *board, int row, int col, int x){
    for (int i = 0; i < 9; i++){
        if (x == board->box[i][col]) return 0;
    }

    for (int j = 0; j < 9; j++){
        if (x == board->box[row][j]) return 0;
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = startRow; i < startRow + 3; i++){
        for (int j = startCol; j < startCol + 3; j++){
            if (board->box[i][j] == x) return 0;
        }
    }
    return 1;
}

int backTrack(sudoku *board, int row, int col){
    if (row == 8 && col == 9) 
        return 1;
    if (col == 9){
        row++;
        col = 0;
    }
    if (board->box[row][col] != 0){
        return backTrack(board, row, col + 1);
    }

    for (int j = 1; j <= 9; j++){
        if (sloveSudoku(board, row, col, j)){
            board->box[row][col] = j;
            if (backTrack(board, row, col + 1)) 
                return 1;
        }
        board->box[row][col] = 0;
    }
    return 0;   
}

void freeMatrix(int **a, int m){
    for (int i = 0; i < m; i++){
        free(a[i]);
    }
    free(a);
}

void printSudoku(FILE *g, sudoku *board){
    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            fprintf(g, "%d ", board->box[i][j]);
        }
        fprintf(g, "\n");
    }
}

int main(){
    FILE *f = fopen("data11.txt", "r");
    FILE *g = fopen("outp11.txt", "w");

    sudoku board;

    scanSudoku(f, &board);
    backTrack(&board, 0, 0);
    printSudoku(g, &board);

    freeMatrix(board.box, 9);
    fclose(f);
    fclose(g);
}