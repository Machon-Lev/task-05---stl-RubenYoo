#include <iostream>
#include <fstream>
#include <map>
#include <List>
#include <string>
#include <algorithm>
#include "Coordinate.h"
#include "Distance.h"

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

    Distance dist;
 
    using pfunc = double (*)(Coordinate, Coordinate);
    std::map<size_t, pfunc> choiceToFunc;
    choiceToFunc[0] = &dist.euclidean;
    choiceToFunc[1] = &dist.chebyshev;
    choiceToFunc[2] = &dist.manhattan;

    double radius;
    size_t choice;
    Coordinate* targetCoordinate;
    
    std::cout << "Please enter selected city name (with line break after it):" << std::endl;
    std::getline(std::cin, city);

    auto it = cityToLocation.find(city);
    if (it == cityToLocation.end()) {
        std::cout << "ERROR: \"" << city << "\" isn't found in the city list. Please try again." << std::endl;
        return 1;
    } 
    else
        targetCoordinate = it->second;

    std::cout << "Please enter the wanted radius :" << std::endl;
    std::cin >> radius;

    std::cout << "Please enter the wanted norm (0 - L2, Euclidean distance, 1 - Linf, Chebyshev distance, 2 - L1, Manhattan distance):" << std::endl;
    std::cin >> choice;
    
    

    std::map<std::string, Coordinate*> citiesWithinRadius;

    std::copy_if(cityToLocation.begin(), cityToLocation.end(), std::inserter(citiesWithinRadius, citiesWithinRadius.end()),
        [&](const auto& pair) {
            std::string cityName = pair.first;
            double distance = choiceToFunc[choice](*pair.second, *targetCoordinate);
            return distance <= radius && cityName != city;
        });


    /*
    // Print the cities within the radius
    std::cout << "Cities within the radius from the target coordinate:" << std::endl;
    for (const auto& pair : citiesWithinRadius) {
        std::cout << pair.first << std::endl;
    }
    */

    return 0;

}