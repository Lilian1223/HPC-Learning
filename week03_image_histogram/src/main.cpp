#include "../include/ImageHistogram.h"

#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./image_histogram <pgm_file>" << std::endl;
        return 1;
    }

    ImageHistogram image;

    if (!image.loadPGM(argv[1])) {
        return 1;
    }

    image.computeHistogram();

    std::cout << "minValue: " << image.getMinPixel() << std::endl;
    std::cout << "maxValue: " << image.getMaxPixel() << std::endl;
    std::cout << "mean: " << image.getMeanPixel() << std::endl;

    if (!image.exportCSV("histogram.csv")) {
        return 1;
    }

    return 0;
}
