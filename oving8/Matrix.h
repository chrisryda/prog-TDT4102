#pragma once
#include <iostream>

class Matrix {
private:
    int n_rows;
    int n_columns;
    double** matrix;
public:
    Matrix (int rows, int columns);
    explicit Matrix(int rows);
    Matrix (const Matrix &rhs);
    ~Matrix();
    int getRows() const;
    int getColumns() const;

    double get(int row, int col) const;
    void set(int row, int col, double value);
    double* operator[](int n);
    friend std::ostream& operator<<(std::ostream &os, const Matrix &m);
    Matrix& operator=(Matrix rhs);
};
