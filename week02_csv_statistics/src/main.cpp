#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "CSVStatistics.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./csv_stats <csv_file>" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]);

    if (!file.is_open()) {
        std::cout << "Failed to open the file." << std::endl;
        return 1;
    }

    std::vector<int> scores;
    std::string line;

    // Skip header
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);

        std::string name;
        std::string score;

        std::getline(ss, name, ',');
        std::getline(ss, score, ',');

        if (score.empty()) {
            std::cout << "Invalid score for " << name << std::endl;
            continue;
        }

        try {
            int scoreValue = std::stoi(score);
            scores.push_back(scoreValue);
        }
        catch (const std::invalid_argument& e) {
            std::cout << "Invalid score for " << name << std::endl;
            continue;
        }
        catch (const std::out_of_range& e) {
            std::cout << "Score out of range for " << name << std::endl;
            continue;
        }
    }

    if (scores.empty()) {
        std::cout << "No valid scores." << std::endl;
        return 1;
    }

    std::cout << "Mean: "
              << CSVStatistics::mean(scores)
              << std::endl;

    std::cout << "Min: "
              << CSVStatistics::min(scores)
              << std::endl;

    std::cout << "Max: "
              << CSVStatistics::max(scores)
              << std::endl;

    std::cout << "Median: "
              << CSVStatistics::median(scores)
              << std::endl;

    std::cout << "Variance: "
              << CSVStatistics::variance(scores)
              << std::endl;

    std::cout << "Standard Deviation: "
              << CSVStatistics::standardDeviation(scores)
              << std::endl;

    return 0;
}
