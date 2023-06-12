#include <iostream>
#include <fstream>
#include <map>
#include <string>

int main() {

    std::ifstream inputFile;
    inputFile.open("data.txt"); 

    if (!inputFile) {
        std::cout << "Error opening the file!" << std::endl;
        return 1;
    }

    std::map<std::string, std::string> cityToLocation;
    std::map<std::string, std::string> locationToCity;

    std::string key, value;

    while (std::getline(inputFile, key) && std::getline(inputFile, value)) {
        cityToLocation[key] = value;
        locationToCity[value] = key;
    }

    inputFile.close(); 

    /*
    for (const auto& pair : cityToLocation) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }
    */


    return 0;

}