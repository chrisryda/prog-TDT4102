#include "Matrix.h"
#include <iostream>
#include <utility>
#include <iomanip>
#include <cassert>

using namespace std;

Matrix::Matrix(int rows, int columns) {
    assert(rows > 0 && columns > 0);
    n_rows = rows;
    n_columns = columns;
    
    matrix = new double*[n_rows]; // each element is a pointer to an array.
    for(int i = 0; i < n_rows; ++i) {
        matrix[i] = new double[n_columns];
        for(int j = 0; j < n_columns; ++j) {
            matrix[i][j] = 0;
        }
    }
}

Matrix::Matrix(int rows) : Matrix(rows, rows) {
    for (int i = 0; i < rows; ++i) {
        matrix[i][i] = 1;
    }
}

Matrix::Matrix(const Matrix &rhs) : matrix{ nullptr } {
    this->n_rows = rhs.n_rows;
    this->n_columns = rhs.n_columns;
    this->matrix= new double*[rhs.n_rows] {};

    for(int i = 0; i < rhs.n_rows; ++i) {
        this->matrix[i] = new double[rhs.n_columns];
        for(int j = 0; j < rhs.n_columns; ++j) {
            this->matrix[i][j] = rhs.matrix[i][j];
        }
    }
}

Matrix::~Matrix() {
    for(int i = 0; i < n_rows; ++i) {
        delete matrix[i];
    }
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
    for(int i = 0; i < m.n_rows; ++i) {
        os <<  "[ ";
        for(int j = 0; j < m.n_columns; ++j) {
            os << setprecision(4) << m.matrix[i][j] << " ";
        }
        os << " ]" << endl;
    }
    return os;
}

Matrix &Matrix::operator=(Matrix rhs) {
    std::swap(n_rows, rhs.n_rows);
    std::swap(n_columns, rhs.n_columns);    
    std::swap(matrix, rhs.matrix);
    return *this;
}

Matrix &Matrix::operator+=(Matrix rhs) {
    assert(n_rows == rhs.n_rows && n_columns == rhs.n_columns);
    for(int i = 0; i < n_rows; ++i) {
        for(int j = 0; j < n_columns; ++j) {
            this->matrix[i][j] += rhs.matrix[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator+(Matrix rhs) {
    Matrix m = *this;
    m += rhs;
    return m;
}
