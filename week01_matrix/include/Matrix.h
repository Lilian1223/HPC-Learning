#pragma once

#include <vector>
#include <stdexcept>

class Matrix {
private:
    int rows;
    int cols;
    std::vector<std::vector<double>> data;

public:
    Matrix(int rowCount, int colCount);

    void set(int row, int col, double value);
    double get(int row, int col) const;

    int getRows() const;
    int getCols() const;

    void print() const;

    bool hasSameSize(const Matrix& other) const;

    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(double scalar) const;
    Matrix operator*(const Matrix& other) const;

    Matrix transpose() const;
};
