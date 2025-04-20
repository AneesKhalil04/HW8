#ifndef MATRIX_H
#define MATRIX_H

void transpose(int theRows, int theCols, int in[theRows][theCols], int out[theCols][theRows]);
void scalar_multiply(int rowIs, int colIf, int in[rowIs][colIf], int scalar, int out[rowIs][colIf]);
void multiply(int rows1, int cols1, int m1[rows1][cols1],
              int rows2, int cols2, int m2[rows2][cols2],
              int result[rows1][cols2]);
void add(int rowIf, int colIs, int a[rowIf][colIs], int b[rowIf][colIs], int result[rowIf][colIs]);
void print_matrix(int rowIf, int colIf, int mat[rowIf][colIf]);

#endif
