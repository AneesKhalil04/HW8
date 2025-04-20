#ifndef MATRIXCPP_H
#define MATRIXCPP_H

#include <vector>
using namespace std;

class Matrix {
private:
    int theNumRows;
    int theNumCols;
    vector<vector<int>> matrixIs;

public:
    Matrix(int rowIf, int colIf);
    Matrix(const vector<vector<int>>& inputData);

    Matrix transpose() const;
    Matrix operator*(int factorIf) const;
    Matrix operator*(const Matrix& theOtherMatrix) const;
    Matrix operator+(const Matrix& theOtherMatrix) const;

    void print() const;
    void setValue(int rowIf, int colIf, int valueIf);
    int getValue(int rowIf, int colIf) const;

    int getNumRows() const;
    int getNumCols() const;
};

#endif
