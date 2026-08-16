#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    std::ifstream file("data/sample.pgm");

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

    file >> width >> height;
    file >> maxValue;

    std::vector<int> pixels;

    for (int i = 0; i < width * height; i++) {
        int value;
        file >> value;
        pixels.push_back(value);
    }

    std::cout << "Format: " << magic << std::endl;
    std::cout << "Width: " << width << std::endl;
    std::cout << "Height: " << height << std::endl;
    std::cout << "Max value: " << maxValue << std::endl;
    std::cout << "Pixels: " << pixels.size() << std::endl;

    std::cout << "Pixel values: ";
    for (int pixel : pixels) {
        std::cout << pixel << " ";
    }
    std::cout << std::endl;

    return 0;
}