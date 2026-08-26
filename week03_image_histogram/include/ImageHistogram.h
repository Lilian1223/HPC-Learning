#ifndef IMAGEHISTOGRAM_H
#define IMAGEHISTOGRAM_H

#include <string>
#include <vector>

class ImageHistogram {
private:
    int width;
    int height;
    int maxValue;
    std::vector<int> pixels;
    std::vector<int> histogram;

public:
    ImageHistogram();

    bool loadPGM(const std::string& filename);

    void computeHistogram();

    int getMinPixel() const;
    int getMaxPixel() const;
    double getMeanPixel() const;

    const std::vector<int>& getHistogram() const;

    bool exportCSV(const std::string& filename) const;
};

#endif
