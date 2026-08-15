#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>

int main(int argc, char* argv[]){
    if (argc < 2) {
        std::cout << "Usage: ./csv_stats <csv_file>" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]);
    if(!file.is_open()){
        std::cout << "Failed to open the file." << std::endl;
        return 1;
    }

    std::string line;
    std::getline(file, line); // Skip the header line

    std::vector<int> scores;

    while(std::getline(file, line)){
        std::stringstream ss(line);

        std::string name;
        std::string score;

        std::getline(ss, name, ',');
        std::getline(ss, score, ',');

        if (score.empty()) {
            std::cout << "Invalid score for " << name << '\n';
            continue;
        }

        try {
            int scoreValue = std::stoi(score);
            scores.push_back(scoreValue);
        }
        catch (const std::invalid_argument& e) {
            std::cout << "Invalid score for " << name << '\n';
            continue;
        }
        catch (const std::out_of_range& e) {
            std::cout << "Score out of range for " << name << '\n';
            continue;
        }

    }

    for (int score: scores) {
        std::cout << score << std::endl;
    }

    if (scores.empty()) {
        std::cout << "No valid scores.\n";
        return 0;
    }

    int minScore = scores[0];
    int maxScore = scores[0];
    int sum = 0;
    for(int score: scores){
        minScore = std::min(minScore, score);
        maxScore = std::max(maxScore, score);
        sum += score;
    }
    double mean = static_cast<double>(sum) / scores.size();

    std::cout << "Mean: " << mean << std::endl;
    std::cout << "Min: " << minScore << std::endl;
    std::cout << "Max: " << maxScore << std::endl;

    std::sort(scores.begin(), scores.end());
    double median;
    if(scores.size() % 2 == 1){
        median = scores[scores.size() / 2];
    } else {
        median = (scores[scores.size() / 2 - 1] + scores[scores.size() / 2]) / 2.0;
    }
    std::cout << "Median: " << median << std::endl;

    double varianceSum = 0.0;
    for(int score: scores){
        double diff = score - mean;
        varianceSum += diff * diff;
    }
    double variance = varianceSum / scores.size();
    std::cout << "Variance: " << variance << std::endl;

    double standardDeviation = std::sqrt(variance);
    std::cout << "Standard Deviation: " << standardDeviation << std::endl;

    //file.close();

    return 0;
}
