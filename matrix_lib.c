#include <stdio.h>
#include "matrix.h"


#define ROWS_A 2
#define COLS_A 2
#define ROWS_B 2
#define COLS_B 3
#define ROWS_C 2
#define COLS_C 3

void transpose(int theRows, int theCols, int in[theRows][theCols], int out[theCols][theRows]) {
    int rowIf = 0;
    do {
        for (int colIs = 0; colIs < theCols; colIs++) {
            out[colIs][rowIf] = in[rowIf][colIs];
        }
        rowIf++;
    } while (rowIf < theRows);
}

void scalar_multiply(int rowIs, int colIf, int in[rowIs][colIf], int scalar, int out[rowIs][colIf]) {
    int i = 0;
    do {
        for (int j = 0; j < colIf; j++) {
            out[i][j] = in[i][j] * scalar;
        }
        i++;
    } while (i < rowIs);
}

void multiply(int rows1, int cols1, int m1[rows1][cols1],
              int rows2, int cols2, int m2[rows2][cols2],
              int result[rows1][cols2]) {
    int rowIf = 0;
    do {
        for (int colIf = 0; colIf < cols2; colIf++) {
            result[rowIf][colIf] = 0;
            int theK = 0;
            do {
                result[rowIf][colIf] += m1[rowIf][theK] * m2[theK][colIf];
                theK++;
            } while (theK < cols1);
        }
        rowIf++;
    } while (rowIf < rows1);
}

void add(int rowIf, int colIs, int a[rowIf][colIs], int b[rowIf][colIs], int result[rowIf][colIs]) {
    int i = 0;
    do {
        for (int j = 0; j < colIs; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
        i++;
    } while (i < rowIf);
}

void print_matrix(int rowIf, int colIf, int mat[rowIf][colIf]) {
    int i = 0;
    do {
        for (int j = 0; j < colIf; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
        i++;
    } while (i < rowIf);
}

int main() {
    int A[ROWS_A][COLS_A] = {{6, 4}, {8, 3}};
    int B[ROWS_B][COLS_B] = {{1, 2, 3}, {4, 5, 6}};
    int C[ROWS_C][COLS_C] = {{2, 4, 6}, {1, 3, 5}};

    int B_scaled[ROWS_B][COLS_B];
    int C_transposed[COLS_C][ROWS_C];
    int mult_result[ROWS_A][COLS_A];
    int D[ROWS_A][COLS_A];

    scalar_multiply(ROWS_B, COLS_B, B, 3, B_scaled);
    transpose(ROWS_C, COLS_C, C, C_transposed);
    multiply(ROWS_B, COLS_B, B_scaled, COLS_C, ROWS_C, C_transposed, mult_result);
    add(ROWS_A, COLS_A, A, mult_result, D);

    printf("Matrix D = A + (3 * B) * C^T:\n");
    print_matrix(ROWS_A, COLS_A, D);

    return 0;
}
