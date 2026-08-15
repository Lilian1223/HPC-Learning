#include "CSVStatistics.h"
#include <algorithm>
#include <cmath>

double CSVStatistics::mean(const std::vector<int>& scores) {
    int sum = 0;

    for (int score : scores) {
        sum += score;
    }

    return static_cast<double>(sum) / scores.size();
}

int CSVStatistics::min(const std::vector<int>& scores) {
    int minScore = scores[0];

    for (int score : scores) {
        minScore = std::min(minScore, score);
    }

    return minScore;
}

int CSVStatistics::max(const std::vector<int>& scores) {
    int maxScore = scores[0];

    for (int score : scores) {
        maxScore = std::max(maxScore, score);
    }

    return maxScore;
}

double CSVStatistics::median(std::vector<int> scores) {
    std::sort(scores.begin(), scores.end());

    if (scores.size() % 2 == 1) {
        return scores[scores.size() / 2];
    }

    return (
        scores[scores.size() / 2 - 1] +
        scores[scores.size() / 2]
    ) / 2.0;
}

double CSVStatistics::variance(const std::vector<int>& scores) {
    double avg = mean(scores);
    double varianceSum = 0.0;

    for (int score : scores) {
        double diff = score - avg;
        varianceSum += diff * diff;
    }

    return varianceSum / scores.size();
}

double CSVStatistics::standardDeviation(const std::vector<int>& scores) {
    return std::sqrt(variance(scores));
}
