cmake_minimum_required(VERSION 3.10)

project(ImageHistogram)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(image_histogram
    src/main.cpp
    src/ImageHistogram.cpp
)

target_include_directories(image_histogram PRIVATE include)

add_executable(image_histogram_tests
    tests/test_image_histogram.cpp
    src/ImageHistogram.cpp
)

target_include_directories(image_histogram_tests PRIVATE include)
