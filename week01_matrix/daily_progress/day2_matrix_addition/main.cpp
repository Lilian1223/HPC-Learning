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
};

int main(){
    Matrix matrix(2, 3);

    matrix.set(0, 0, 1);
    matrix.set(0, 1, 2);
    matrix.set(0, 2, 3);
    matrix.set(1, 0, 4);
    matrix.set(1, 1, 5);
    matrix.set(1, 2, 6);

    matrix.print();

    std::cout << "Element at (1, 2): "
              << matrix.get(1, 2) << '\n';

    std::cout << matrix.getRows() << '\n';
    std::cout << matrix.getCols() << '\n';

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

    Matrix result = a.add(b);
    
    std::cout << "Matrix A:\n";
    a.print();
    std::cout << "Matrix B:\n";
    b.print();
    std::cout << "A + B:\n";
    result.print();

    return 0;
}
