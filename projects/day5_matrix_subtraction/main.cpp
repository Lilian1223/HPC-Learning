#include <iostream>
#include <vector>
#include <stdexcept>

class Matrix{
private:
    int rows;
    int cols;
    std::vector<std::vector<double>> data;

public:
    Matrix(int rowCount, int colCount){
        rows = rowCount;
        cols = colCount;

        data = std::vector<std::vector<double>>(
            rows,
            std::vector<double>(cols, 0.0)
        );
    }

    void set(int row, int col, double value){
        data[row][col] = value;
    }

    double get(int row, int col) const{
        return data[row][col];
    }

    int getRows() const{
        return rows;
    }

    int getCols() const{
        return cols;
    }

    void print() const{
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                std::cout << data[row][col] << " ";
            }
            std::cout << '\n';
        }
    }

    bool hasSameSize(const Matrix& other) const{
        return (rows == other.rows) && (cols == other.cols);
    }

    Matrix add(const Matrix& other) const{
        if(!hasSameSize(other)){
            throw std::invalid_argument(
                "Matrices must have the same dimensions for addition."
            );
        }

        Matrix result(rows, cols);

        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                result.data[row][col] = data[row][col] + other.data[row][col];
            }
        }
        return result;
    }

    Matrix multipliedByScalar(double scalar){
        Matrix result(rows, cols);

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                result.data[row][col] = data[row][col] * scalar;
            }
        }

        return result;
    }

    Matrix transpose(){
        Matrix result(cols, rows);

        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                result.data[col][row] = data[row][col];
            }
        }

        return result;
    }

    Matrix subtract(const Matrix& other) {
        if (!hasSameSize(other)) {
            throw std::runtime_error("Matrices must have the same size");
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
};

int main(){

    Matrix a(2, 2);
    Matrix b(2, 2);

    a.set(0, 0, 1);
    a.set(0, 1, 2);
    a.set(1, 0, 3);
    a.set(1, 1, 4);

    b.set(0, 0, 5);
    b.set(0, 1, 6);
    b.set(1, 0, 7);
    b.set(1, 1, 8);

    std::cout << "Matrix A subtract Matrix B :\n";
    Matrix result = a.subtract(b);
    result.print();

    return 0;
}
