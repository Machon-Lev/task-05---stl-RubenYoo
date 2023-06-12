#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include "Coordinate.h"

int main() {

    std::ifstream inputFile;
    inputFile.open("data.txt"); 

    if (!inputFile) {
        std::cout << "Error opening the file!" << std::endl;
        return 1;
    }

    std::map<std::string, Coordinate> cityToLocation;
    std::map<Coordinate, std::string> locationToCity;

    std::string coo, city;

    while (std::getline(inputFile, coo) && std::getline(inputFile, city)) {
        Coordinate coordinate(coo);
        cityToLocation[city] = coordinate;
        locationToCity[coordinate] = city;
    }

    inputFile.close(); 

    /*
    for (const auto& pair : cityToLocation) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }
    */
    


    return 0;

}