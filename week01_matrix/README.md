# Week 1 Matrix Project

A simple C++ matrix library created as part of my HPC learning journey.

This project is my Week 1 practice project for learning C++ fundamentals and preparing for future High Performance Computing (HPC) work. The main goal is to build a basic `Matrix` class while practicing object-oriented programming, operator overloading, exception handling, testing, project organization, and CMake.

## Features

The `Matrix` class currently supports:

- Matrix creation
- Setting matrix elements with `set()`
- Reading matrix elements with `get()`
- Row and column queries with `getRows()` and `getCols()`
- Bounds checking with `std::out_of_range`
- Matrix addition using `operator+`
- Matrix subtraction using `operator-`
- Scalar multiplication using `operator*`
- Matrix multiplication using `operator*`
- Matrix transpose
- Matrix dimension checking
- Exception handling for invalid matrix operations
- Basic test cases
- CMake build configuration

## Project Structure

```text
week01_matrix/
├── include/
│   └── Matrix.h
├── src/
│   └── Matrix.cpp
├── tests/
│   └── test_matrix.cpp
├── CMakeLists.txt
└── README.md
```

### File Description

- `include/Matrix.h`
  - Contains the declaration of the `Matrix` class.

- `src/Matrix.cpp`
  - Contains the implementation of the `Matrix` class.

- `tests/test_matrix.cpp`
  - Contains test cases for matrix operations and error handling.

- `CMakeLists.txt`
  - Defines how the project should be built using CMake.

- `README.md`
  - Documents the project, features, build instructions, and learning outcomes.

## Matrix Class

The matrix stores its values using:

```cpp
std::vector<std::vector<double>>
```

The class keeps the matrix dimensions and data private:

```cpp
private:
    int rows;
    int cols;
    std::vector<std::vector<double>> data;
```

Public member functions are used to access and modify the matrix safely.

## Basic Usage

Create a matrix:

```cpp
Matrix a(2, 2);
```

Set values:

```cpp
a.set(0, 0, 1);
a.set(0, 1, 2);
a.set(1, 0, 3);
a.set(1, 1, 4);
```

Read a value:

```cpp
double value = a.get(0, 0);
```

Print a matrix:

```cpp
a.print();
```

## Matrix Addition

Matrix addition is implemented using `operator+`.

Example:

```cpp
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
```

Expected output:

```text
6 8
10 12
```

Both matrices must have the same dimensions.

## Matrix Subtraction

Matrix subtraction is implemented using `operator-`.

Example:

```cpp
Matrix result = a - b;
```

For:

```text
A =
1 2
3 4

B =
5 6
7 8
```

The result is:

```text
-4 -4
-4 -4
```

Both matrices must have the same dimensions.

## Scalar Multiplication

Scalar multiplication is implemented using `operator*`.

Example:

```cpp
Matrix result = a * 3;
```

For:

```text
A =
1 2
3 4
```

The result is:

```text
3 6
9 12
```

## Matrix Transpose

The `transpose()` function swaps the rows and columns of a matrix.

Example:

```cpp
Matrix result = a.transpose();
```

For:

```text
1 2 3
4 5 6
```

The transpose is:

```text
1 4
2 5
3 6
```

## Matrix Multiplication

Matrix multiplication is implemented using `operator*`.

For matrix multiplication:

```text
A = m × n
B = n × p
```

the result will have dimensions:

```text
m × p
```

The number of columns in the first matrix must equal the number of rows in the second matrix.

Example:

```cpp
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
```

Expected output:

```text
46 52
109 124
```

## Error Handling

### Index Bounds Checking

The `set()` and `get()` functions check whether the requested index is inside the matrix.

Example:

```cpp
Matrix m(2, 2);

m.set(5, 0, 10);
```

This throws:

```text
Matrix index out of range
```

using:

```cpp
std::out_of_range
```

### Invalid Matrix Multiplication

If two matrices have incompatible dimensions:

```cpp
Matrix a(2, 2);
Matrix b(3, 2);

Matrix result = a * b;
```

the program throws:

```text
Matrix dimensions are incompatible for multiplication.
```

using:

```cpp
std::invalid_argument
```

## Tests

The project currently contains nine basic tests:

1. `set()` and `get()`
2. `set()` out-of-range checking
3. `get()` out-of-range checking
4. Matrix addition
5. Matrix subtraction
6. Scalar multiplication
7. Matrix transpose
8. Matrix multiplication
9. Invalid matrix multiplication dimensions

The tests are located in:

```text
tests/test_matrix.cpp
```

## Building the Project

This project uses CMake.

### Requirements

- C++17-compatible compiler
- CMake 3.10 or newer

Examples of compatible compilers include:

- GCC / G++
- Clang
- MSVC

## Build with CMake

From the `week01_matrix` directory:

```powershell
cmake -S . -B build
```

This tells CMake:

- `-S .` — use the current directory as the source directory
- `-B build` — place generated build files inside the `build` directory

Compile the project:

```powershell
cmake --build build
```

On Windows with the Visual Studio generator, the test executable is typically generated at:

```text
build/Debug/matrix_tests.exe
```

Run the tests:

```powershell
.\build\Debug\matrix_tests.exe
```

## CMake Configuration

The project uses the following basic CMake configuration:

```cmake
cmake_minimum_required(VERSION 3.10)

project(MatrixProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
    matrix_tests
    src/Matrix.cpp
    tests/test_matrix.cpp
)

target_include_directories(
    matrix_tests
    PRIVATE
    include
)
```

`target_include_directories()` allows the source files to write:

```cpp
#include "Matrix.h"
```

instead of using relative paths such as:

```cpp
#include "../include/Matrix.h"
```

## Build Directory

CMake automatically generates many temporary build files inside:

```text
build/
```

These files are generated automatically and should normally not be committed to Git.

Examples include:

```text
CMakeFiles/
Debug/
x64/
CMakeCache.txt
*.vcxproj
*.sln
```

The `build/` directory can be deleted and recreated at any time using:

```powershell
cmake -S . -B build
cmake --build build
```

## What I Learned

Through this project, I practiced:

### C++

- Classes and objects
- Private and public members
- Constructors
- Member functions
- `const` member functions
- Header and implementation file separation
- `std::vector`
- Nested loops
- References
- Operator overloading
- Exception handling
- Matrix operations

### Programming Concepts

- Bounds checking
- Input validation
- Matrix dimension rules
- Row-column matrix multiplication
- Code organization
- Testing

### Development Tools

- Git
- GitHub
- CMake
- Command-line compilation
- VS Code
- PowerShell

## Future Improvements

Possible future improvements include:

- Automated PASS / FAIL tests
- Unit testing framework integration
- Additional operator overloads
- Support for `scalar * Matrix`
- Equality comparison with `operator==`
- More matrix operations
- Performance benchmarking
- Contiguous matrix memory layout
- Cache-friendly optimizations
- OpenMP parallelization
- CUDA GPU implementation

## Learning Goal

This project is the first step in building stronger C++ fundamentals before moving into more advanced topics such as:

- Parallel programming
- High Performance Computing
- CPU optimization
- GPU programming
- CUDA
- Memory optimization
- Scientific computing
