#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    // std::ifstream file("../../data/sample.pgm");
    // std::ifstream file("invalid_dimensions.pgm");
    // std::ifstream file("incomplete_pixels.pgm");
    std::ifstream file("too_many_pixels.pgm");

    if (!file.is_open()) {
        std::cout << "Failed to open file." << std::endl;
        return 1;
    }

    std::string magic;
    int width;
    int height;
    int maxValue;

    file >> magic;
    if (magic != "P2") {
        std::cout << "Unsupported PGM format." << std::endl;
        return 1;
    }

    if (!(file >> width >> height)) {
        std::cout << "Invalid image dimensions." << std::endl;
        return 1;
    }

    if (width <= 0 || height <= 0) {
        std::cout << "Image dimensions must be positive." << std::endl;
        return 1;
    }

    if (!(file >> maxValue)) {
        std::cout << "Invalid max value." << std::endl;
        return 1;
    }

    if (maxValue <= 0 || maxValue > 255) {
        std::cout << "Invalid max value." << std::endl;
        return 1;
    }

    std::vector<int> pixels;

    for (int i = 0; i < width * height; i++) {
        int value;

        if (!(file >> value)) {
            std::cout << "Incomplete pixel data." << std::endl;
            return 1;
        }

        if (value < 0 || value > maxValue) {
            std::cout << "Invalid pixel value." << std::endl;
            return 1;
        }

        pixels.push_back(value);
    }

    int extraValue;
    if (file >> extraValue) {
        std::cout << "Too many pixel values." << std::endl;
        return 1;
    }

    int minValue = *std::min_element(pixels.begin(), pixels.end());
    int maxPixelValue = *std::max_element(pixels.begin(), pixels.end());

    long long sum = 0;
    for (int pixel : pixels) {
        sum += pixel;
    }
    double mean = static_cast<double>(sum) / pixels.size();

    std::cout << "minValue: " << minValue << std::endl;
    std::cout << "maxValue: " << maxPixelValue << std::endl;
    std::cout << "mean: " << mean << std::endl;

    // std::vector<int> histogram(256, 0);

    // for (int pixel : pixels) {
    //     histogram[pixel]++;
    // }

    // std::ofstream outFile("histogram.csv");

    // if (!outFile) {
    //     std::cout << "Failed to create histogram.csv\n";
    //     return 1;
    // }

    // outFile << "pixel_value,count\n";

    // for (int i = 0; i < 256; i++) {
    //     outFile << i << "," << histogram[i] << "\n";
    // }


    return 0;
}