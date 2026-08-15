cmake_minimum_required(VERSION 3.10)

project(CSVStatistics)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
    csv_stats
    src/main.cpp
    src/CSVStatistics.cpp
)

add_executable(
    csv_stats_tests
    tests/test_csv_statistics.cpp
    src/CSVStatistics.cpp
)

target_include_directories(
    csv_stats
    PRIVATE
    include
)

target_include_directories(
    csv_stats_tests
    PRIVATE
    include
)
