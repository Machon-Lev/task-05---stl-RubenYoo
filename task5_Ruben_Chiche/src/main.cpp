#include <iostream>
#include <fstream>
#include <map>
#include <List>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>
#include "Coordinate.h"
#include "Distance.h"

std::string PATH = "data.txt";

void readData(std::string, std::map<std::string, Coordinate>&);

int main() { 

    std::map<std::string, Coordinate> cityToLocation;

    // try reading the data from the data.txt file
    try
    {
        readData(PATH, cityToLocation);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what();
        return 1;
    }
    
    // mapping a number to a distance function
    std::map<size_t, double (*)(Coordinate, Coordinate)> choiceToFunc;
    choiceToFunc[0] = Distance::euclidean;
    choiceToFunc[1] = Distance::chebyshev;
    choiceToFunc[2] = Distance::manhattan;

    double radius;
    size_t choice;
    Coordinate targetCoordinate;
    std::string city;
    
    do
    {
        // read city name

        std::cout << "Please enter selected city name (with line break after it):" << std::endl;

        auto it = cityToLocation.end();

        while (it == cityToLocation.end())
        {
            std::getline(std::cin, city);
            it = cityToLocation.find(city);
            if (city == "0")
            {
                std::cout << "Bye";
                return 0;
            }
            if (it == cityToLocation.end())
                std::cout << "ERROR: \"" << city << "\" isn't found in the city list. Please try again." << std::endl;
            else
                targetCoordinate = it->second;
        }


        // read radius
        std::cout << "Please enter the wanted radius :" << std::endl;
        std::cin >> radius;


        // read distance choice calculation
        std::cout << "Please enter the wanted norm (0 - L2, Euclidean distance, 1 - Linf, Chebyshev distance, 2 - L1, Manhattan distance):" << std::endl;
        std::cin >> choice;


        std::map<std::string, Coordinate> citiesWithinRadius;


        // checking for cities within the radius
        std::copy_if(cityToLocation.begin(), cityToLocation.end(), std::inserter(citiesWithinRadius, citiesWithinRadius.end()),
            [&](const auto& pair) {
                std::string cityName = pair.first;
                double distance = choiceToFunc[choice](pair.second, targetCoordinate);
                return distance <= radius && cityName != city;
            });


        // count cities in the north
        int countCitiesNorth = std::count_if(cityToLocation.begin(), cityToLocation.end(),
            [&](const auto& pair) {
                return pair.second.getY() < targetCoordinate.getY();
            });

        // parse result of cities within the radius into a vector
        std::vector<std::string> cities;
        std::transform(citiesWithinRadius.begin(), citiesWithinRadius.end(), std::back_inserter(cities),
            [](const auto& pair) {
                return pair.first;
            });

        // print all the informations
        std::cout << "Search result:" << std::endl;
        std::cout << citiesWithinRadius.size() << " city/cities found in the given radius." << std::endl;
        std::cout << countCitiesNorth << " cities are to the north of the selected city." << std::endl;
        std::cout << "City list:" << std::endl;
        std::copy(cities.begin(), cities.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
        std::cin.ignore();

    } while (true);
    
    
    return 0;
}

// read data from file
void readData(std::string path, std::map<std::string, Coordinate>& container)
{
    std::ifstream inputFile;
    std::string coordinate, city, line;
    double x, y;

    inputFile.open(path);
    if (!inputFile)
        throw std::runtime_error("Could not open file");

    while (std::getline(inputFile, city))
    {
        if (std::getline(inputFile, line))
        {
            std::istringstream iss(line);
            if (iss >> x >> std::ws && iss.peek() == '-' && iss.ignore() && iss >> y)
            {
                Coordinate coordinate(x, y);
                container.insert({ city, coordinate });
            }
            else
                throw std::runtime_error("Location format is wrong");
        }
        else
            throw std::runtime_error("Location of city is missing");
    }
    if (container.empty())
        throw std::runtime_error("The file is empty");

    inputFile.close();
}

