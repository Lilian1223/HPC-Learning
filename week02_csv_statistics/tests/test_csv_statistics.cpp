#include <iostream>
#include <vector>
#include <cmath>
#include "CSVStatistics.h"

bool nearlyEqual(double a, double b, double epsilon = 1e-6) {
    return std::abs(a - b) < epsilon;
}

int main() {
    std::vector<int> scores = {80, 90, 100};

    int passed = 0;
    int total = 6;

    if (nearlyEqual(CSVStatistics::mean(scores), 90.0)) {
        std::cout << "PASS: mean" << std::endl;
        passed++;
    } else {
        std::cout << "FAIL: mean" << std::endl;
    }

    if (CSVStatistics::min(scores) == 80) {
        std::cout << "PASS: min" << std::endl;
        passed++;
    } else {
        std::cout << "FAIL: min" << std::endl;
    }

    if (CSVStatistics::max(scores) == 100) {
        std::cout << "PASS: max" << std::endl;
        passed++;
    } else {
        std::cout << "FAIL: max" << std::endl;
    }

    if (nearlyEqual(CSVStatistics::median(scores), 90.0)) {
        std::cout << "PASS: median" << std::endl;
        passed++;
    } else {
        std::cout << "FAIL: median" << std::endl;
    }

    if (nearlyEqual(CSVStatistics::variance(scores), 66.6666667)) {
        std::cout << "PASS: variance" << std::endl;
        passed++;
    } else {
        std::cout << "FAIL: variance" << std::endl;
    }

    if (nearlyEqual(CSVStatistics::standardDeviation(scores), 8.1649658)) {
        std::cout << "PASS: standard deviation" << std::endl;
        passed++;
    } else {
        std::cout << "FAIL: standard deviation" << std::endl;
    }

    std::cout << passed << "/" << total << " tests passed." << std::endl;

    return passed == total ? 0 : 1;
}
