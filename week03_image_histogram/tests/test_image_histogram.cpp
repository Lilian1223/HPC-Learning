#include "../include/ImageHistogram.h"

#include <cmath>
#include <iostream>

bool nearlyEqual(double a, double b, double epsilon = 1e-9) {
    return std::abs(a - b) < epsilon;
}

int main() {
    ImageHistogram image;

    if (!image.loadPGM("data/sample.pgm")) {
        std::cout << "Test failed: could not load sample.pgm\n";
        return 1;
    }

    image.computeHistogram();

    if (image.getMinPixel() != 0) {
        std::cout << "Test failed: min pixel\n";
        return 1;
    }

    if (image.getMaxPixel() != 250) {
        std::cout << "Test failed: max pixel\n";
        return 1;
    }

    if (!nearlyEqual(image.getMeanPixel(), 93.75)) {
        std::cout << "Test failed: mean pixel\n";
        return 1;
    }

    const std::vector<int>& histogram = image.getHistogram();

    if (histogram[0] != 2) {
        std::cout << "Test failed: histogram[0]\n";
        return 1;
    }

    if (histogram[50] != 2) {
        std::cout << "Test failed: histogram[50]\n";
        return 1;
    }

    if (histogram[100] != 2) {
        std::cout << "Test failed: histogram[100]\n";
        return 1;
    }

    if (histogram[250] != 1) {
        std::cout << "Test failed: histogram[250]\n";
        return 1;
    }

    std::cout << "All tests passed!\n";

    return 0;
}
