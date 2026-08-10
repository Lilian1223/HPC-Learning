#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

int main(){
    std::ifstream file("data/sample.csv");
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
    //file.close();

    return 0;
}