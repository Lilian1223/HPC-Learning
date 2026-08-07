#include <iostream>
#include <vector>

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

    void print() const{
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                std::cout << data[row][col] << " ";
            }
            std::cout << '\n';
        }
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
    
    return 0;
}
