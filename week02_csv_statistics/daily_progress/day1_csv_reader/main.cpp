#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main(){
    std::ifstream file("data/sample.csv");
    if(!file.is_open()){
        std::cout << "Failed to open the file." << std::endl;
        return 1;
    }

    std::string line;
    std::getline(file, line); // Skip the header line

    while(std::getline(file, line)){
        std::stringstream ss(line);

        std::string name;
        std::string score;

        std::getline(ss, name, ',');
        std::getline(ss, score, ',');

        int scoreValue = std::stoi(score);
        std::cout << name << ": " << scoreValue << std::endl;
    }
    // file.close();

    return 0;
}