#include <iostream>
#include <fstream>

int main() {
    std::string buff;
    std::ifstream cals("cals");
    int maxCals=0;
    int nMaxCals=0;
    int tMaxCals=0;
    int tempCals=0;
    while (std::getline(cals, buff)) {
        if (buff.length()==0) {
            if (tempCals > maxCals) {maxCals = tempCals;}
            else if (tempCals > nMaxCals) {nMaxCals=tempCals;}
            else if (tempCals > tMaxCals) {tMaxCals=tempCals;}
            tempCals=0;
            continue;
        }
        tempCals += std::stoi(buff);
    }
    std::cout << maxCals + nMaxCals + tMaxCals << std::endl;
}