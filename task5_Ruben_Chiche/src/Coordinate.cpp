#include "Coordinate.h"
#include <sstream>

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