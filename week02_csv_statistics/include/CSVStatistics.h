#ifndef CSVSTATISTICS_H
#define CSVSTATISTICS_H

#include <vector>

class CSVStatistics {
public:
    static double mean(const std::vector<int>& scores);
    static int min(const std::vector<int>& scores);
    static int max(const std::vector<int>& scores);
    static double median(std::vector<int> scores);
    static double variance(const std::vector<int>& scores);
    static double standardDeviation(const std::vector<int>& scores);
};

#endif
