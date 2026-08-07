#include "Matrix.h"
#include <iostream>

int main() {

    std::cout << "===== Test 1: set / get =====\n";
    {
        Matrix m(2, 2);

        m.set(0, 0, 10);
        m.set(1, 1, 20);

        std::cout << m.get(0, 0) << '\n';
        std::cout << m.get(1, 1) << '\n';

        // Expected:
        // 10
        // 20
    }


    std::cout << "\n===== Test 2: set out of range =====\n";
    {
        try {
            Matrix m(2, 2);

            m.set(5, 0, 10);
        }
        catch (const std::out_of_range& e) {
            std::cout << e.what() << '\n';
        }

        // Expected:
        // Matrix index out of range
    }


    std::cout << "\n===== Test 3: get out of range =====\n";
    {
        try {
            Matrix m(2, 2);

            std::cout << m.get(0, 5) << '\n';
        }
        catch (const std::out_of_range& e) {
            std::cout << e.what() << '\n';
        }

        // Expected:
        // Matrix index out of range
    }


    std::cout << "\n===== Test 4: matrix addition =====\n";
    {
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

        Matrix result = a + b;

        result.print();

        // Expected:
        // 6 8
        // 10 12
    }


    std::cout << "\n===== Test 5: matrix subtraction =====\n";
    {
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

        Matrix result = a - b;

        result.print();

        // Expected:
        // -4 -4
        // -4 -4
    }


    std::cout << "\n===== Test 6: scalar multiplication =====\n";
    {
        Matrix a(2, 2);

        a.set(0, 0, 1);
        a.set(0, 1, 2);
        a.set(1, 0, 3);
        a.set(1, 1, 4);

        Matrix result = a * 3;

        result.print();

        // Expected:
        // 3 6
        // 9 12
    }


    std::cout << "\n===== Test 7: transpose =====\n";
    {
        Matrix a(2, 3);

        a.set(0, 0, 1);
        a.set(0, 1, 2);
        a.set(0, 2, 3);

        a.set(1, 0, 4);
        a.set(1, 1, 5);
        a.set(1, 2, 6);

        Matrix result = a.transpose();

        result.print();

        // Expected:
        // 1 4
        // 2 5
        // 3 6
    }


    std::cout << "\n===== Test 8: matrix multiplication =====\n";
    {
        Matrix a(2, 3);
        Matrix b(3, 2);

        a.set(0, 0, 1);
        a.set(0, 1, 2);
        a.set(0, 2, 3);

        a.set(1, 0, 4);
        a.set(1, 1, 5);
        a.set(1, 2, 6);

        b.set(0, 0, 5);
        b.set(0, 1, 6);

        b.set(1, 0, 7);
        b.set(1, 1, 8);

        b.set(2, 0, 9);
        b.set(2, 1, 10);

        Matrix result = a * b;

        result.print();

        // Expected:
        // 46 52
        // 109 124
    }


    std::cout << "\n===== Test 9: incompatible matrix multiplication =====\n";
    {
        try {
            Matrix a(2, 2);
            Matrix b(3, 2);

            Matrix result = a * b;

            result.print();
        }
        catch (const std::invalid_argument& e) {
            std::cout << e.what() << '\n';
        }

        // Expected:
        // Matrix dimensions are incompatible for multiplication.
    }


    std::cout << "\n===== All tests finished =====\n";

    return 0;
}
