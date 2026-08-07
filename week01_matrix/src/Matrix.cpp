#include "Matrix.h"
#include <iostream>

Matrix::Matrix(int rowCount, int colCount) {
    rows = rowCount;
    cols = colCount;

    data = std::vector<std::vector<double>>(
        rows,
        std::vector<double>(cols, 0.0)
    );
}

void Matrix::set(int row, int col, double value) {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        throw std::out_of_range("Matrix index out of range");
    }

    data[row][col] = value;
}

double Matrix::get(int row, int col) const {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        throw std::out_of_range("Matrix index out of range");
    }

    return data[row][col];
}

int Matrix::getRows() const {
    return rows;
}

int Matrix::getCols() const {
    return cols;
}

void Matrix::print() const {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            std::cout << data[row][col] << " ";
        }
        std::cout << '\n';
    }
}

bool Matrix::hasSameSize(const Matrix& other) const {
    return (rows == other.rows) && (cols == other.cols);
}

Matrix Matrix::operator+(const Matrix& other) const {
    if (!hasSameSize(other)) {
        throw std::invalid_argument(
            "Matrices must have the same dimensions for addition."
        );
    }

    Matrix result(rows, cols);

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            result.data[row][col] =
                data[row][col] + other.data[row][col];
        }
    }

    return result;
}

Matrix Matrix::operator-(const Matrix& other) const {
    if (!hasSameSize(other)) {
        throw std::invalid_argument(
            "Matrices must have the same dimensions for subtraction."
        );
    }

    Matrix result(rows, cols);

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            result.data[row][col] =
                data[row][col] - other.data[row][col];
        }
    }

    return result;
}

Matrix Matrix::operator*(double scalar) const {
    Matrix result(rows, cols);

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            result.data[row][col] =
                data[row][col] * scalar;
        }
    }

    return result;
}

Matrix Matrix::transpose() const {
    Matrix result(cols, rows);

    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            result.data[col][row] =
                data[row][col];
        }
    }

    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (cols != other.rows) {
        throw std::invalid_argument(
            "Matrix dimensions are incompatible for multiplication."
        );
    }

    Matrix result(rows, other.cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < other.cols; j++) {
            for (int k = 0; k < cols; k++) {
                result.data[i][j] +=
                    data[i][k] * other.data[k][j];
            }
        }
    }

    return result;
}
