#include <stdio.h>

#define ROWS 2
#define COLS 2

void addMatrices(int a[ROWS][COLS], int b[ROWS][COLS], int result[ROWS][COLS]);
void multiplyMatrices(int a[ROWS][COLS], int b[ROWS][COLS], int result[ROWS][COLS]);
void printMatrix(int matrix[ROWS][COLS]);

int main() {
    int matrix1[ROWS][COLS] = {{1, 2}, {3, 4}};
    int matrix2[ROWS][COLS] = {{5, 6}, {7, 8}};
    int sum[ROWS][COLS], product[ROWS][COLS];

    addMatrices(matrix1, matrix2, sum);
    multiplyMatrices(matrix1, matrix2, product);

    printf("Matrix Addition:\n");
    printMatrix(sum);

    printf("Matrix Multiplication:\n");
    printMatrix(product);

    return 0;
}

void addMatrices(int a[ROWS][COLS], int b[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}

void multiplyMatrices(int a[ROWS][COLS], int b[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = 0;
            for (int k = 0; k < COLS; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void printMatrix(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
