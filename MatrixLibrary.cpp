#include <iostream>
#include <vector>
#include "Matrixcpp.h"
using namespace std;

Matrix::Matrix(int rowIf, int colIf) {
    theNumRows = rowIf;
    theNumCols = colIf;
    matrixIs = vector<vector<int>>(theNumRows, vector<int>(theNumCols, 0));
}

Matrix::Matrix(const vector<vector<int>>& inputData) {
    theNumRows = inputData.size();
    theNumCols = inputData[0].size();
    matrixIs = inputData;
}

Matrix Matrix::transpose() const {
    Matrix theTransposed(theNumCols, theNumRows);
    int i = 0;
    do {
        for (int j = 0; j < theNumCols; ++j)
            theTransposed.matrixIs[j][i] = matrixIs[i][j];
        i++;
    } while (i < theNumRows);
    return theTransposed;
}

Matrix Matrix::operator*(int factorIf) const {
    Matrix resultIf(theNumRows, theNumCols);
    int i = 0;
    do {
        for (int j = 0; j < theNumCols; ++j)
            resultIf.matrixIs[i][j] = matrixIs[i][j] * factorIf;
        i++;
    } while (i < theNumRows);
    return resultIf;
}

Matrix Matrix::operator*(const Matrix& theOtherMatrix) const {
    if (theNumCols != theOtherMatrix.theNumRows) {
        cout << "the matrix dimensions cant be multiplied due to the demensions\n";
        return Matrix(0, 0);
    }

    Matrix resultIs(theNumRows, theOtherMatrix.theNumCols);
    int i = 0;
    do {
        for (int j = 0; j < theOtherMatrix.theNumCols; ++j) {
            int k = 0;
            do {
                resultIs.matrixIs[i][j] += matrixIs[i][k] * theOtherMatrix.matrixIs[k][j];
                k++;
            } while (k < theNumCols);
        }
        i++;
    } while (i < theNumRows);
    return resultIs;
}

Matrix Matrix::operator+(const Matrix& theOtherMatrix) const {
    if (theNumRows != theOtherMatrix.theNumRows || theNumCols != theOtherMatrix.theNumCols) {
        cout << "Error: Matrix dimensions don't match for addition.\n";
        return Matrix(0, 0);
    }

    Matrix resultMatrix(theNumRows, theNumCols);
    int i = 0;
    do {
        for (int j = 0; j < theNumCols; ++j)
            resultMatrix.matrixIs[i][j] = matrixIs[i][j] + theOtherMatrix.matrixIs[i][j];
        i++;
    } while (i < theNumRows);
    return resultMatrix;
}

void Matrix::print() const {
    int rowIf = 0;
    do {
        for (int colIf = 0; colIf < theNumCols; ++colIf)
            cout << matrixIs[rowIf][colIf] << " ";
        cout << endl;
        rowIf++;
    } while (rowIf < theNumRows);
}

void Matrix::setValue(int rowIf, int colIf, int valueIf) {
    if (rowIf >= 0 && rowIf < theNumRows && colIf >= 0 && colIf < theNumCols)
        matrixIs[rowIf][colIf] = valueIf;
}

int Matrix::getValue(int rowIf, int colIf) const {
    return matrixIs[rowIf][colIf];
}

int Matrix::getNumRows() const {
    return theNumRows;
}

int Matrix::getNumCols() const {
    return theNumCols;
}

int main() {
    vector<vector<int>> aData = {{6, 4}, {8, 3}};
    vector<vector<int>> bData = {{1, 2, 3}, {4, 5, 6}};
    vector<vector<int>> cData = {{2, 4, 6}, {1, 3, 5}};

    Matrix theA(aData);
    Matrix theB(bData);
    Matrix theC(cData);

    Matrix resultIf = theA + (theB * 3) * theC.transpose();

    cout << "Matrix D = A + (3 * B) * C^T:\n";
    resultIf.print();

    return 0;
}
