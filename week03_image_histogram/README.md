# Week 3 - Image Histogram

This project reads a P2 PGM grayscale image, validates the input data, computes basic image statistics, builds a 256-bin histogram, and exports the histogram to a CSV file.

## Project Structure

```text
week03_image_histogram/
├── daily_progress/
│   ├── day1_pgm_reader/
│   ├── day2_pgm_parser/
│   ├── day3_histogram/
│   ├── day4_histogram_csv/
│   ├── day5_image_statistics/
│   ├── day6_file_validation/
│   └── day7_tests_readme/
├── data/
│   └── sample.pgm
├── include/
├── src/
├── tests/
└── README.md
```

## Features

- Read P2 PGM grayscale image files
- Parse image width, height, and maximum pixel value
- Validate the PGM format
- Validate image dimensions
- Validate maximum pixel value
- Validate individual pixel values
- Detect incomplete pixel data
- Detect extra pixel data
- Compute minimum pixel value
- Compute maximum pixel value
- Compute mean pixel value
- Build a 256-bin histogram
- Export histogram data to CSV
- Accept an input PGM file from the command line

## Sample Input

Example `sample.pgm`:

```text
P2
4 3
255
0 50 100 150
200 250 100 50
0 25 75 125
```

## Compile

From a daily project directory such as:

```text
daily_progress/day7_tests_readme
```

compile with:

```bash
g++ main.cpp -o histogram_test
```

## Run

The program accepts a PGM file path as a command-line argument.

Example:

```bash
./histogram_test sample.pgm
```

## Expected Output

For the sample image:

```text
minValue: 0
maxValue: 250
mean: 93.75
```

## Histogram Output

The program generates a CSV file:

```text
histogram.csv
```

The CSV contains two columns:

```text
pixel_value,count
```

Example:

```text
pixel_value,count
0,2
1,0
2,0
...
25,1
...
50,2
...
100,2
...
250,1
...
255,0
```

## Validation Tests

The Day 7 test directory contains several PGM files for testing invalid input.

### Invalid Dimensions

`invalid_dimensions.pgm`

Example:

```text
P2
0 3
255
0 50 100
```

Expected error:

```text
Image dimensions must be positive.
```

### Incomplete Pixel Data

`incomplete_pixels.pgm`

Example:

```text
P2
2 2
255
10 20 30
```

Expected error:

```text
Incomplete pixel data.
```

### Too Many Pixel Values

`too_many_pixels.pgm`

Example:

```text
P2
2 2
255
10 20 30 40 50
```

Expected error:

```text
Too many pixel values.
```

## Daily Progress

### Day 1 - PGM Reader
- Open a P2 PGM file
- Read image metadata
- Read pixel values

### Day 2 - PGM Parser
- Validate pixel input
- Detect incomplete pixel data
- Check pixel value ranges

### Day 3 - Histogram
- Build a 256-bin histogram
- Count the frequency of each grayscale value

### Day 4 - Histogram CSV Export
- Export histogram data to `histogram.csv`

### Day 5 - Image Statistics
- Compute minimum pixel value
- Compute maximum pixel value
- Compute mean pixel value

### Day 6 - File Validation
- Validate image dimensions
- Validate maximum pixel value
- Detect extra pixel values
- Test invalid PGM files

### Day 7 - Testing and Documentation
- Add valid and invalid sample files
- Add command-line file input
- Test multiple PGM files
- Document the Week 3 project

## Concepts Practiced

- C++ file I/O
- `std::vector`
- PGM image parsing
- Input validation
- Histograms
- Basic image statistics
- CSV output
- Command-line arguments
- Testing
- Project documentation
