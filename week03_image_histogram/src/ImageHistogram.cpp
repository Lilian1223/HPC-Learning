#include "../include/ImageHistogram.h"

#include <algorithm>
#include <fstream>
#include <iostream>

ImageHistogram::ImageHistogram()
    : width(0),
      height(0),
      maxValue(0),
      histogram(256, 0) {
}

bool ImageHistogram::loadPGM(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cout << "Failed to open file." << std::endl;
        return false;
    }

    std::string magic;

    file >> magic;

    if (magic != "P2") {
        std::cout << "Unsupported PGM format." << std::endl;
        return false;
    }

    if (!(file >> width >> height)) {
        std::cout << "Invalid image dimensions." << std::endl;
        return false;
    }

    if (width <= 0 || height <= 0) {
        std::cout << "Image dimensions must be positive." << std::endl;
        return false;
    }

    if (!(file >> maxValue)) {
        std::cout << "Invalid max value." << std::endl;
        return false;
    }

    if (maxValue <= 0 || maxValue > 255) {
        std::cout << "Invalid max value." << std::endl;
        return false;
    }

    pixels.clear();

    for (int i = 0; i < width * height; i++) {
        int value;

        if (!(file >> value)) {
            std::cout << "Incomplete pixel data." << std::endl;
            return false;
        }

        if (value < 0 || value > maxValue) {
            std::cout << "Invalid pixel value." << std::endl;
            return false;
        }

        pixels.push_back(value);
    }

    int extraValue;

    if (file >> extraValue) {
        std::cout << "Too many pixel values." << std::endl;
        return false;
    }

    return true;
}

void ImageHistogram::computeHistogram() {
    std::fill(histogram.begin(), histogram.end(), 0);

    for (int pixel : pixels) {
        histogram[pixel]++;
    }
}

int ImageHistogram::getMinPixel() const {
    return *std::min_element(pixels.begin(), pixels.end());
}

int ImageHistogram::getMaxPixel() const {
    return *std::max_element(pixels.begin(), pixels.end());
}

double ImageHistogram::getMeanPixel() const {
    long long sum = 0;

    for (int pixel : pixels) {
        sum += pixel;
    }

    return static_cast<double>(sum) / pixels.size();
}

const std::vector<int>& ImageHistogram::getHistogram() const {
    return histogram;
}

bool ImageHistogram::exportCSV(const std::string& filename) const {
    std::ofstream outFile(filename);

    if (!outFile) {
        std::cout << "Failed to create CSV file." << std::endl;
        return false;
    }

    outFile << "pixel_value,count\n";

    for (int i = 0; i < histogram.size(); i++) {
        outFile << i << "," << histogram[i] << "\n";
    }

    return true;
}
