#include "Matrix.h"
#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;

Matrix::Matrix(int rows, int columns) {
    assert(rows > 0 && columns > 0);
    n_rows = rows;
    n_columns = columns;
    
    matrix = new double*[n_rows]; // each element is a pointer to an array.
    for(size_t i = 0; i < n_rows; ++i) {
        matrix[i] = new double[n_columns]; // build rows
    }
    for(size_t i = 0; i < n_rows; ++i) {
        for(size_t j = 0; j < n_columns; ++j) {
            matrix[i][j] = 0;
        }
    }
}

Matrix::Matrix(int rows) : Matrix(rows, rows) { 
    for (size_t i = 0; i < rows; ++i) {
        matrix[i][i] = 1;
    }
}

Matrix::~Matrix() {
    delete[] matrix;
    matrix = nullptr;
}

int Matrix::getRows() const {
    return n_rows;
}

int Matrix::getColumns() const {
    return n_columns;
}

double Matrix::get(int row, int col) const {
    return matrix[row][col];
}

void Matrix::set(int row, int col, double value) {
    matrix[row][col] = value;
}

double* Matrix::operator[](int n) {
    return matrix[n];
}

ostream& operator<<(ostream &os, const Matrix &m) {
    for(size_t i = 0; i < m.n_rows; ++i) {
        os <<  "[ ";
        for(size_t j = 0; j < m.n_columns; ++j) {
            os << setprecision(4) << m.matrix[i][j] << " ";
        }
        os << " ]" << endl;
    }
    return os;
}
