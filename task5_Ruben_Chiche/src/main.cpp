#include <iostream>
#include <fstream>
#include <map>
#include <List>
#include <string>
#include "Coordinate.h"

int main() {

    std::ifstream inputFile;
    inputFile.open("data.txt"); 

    if (!inputFile) {
        std::cout << "Error opening the file!" << std::endl;
        return 1;
    }

    std::map<std::string, Coordinate*> cityToLocation;
    std::map<Coordinate*, std::string> locationToCity;

    std::string coordinate, city;
    
    while (std::getline(inputFile, city) && std::getline(inputFile, coordinate))
    {
        cityToLocation[city] = new Coordinate(coordinate);
        locationToCity[new Coordinate(coordinate)] = city;
    }

    inputFile.close(); 

        
    double radius;
    size_t choice;
    
    std::cout << "Please enter selected city name (with line break after it):" << std::endl;
    std::getline(std::cin, city);

    auto it = cityToLocation.find(city);
    if (it == cityToLocation.end())
        std::cout << "ERROR: \"" << city << "\" isn't found in the city list. Please try again." << std::endl;

    std::cout << "Please enter the wanted radius :" << std::endl;
    std::cin >> radius;

    std::cout << "Please enter the wanted norm (0 – L2, Euclidean distance, 1 – Linf, Chebyshev distance, 2 – L1, Manhattan distance):" << std::endl;
    std::cin >> choice;
    

    return 0;

}