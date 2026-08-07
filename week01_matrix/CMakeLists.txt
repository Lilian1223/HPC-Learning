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
