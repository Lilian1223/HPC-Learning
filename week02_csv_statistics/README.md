# Week 2 CSV Statistics

A C++ project for reading score data from a CSV file and calculating basic statistics.

## Features

This project currently supports:

- Reading score data from a CSV file
- Skipping the CSV header
- Handling empty score values
- Handling invalid score values
- Handling out-of-range score values
- Calculating mean
- Calculating minimum
- Calculating maximum
- Calculating median
- Calculating variance
- Calculating standard deviation
- Accepting a CSV file path from the command line
- Building the project with CMake
- Running unit-style tests for the statistics functions

## Project Structure

```text
week02_csv_statistics/
├── daily_progress/
│   ├── day1_csv_reader/
│   ├── day2_numeric_rows/
│   ├── day3_invalid_input/
│   ├── day4_statistics/
│   ├── day5_median/
│   ├── day6_variance_stddev/
│   └── day7_cli_usage/
├── data/
│   └── sample.csv
├── include/
│   └── CSVStatistics.h
├── src/
│   ├── CSVStatistics.cpp
│   └── main.cpp
├── tests/
│   └── test_csv_statistics.cpp
├── CMakeLists.txt
└── README.md
```

## Build

From the `week02_csv_statistics` directory:

```bash
cmake -S . -B build
cmake --build build
```

After a successful build, the executables will be available in the `build` directory.

## Run

Run the program and provide the CSV file path as a command-line argument:

```bash
./build/csv_stats data/sample.csv
```

## Example Input

```csv
name,score
Alice,90
Bob,
Charlie,abc
David,85
```

## Example Output

```text
Invalid score for Bob
Invalid score for Charlie
Mean: 87.5
Min: 85
Max: 90
Median: 87.5
Variance: 6.25
Standard Deviation: 2.5
```

## Missing Command-Line Argument

If no CSV file is provided:

```bash
./build/csv_stats
```

The program prints:

```text
Usage: ./csv_stats <csv_file>
```

## Invalid File Path

If the specified file does not exist:

```bash
./build/csv_stats data/not_exist.csv
```

The program prints:

```text
Failed to open the file.
```

## Statistics

The program calculates the following statistics using all valid score values:

- **Mean**: average of all valid scores
- **Min**: smallest valid score
- **Max**: largest valid score
- **Median**: middle value after sorting the scores
- **Variance**: average squared distance from the mean
- **Standard Deviation**: square root of the variance

## Testing

The project includes tests for all implemented statistics functions.

Run the tests with:

```bash
./build/csv_stats_tests
```

Expected output:

```text
PASS: mean
PASS: min
PASS: max
PASS: median
PASS: variance
PASS: standard deviation
6/6 tests passed.
```

## Implementation Structure

The project separates declarations and implementations:

- `include/CSVStatistics.h`
  - Declares the `CSVStatistics` class and its statistics functions.

- `src/CSVStatistics.cpp`
  - Implements mean, min, max, median, variance, and standard deviation.

- `src/main.cpp`
  - Handles command-line arguments.
  - Reads and parses CSV input.
  - Handles invalid values.
  - Calls the `CSVStatistics` functions.

- `tests/test_csv_statistics.cpp`
  - Tests the statistics functions using known expected results.

## Notes

Invalid or empty score values are skipped and are not included in the statistical calculations.

The `daily_progress` directory contains the implementation from each learning day so that the development process can be reviewed step by step.

The formal project implementation is located in the `include`, `src`, and `tests` directories.
