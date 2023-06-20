#include "Coordinate.h"
#include <sstream>

// constructor that parse string coordinate, to Coordinate object
Coordinate::Coordinate(std::string coordinate)
{

    std::istringstream iss(coordinate);
    double firstValue, secondValue;
    
    if (iss >> firstValue) {
        char separator;
        if (iss.ignore() && iss >> separator && separator == '-' && iss.ignore() && iss >> secondValue) {
            _myCoordinate.first = firstValue;
            _myCoordinate.second = secondValue;
        }
        else {
            throw "Failed to extract the separator and the second value from the coordinates string.";
        }
    }
    else {
        throw "Failed to extract the first value from the coordinates string.";
    }

}

// constructor
Coordinate::Coordinate(double x, double y)
{
	_myCoordinate.first = x;
	_myCoordinate.second = y;
}

// get X value
double Coordinate::getX() const
{
	return _myCoordinate.first;
}

// get Y value
double Coordinate::getY() const
{
	return _myCoordinate.second;
}